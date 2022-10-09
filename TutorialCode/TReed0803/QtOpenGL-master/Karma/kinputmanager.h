#ifndef KINPUTMANAGER_H
#define KINPUTMANAGER_H KInputManager

#include <KPoint>
#include <KTouchPoint>
#include <Qt>

class QGestureEvent;
class QKeyEvent;
class QMouseEvent;
class KPinchGesture;
class KPanGesture;

class KInputManager
{
public:

  // Possible key states
  enum InputState
  {
    InputInvalid,
    InputRegistered,
    InputUnregistered,
    InputTriggered,
    InputPressed,
    InputReleased
  };

  // State checking
  static InputState keyState(Qt::Key key);
  static bool keyTriggered(Qt::Key key);
  static bool keyPressed(Qt::Key key);
  static bool keyReleased(Qt::Key key);
  static InputState buttonState(Qt::MouseButton button);
  static bool buttonTriggered(Qt::MouseButton button);
  static bool buttonPressed(Qt::MouseButton button);
  static bool buttonReleased(Qt::MouseButton button);
  static KPoint mousePosition();
  static KPoint mouseDelta();
  static int touchCount();
  static KTouchPoint touchPoint(int idx);
  static bool pinchGesture(KPinchGesture *info);
  static bool panGesture(KPanGesture *info);

  // State updating
  static void update();
  static void registerKeyPressEvent(QKeyEvent *event);
  static void registerKeyReleaseEvent(QKeyEvent *event);
  static void registerMousePressEvent(QMouseEvent *event);
  static void registerMouseReleaseEvent(QMouseEvent *event);
  static void registerMouseMoveEvent(QMouseEvent *event);
  static void registerTouchEvent(QTouchEvent *event);
  static void registerGestureEvent(QGestureEvent *event);
  static void reset();
};

inline bool KInputManager::keyTriggered(Qt::Key key)
{
  return keyState(key) == InputTriggered;
}

inline bool KInputManager::keyPressed(Qt::Key key)
{
  return keyState(key) == InputPressed;
}

inline bool KInputManager::keyReleased(Qt::Key key)
{
  return keyState(key) == InputReleased;
}

inline bool KInputManager::buttonTriggered(Qt::MouseButton button)
{
  return buttonState(button) == InputTriggered;
}

inline bool KInputManager::buttonPressed(Qt::MouseButton button)
{
  return buttonState(button) == InputPressed;
}

inline bool KInputManager::buttonReleased(Qt::MouseButton button)
{
  return buttonState(button) == InputReleased;
}

#endif // KINPUTMANAGER_H
