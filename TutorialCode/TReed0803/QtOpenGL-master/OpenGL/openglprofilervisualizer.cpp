#include "openglprofilervisualizer.h"
#include "openglframeresults.h"

#include <cstdint>

#include <QColor>
#include <QMoveEvent>
#include <QPoint>
#include <QPointF>
#include <QRectF>
#include <QSize>
#include <QSizeF>
#include <QString>
#include <QToolTip>

#include <KColor>
#include <OpenGLDebugDraw>
#include <KInputManager>
#include <KRectF>
#include <KMacros>
#include <KMath>

/*******************************************************************************
 * OpenGLProfilerVisualizerPrivate
 ******************************************************************************/
class OpenGLProfilerVisualizerPrivate
{
public:
  OpenGLProfilerVisualizerPrivate();

  bool m_dirty;
  QPoint m_windowPosition;
  QPoint m_topLeftBorder, m_bottomRightBorder;
  QPointF m_topLeft, m_topLeftOffset, m_bottomRight, m_bottomRightOffset;
  QSizeF m_surfaceArea;
  QRectF m_surfaceRect;
  QSize m_windowSize;
  QString m_currToolTip;
  OpenGLFrameResults m_lastResultSet;
};

OpenGLProfilerVisualizerPrivate::OpenGLProfilerVisualizerPrivate() :
  m_dirty(true)
{
  // Intentionally Empty
}

/*******************************************************************************
 * OpenGLProfilerVisualizer
 ******************************************************************************/


OpenGLProfilerVisualizer::OpenGLProfilerVisualizer(QObject *parent) :
  QObject(parent), m_private(new OpenGLProfilerVisualizerPrivate)
{
  setBorder(10, 10, 0, 10);
  setOffset(0.0f, 0.0f, 0.9f, 0.0f);
}

OpenGLProfilerVisualizer::~OpenGLProfilerVisualizer()
{
  delete m_private;
}


void OpenGLProfilerVisualizer::resizeGL(int width, int height)
{
  P(OpenGLProfilerVisualizerPrivate);
  p.m_windowSize.setWidth(width);
  p.m_windowSize.setHeight(height);
  p.m_dirty = true;
}

void OpenGLProfilerVisualizer::paintGL()
{
  P(OpenGLProfilerVisualizerPrivate);

  // Recalculate Profiler information if needed
  if (p.m_dirty)
  {
    p.m_dirty = false;
    p.m_topLeft.setX(p.m_topLeftOffset.x() + float(p.m_topLeftBorder.x()) / p.m_windowSize.width());
    p.m_topLeft.setY(p.m_topLeftOffset.y() + float(p.m_topLeftBorder.y()) / p.m_windowSize.height());
    p.m_bottomRight.setX(1.0f - (p.m_bottomRightOffset.x() + float(p.m_bottomRightBorder.x()) / p.m_windowSize.width()));
    p.m_bottomRight.setY(1.0f - (p.m_bottomRightOffset.y() + float(p.m_bottomRightBorder.y()) / p.m_windowSize.height()));
    p.m_surfaceArea.setWidth(p.m_bottomRight.x() - p.m_topLeft.x());
    p.m_surfaceArea.setHeight(p.m_bottomRight.y() - p.m_topLeft.y());
    p.m_surfaceRect.setTopLeft(p.m_topLeft);
    p.m_surfaceRect.setSize(p.m_surfaceArea);
  }

  // Draw Background
  OpenGLDebugDraw::Screen::drawRect(p.m_surfaceRect, Qt::white);

  // Find our step
  float markerYStep = p.m_surfaceArea.height() / p.m_lastResultSet.maxDepth();
  uint64_t frameBegin = p.m_lastResultSet.startTime();
  uint64_t frameEnd = p.m_lastResultSet.endTime();
  float frameTime = float(frameEnd - frameBegin);

  // Find mouse pos
  QPoint absoluteMousePos = KInputManager::mousePosition();
  QPoint relativeMousePos = absoluteMousePos - p.m_windowPosition;
  QPointF normalizedRelativeMousePos(
    float(relativeMousePos.x()) / p.m_windowSize.width(),
    float(relativeMousePos.y()) / p.m_windowSize.height()
  );

  // Draw each marker
  QColor markerColor;
  QRectF normalizedMarkerRect;
  float normalizedMarkerStart, normalizedMarkerEnd;
  const OpenGLMarkerResults &gpuResults = p.m_lastResultSet.gpuResults();
  for (size_t i = 0; i < gpuResults.size(); ++i)
  {
    const OpenGLMarkerResult &result = gpuResults[i];

    // Calculate normalized marker area
    normalizedMarkerStart = (result.startTime() - frameBegin) / frameTime;
    normalizedMarkerEnd = (result.endTime() - frameBegin) / frameTime;
    normalizedMarkerRect.setLeft(p.m_topLeft.x() + p.m_surfaceArea.width() * normalizedMarkerStart);
    normalizedMarkerRect.setRight(p.m_topLeft.x() + p.m_surfaceArea.width() * normalizedMarkerEnd);
    normalizedMarkerRect.setTop(p.m_topLeft.y() + markerYStep * result.depth());
    normalizedMarkerRect.setBottom(p.m_topLeft.y() + markerYStep * (result.depth() + 1));

    // Display debug information if selected
    if (normalizedMarkerRect.contains(normalizedRelativeMousePos))
    {
      markerColor = Qt::yellow;
      if (p.m_currToolTip != result.name())
      {
        p.m_currToolTip = result.name();
        QString str = result.name() + " " + QString::number(result.elapsedMilliseconds());
        QToolTip::showText(QCursor::pos(), str);
      }
    }
    else
    {
      markerColor = Karma::colorShift(Qt::red, float(i) / gpuResults.size());
      if (p.m_currToolTip == result.name())
      {
        p.m_currToolTip.clear();
        QToolTip::hideText();
      }
    }

    OpenGLDebugDraw::Screen::drawRect(normalizedMarkerRect, markerColor);
  }
}

void OpenGLProfilerVisualizer::moveEvent(const QMoveEvent *ev)
{
  P(OpenGLProfilerVisualizerPrivate);
  p.m_windowPosition = ev->pos();
}

void OpenGLProfilerVisualizer::frameResultsAvailable(const OpenGLFrameResults &results)
{
  P(OpenGLProfilerVisualizerPrivate);
  p.m_lastResultSet = results;
}

void OpenGLProfilerVisualizer::setBorder(int left, int right, int top, int bottom)
{
  P(OpenGLProfilerVisualizerPrivate);
  p.m_topLeftBorder.setX(left);
  p.m_topLeftBorder.setY(top);
  p.m_bottomRightBorder.setX(right);
  p.m_bottomRightBorder.setY(bottom);
  p.m_dirty = true;
}

void OpenGLProfilerVisualizer::setOffset(float left, float right, float top, float bottom)
{
  P(OpenGLProfilerVisualizerPrivate);
  p.m_topLeftOffset.setX(left);
  p.m_topLeftOffset.setY(top);
  p.m_bottomRightOffset.setX(right);
  p.m_bottomRightOffset.setY(bottom);
  p.m_dirty = true;
}
