/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <GlWidget2.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    GlWidget2 *openGLWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *Start;
    QSlider *rotXSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *rotYSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *rotZSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(625, 523);
        Widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new GlWidget2(Widget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(0, 400));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(label);

        Start = new QPushButton(Widget);
        Start->setObjectName(QString::fromUtf8("Start"));

        horizontalLayout->addWidget(Start);

        rotXSlider = new QSlider(Widget);
        rotXSlider->setObjectName(QString::fromUtf8("rotXSlider"));
        rotXSlider->setMaximum(5000);
        rotXSlider->setSingleStep(16);
        rotXSlider->setPageStep(15);
        rotXSlider->setOrientation(Qt::Horizontal);
        rotXSlider->setTickPosition(QSlider::TicksAbove);
        rotXSlider->setTickInterval(15);

        horizontalLayout->addWidget(rotXSlider);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(label_2);

        rotYSlider = new QSlider(Widget);
        rotYSlider->setObjectName(QString::fromUtf8("rotYSlider"));
        rotYSlider->setMaximum(5000);
        rotYSlider->setSingleStep(16);
        rotYSlider->setPageStep(15);
        rotYSlider->setOrientation(Qt::Horizontal);
        rotYSlider->setTickPosition(QSlider::TicksAbove);
        rotYSlider->setTickInterval(15);

        horizontalLayout_2->addWidget(rotYSlider);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(label_3);

        rotZSlider = new QSlider(Widget);
        rotZSlider->setObjectName(QString::fromUtf8("rotZSlider"));
        rotZSlider->setMaximum(5000);
        rotZSlider->setSingleStep(16);
        rotZSlider->setPageStep(15);
        rotZSlider->setOrientation(Qt::Horizontal);
        rotZSlider->setTickPosition(QSlider::TicksAbove);
        rotZSlider->setTickInterval(15);

        horizontalLayout_3->addWidget(rotZSlider);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "X ", nullptr));
        Start->setText(QApplication::translate("Widget", "Start", nullptr));
        label_2->setText(QApplication::translate("Widget", "Y", nullptr));
        label_3->setText(QApplication::translate("Widget", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
