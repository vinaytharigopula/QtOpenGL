/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <qglbegin.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QSlider *z_rot_slider;
    QLabel *label_3;
    QSlider *x_rot_slider;
    QLabel *label_4;
    QSlider *y_rot_slider;
    QLabel *label_5;
    QGLBegin *openGLWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(609, 493);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        z_rot_slider = new QSlider(centralWidget);
        z_rot_slider->setObjectName(QString::fromUtf8("z_rot_slider"));
        z_rot_slider->setMinimum(0);
        z_rot_slider->setMaximum(360);
        z_rot_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(z_rot_slider, 2, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        x_rot_slider = new QSlider(centralWidget);
        x_rot_slider->setObjectName(QString::fromUtf8("x_rot_slider"));
        x_rot_slider->setMinimum(0);
        x_rot_slider->setMaximum(360);
        x_rot_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(x_rot_slider, 0, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        y_rot_slider = new QSlider(centralWidget);
        y_rot_slider->setObjectName(QString::fromUtf8("y_rot_slider"));
        y_rot_slider->setMinimum(0);
        y_rot_slider->setMaximum(360);
        y_rot_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(y_rot_slider, 1, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 1, 1, 3);

        openGLWidget = new QGLBegin(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(openGLWidget, 0, 1, 1, 3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Begin OpenGL", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Rotate X:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Rotate Y:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Rotate Z:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
