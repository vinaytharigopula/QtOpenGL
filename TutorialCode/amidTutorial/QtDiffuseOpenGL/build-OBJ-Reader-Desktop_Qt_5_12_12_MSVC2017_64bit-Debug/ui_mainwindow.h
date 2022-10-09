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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qobj3dviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *actionAbout_Qt;
    QAction *actionE_xit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QObj3dViewer *obj3dViewer;
    QTabWidget *mainTabs;
    QWidget *perspectiveTab;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *persVerticalAngleSpin;
    QSlider *persVerticalAngleSlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *persNearSpin;
    QSlider *persNearSlider;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *persFarSpin;
    QSlider *persFarSlider;
    QWidget *lookAtTab;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDoubleSpinBox *lookEyeXSpin;
    QDoubleSpinBox *lookEyeYSpin;
    QDoubleSpinBox *lookEyeZSpin;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDoubleSpinBox *lookCenterXSpin;
    QDoubleSpinBox *lookCenterYSpin;
    QDoubleSpinBox *lookCenterZSpin;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QDoubleSpinBox *lookUpXSpin;
    QDoubleSpinBox *lookUpYSpin;
    QDoubleSpinBox *lookUpZSpin;
    QWidget *transformTab;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QDoubleSpinBox *scaleSpin;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QDoubleSpinBox *translateXSpin;
    QDoubleSpinBox *translateYSpin;
    QDoubleSpinBox *translateZSpin;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QDoubleSpinBox *rotateAngleSpin;
    QDoubleSpinBox *rotateXSpin;
    QDoubleSpinBox *rotateYSpin;
    QDoubleSpinBox *rotateZSpin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QSlider *rotateAngleSlider;
    QWidget *textureTab;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *textureFileEdit;
    QPushButton *browseTextureBtn;
    QWidget *diffuseLightTab;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QDoubleSpinBox *lightKd1Spin;
    QDoubleSpinBox *lightKd2Spin;
    QDoubleSpinBox *lightKd3Spin;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QDoubleSpinBox *lightPosXSpin;
    QDoubleSpinBox *lightPosYSpin;
    QDoubleSpinBox *lightPosZSpin;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QDoubleSpinBox *lightLd1Spin;
    QDoubleSpinBox *lightLd2Spin;
    QDoubleSpinBox *lightLd3Spin;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(747, 589);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionE_xit = new QAction(MainWindow);
        actionE_xit->setObjectName(QString::fromUtf8("actionE_xit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        obj3dViewer = new QObj3dViewer(groupBox);
        obj3dViewer->setObjectName(QString::fromUtf8("obj3dViewer"));

        gridLayout_2->addWidget(obj3dViewer, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        mainTabs = new QTabWidget(centralWidget);
        mainTabs->setObjectName(QString::fromUtf8("mainTabs"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainTabs->sizePolicy().hasHeightForWidth());
        mainTabs->setSizePolicy(sizePolicy1);
        perspectiveTab = new QWidget();
        perspectiveTab->setObjectName(QString::fromUtf8("perspectiveTab"));
        gridLayout_7 = new QGridLayout(perspectiveTab);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(perspectiveTab);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label);

        persVerticalAngleSpin = new QDoubleSpinBox(perspectiveTab);
        persVerticalAngleSpin->setObjectName(QString::fromUtf8("persVerticalAngleSpin"));
        persVerticalAngleSpin->setDecimals(2);
        persVerticalAngleSpin->setMinimum(0.000000000000000);
        persVerticalAngleSpin->setMaximum(360.000000000000000);
        persVerticalAngleSpin->setSingleStep(0.100000000000000);
        persVerticalAngleSpin->setValue(30.000000000000000);

        horizontalLayout_2->addWidget(persVerticalAngleSpin);

        persVerticalAngleSlider = new QSlider(perspectiveTab);
        persVerticalAngleSlider->setObjectName(QString::fromUtf8("persVerticalAngleSlider"));
        persVerticalAngleSlider->setMaximum(36000);
        persVerticalAngleSlider->setValue(3000);
        persVerticalAngleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(persVerticalAngleSlider);


        gridLayout_7->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(perspectiveTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_3);

        persNearSpin = new QDoubleSpinBox(perspectiveTab);
        persNearSpin->setObjectName(QString::fromUtf8("persNearSpin"));
        persNearSpin->setDecimals(2);
        persNearSpin->setMinimum(0.000000000000000);
        persNearSpin->setMaximum(999.000000000000000);
        persNearSpin->setSingleStep(0.100000000000000);
        persNearSpin->setValue(0.100000000000000);

        horizontalLayout_4->addWidget(persNearSpin);

        persNearSlider = new QSlider(perspectiveTab);
        persNearSlider->setObjectName(QString::fromUtf8("persNearSlider"));
        persNearSlider->setMaximum(99900);
        persNearSlider->setValue(10);
        persNearSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(persNearSlider);


        gridLayout_7->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(perspectiveTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_4);

        persFarSpin = new QDoubleSpinBox(perspectiveTab);
        persFarSpin->setObjectName(QString::fromUtf8("persFarSpin"));
        persFarSpin->setMinimum(0.000000000000000);
        persFarSpin->setMaximum(999.000000000000000);
        persFarSpin->setSingleStep(0.100000000000000);
        persFarSpin->setValue(100.000000000000000);

        horizontalLayout_5->addWidget(persFarSpin);

        persFarSlider = new QSlider(perspectiveTab);
        persFarSlider->setObjectName(QString::fromUtf8("persFarSlider"));
        persFarSlider->setMaximum(99900);
        persFarSlider->setValue(10000);
        persFarSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(persFarSlider);


        gridLayout_7->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        mainTabs->addTab(perspectiveTab, QString());
        lookAtTab = new QWidget();
        lookAtTab->setObjectName(QString::fromUtf8("lookAtTab"));
        gridLayout_3 = new QGridLayout(lookAtTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(lookAtTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_5);

        lookEyeXSpin = new QDoubleSpinBox(lookAtTab);
        lookEyeXSpin->setObjectName(QString::fromUtf8("lookEyeXSpin"));
        lookEyeXSpin->setMinimum(-99999.000000000000000);
        lookEyeXSpin->setMaximum(99999.000000000000000);
        lookEyeXSpin->setSingleStep(0.100000000000000);
        lookEyeXSpin->setValue(-5.000000000000000);

        horizontalLayout_6->addWidget(lookEyeXSpin);

        lookEyeYSpin = new QDoubleSpinBox(lookAtTab);
        lookEyeYSpin->setObjectName(QString::fromUtf8("lookEyeYSpin"));
        lookEyeYSpin->setMinimum(-99999.000000000000000);
        lookEyeYSpin->setMaximum(99999.000000000000000);
        lookEyeYSpin->setSingleStep(0.100000000000000);
        lookEyeYSpin->setValue(2.000000000000000);

        horizontalLayout_6->addWidget(lookEyeYSpin);

        lookEyeZSpin = new QDoubleSpinBox(lookAtTab);
        lookEyeZSpin->setObjectName(QString::fromUtf8("lookEyeZSpin"));
        lookEyeZSpin->setMinimum(-99999.000000000000000);
        lookEyeZSpin->setMaximum(99999.000000000000000);
        lookEyeZSpin->setSingleStep(0.100000000000000);
        lookEyeZSpin->setValue(5.000000000000000);

        horizontalLayout_6->addWidget(lookEyeZSpin);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(lookAtTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_6);

        lookCenterXSpin = new QDoubleSpinBox(lookAtTab);
        lookCenterXSpin->setObjectName(QString::fromUtf8("lookCenterXSpin"));
        lookCenterXSpin->setMinimum(-99999.000000000000000);
        lookCenterXSpin->setMaximum(99999.000000000000000);
        lookCenterXSpin->setSingleStep(0.100000000000000);

        horizontalLayout_7->addWidget(lookCenterXSpin);

        lookCenterYSpin = new QDoubleSpinBox(lookAtTab);
        lookCenterYSpin->setObjectName(QString::fromUtf8("lookCenterYSpin"));
        lookCenterYSpin->setMinimum(-99999.000000000000000);
        lookCenterYSpin->setMaximum(99999.000000000000000);
        lookCenterYSpin->setSingleStep(0.100000000000000);

        horizontalLayout_7->addWidget(lookCenterYSpin);

        lookCenterZSpin = new QDoubleSpinBox(lookAtTab);
        lookCenterZSpin->setObjectName(QString::fromUtf8("lookCenterZSpin"));
        lookCenterZSpin->setMinimum(-99999.000000000000000);
        lookCenterZSpin->setMaximum(99999.000000000000000);
        lookCenterZSpin->setSingleStep(0.100000000000000);

        horizontalLayout_7->addWidget(lookCenterZSpin);


        gridLayout_3->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(lookAtTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(label_7);

        lookUpXSpin = new QDoubleSpinBox(lookAtTab);
        lookUpXSpin->setObjectName(QString::fromUtf8("lookUpXSpin"));
        lookUpXSpin->setMinimum(-99999.000000000000000);
        lookUpXSpin->setMaximum(99999.000000000000000);
        lookUpXSpin->setSingleStep(0.100000000000000);

        horizontalLayout_8->addWidget(lookUpXSpin);

        lookUpYSpin = new QDoubleSpinBox(lookAtTab);
        lookUpYSpin->setObjectName(QString::fromUtf8("lookUpYSpin"));
        lookUpYSpin->setMinimum(-99999.000000000000000);
        lookUpYSpin->setMaximum(99999.000000000000000);
        lookUpYSpin->setSingleStep(0.100000000000000);
        lookUpYSpin->setValue(1.000000000000000);

        horizontalLayout_8->addWidget(lookUpYSpin);

        lookUpZSpin = new QDoubleSpinBox(lookAtTab);
        lookUpZSpin->setObjectName(QString::fromUtf8("lookUpZSpin"));
        lookUpZSpin->setMinimum(-99999.000000000000000);
        lookUpZSpin->setMaximum(99999.000000000000000);
        lookUpZSpin->setSingleStep(0.100000000000000);

        horizontalLayout_8->addWidget(lookUpZSpin);


        gridLayout_3->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        mainTabs->addTab(lookAtTab, QString());
        transformTab = new QWidget();
        transformTab->setObjectName(QString::fromUtf8("transformTab"));
        gridLayout_4 = new QGridLayout(transformTab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(transformTab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(label_8);

        scaleSpin = new QDoubleSpinBox(transformTab);
        scaleSpin->setObjectName(QString::fromUtf8("scaleSpin"));
        scaleSpin->setMinimum(-99999.000000000000000);
        scaleSpin->setMaximum(99999.000000000000000);
        scaleSpin->setSingleStep(0.100000000000000);
        scaleSpin->setValue(1.000000000000000);

        horizontalLayout_9->addWidget(scaleSpin);


        gridLayout_4->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(transformTab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_9);

        translateXSpin = new QDoubleSpinBox(transformTab);
        translateXSpin->setObjectName(QString::fromUtf8("translateXSpin"));
        translateXSpin->setMinimum(-99999.000000000000000);
        translateXSpin->setMaximum(99999.000000000000000);
        translateXSpin->setSingleStep(0.100000000000000);

        horizontalLayout_10->addWidget(translateXSpin);

        translateYSpin = new QDoubleSpinBox(transformTab);
        translateYSpin->setObjectName(QString::fromUtf8("translateYSpin"));
        translateYSpin->setMinimum(-99999.000000000000000);
        translateYSpin->setMaximum(99999.000000000000000);
        translateYSpin->setSingleStep(0.100000000000000);

        horizontalLayout_10->addWidget(translateYSpin);

        translateZSpin = new QDoubleSpinBox(transformTab);
        translateZSpin->setObjectName(QString::fromUtf8("translateZSpin"));
        translateZSpin->setMinimum(-99999.000000000000000);
        translateZSpin->setMaximum(99999.000000000000000);
        translateZSpin->setSingleStep(0.100000000000000);

        horizontalLayout_10->addWidget(translateZSpin);


        gridLayout_4->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(transformTab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(label_10);

        rotateAngleSpin = new QDoubleSpinBox(transformTab);
        rotateAngleSpin->setObjectName(QString::fromUtf8("rotateAngleSpin"));
        rotateAngleSpin->setMinimum(-99999.000000000000000);
        rotateAngleSpin->setMaximum(99999.000000000000000);
        rotateAngleSpin->setSingleStep(0.100000000000000);

        horizontalLayout_11->addWidget(rotateAngleSpin);

        rotateXSpin = new QDoubleSpinBox(transformTab);
        rotateXSpin->setObjectName(QString::fromUtf8("rotateXSpin"));
        rotateXSpin->setMinimum(-99999.000000000000000);
        rotateXSpin->setMaximum(99999.000000000000000);
        rotateXSpin->setSingleStep(0.100000000000000);

        horizontalLayout_11->addWidget(rotateXSpin);

        rotateYSpin = new QDoubleSpinBox(transformTab);
        rotateYSpin->setObjectName(QString::fromUtf8("rotateYSpin"));
        rotateYSpin->setMinimum(-99999.000000000000000);
        rotateYSpin->setMaximum(99999.000000000000000);
        rotateYSpin->setSingleStep(0.100000000000000);

        horizontalLayout_11->addWidget(rotateYSpin);

        rotateZSpin = new QDoubleSpinBox(transformTab);
        rotateZSpin->setObjectName(QString::fromUtf8("rotateZSpin"));
        rotateZSpin->setMinimum(-99999.000000000000000);
        rotateZSpin->setMaximum(99999.000000000000000);
        rotateZSpin->setSingleStep(0.100000000000000);

        horizontalLayout_11->addWidget(rotateZSpin);


        gridLayout_4->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_14 = new QLabel(transformTab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);

        rotateAngleSlider = new QSlider(transformTab);
        rotateAngleSlider->setObjectName(QString::fromUtf8("rotateAngleSlider"));
        rotateAngleSlider->setMinimum(-3600);
        rotateAngleSlider->setMaximum(3600);
        rotateAngleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(rotateAngleSlider);


        gridLayout_4->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        mainTabs->addTab(transformTab, QString());
        textureTab = new QWidget();
        textureTab->setObjectName(QString::fromUtf8("textureTab"));
        gridLayout_6 = new QGridLayout(textureTab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(textureTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        textureFileEdit = new QLineEdit(textureTab);
        textureFileEdit->setObjectName(QString::fromUtf8("textureFileEdit"));

        horizontalLayout->addWidget(textureFileEdit);

        browseTextureBtn = new QPushButton(textureTab);
        browseTextureBtn->setObjectName(QString::fromUtf8("browseTextureBtn"));

        horizontalLayout->addWidget(browseTextureBtn);


        gridLayout_6->addLayout(horizontalLayout, 0, 0, 1, 1);

        mainTabs->addTab(textureTab, QString());
        diffuseLightTab = new QWidget();
        diffuseLightTab->setObjectName(QString::fromUtf8("diffuseLightTab"));
        gridLayout_5 = new QGridLayout(diffuseLightTab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_12 = new QLabel(diffuseLightTab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        horizontalLayout_14->addWidget(label_12);

        lightKd1Spin = new QDoubleSpinBox(diffuseLightTab);
        lightKd1Spin->setObjectName(QString::fromUtf8("lightKd1Spin"));
        lightKd1Spin->setSingleStep(0.100000000000000);
        lightKd1Spin->setValue(0.000000000000000);

        horizontalLayout_14->addWidget(lightKd1Spin);

        lightKd2Spin = new QDoubleSpinBox(diffuseLightTab);
        lightKd2Spin->setObjectName(QString::fromUtf8("lightKd2Spin"));
        lightKd2Spin->setSingleStep(0.100000000000000);
        lightKd2Spin->setValue(1.000000000000000);

        horizontalLayout_14->addWidget(lightKd2Spin);

        lightKd3Spin = new QDoubleSpinBox(diffuseLightTab);
        lightKd3Spin->setObjectName(QString::fromUtf8("lightKd3Spin"));
        lightKd3Spin->setSingleStep(0.100000000000000);
        lightKd3Spin->setValue(0.000000000000000);

        horizontalLayout_14->addWidget(lightKd3Spin);


        gridLayout_5->addLayout(horizontalLayout_14, 1, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(diffuseLightTab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        horizontalLayout_13->addWidget(label_11);

        lightPosXSpin = new QDoubleSpinBox(diffuseLightTab);
        lightPosXSpin->setObjectName(QString::fromUtf8("lightPosXSpin"));
        lightPosXSpin->setMinimum(-99999.000000000000000);
        lightPosXSpin->setMaximum(99999.000000000000000);
        lightPosXSpin->setSingleStep(0.100000000000000);
        lightPosXSpin->setValue(-25.000000000000000);

        horizontalLayout_13->addWidget(lightPosXSpin);

        lightPosYSpin = new QDoubleSpinBox(diffuseLightTab);
        lightPosYSpin->setObjectName(QString::fromUtf8("lightPosYSpin"));
        lightPosYSpin->setMinimum(-99999.000000000000000);
        lightPosYSpin->setMaximum(99999.000000000000000);
        lightPosYSpin->setSingleStep(0.100000000000000);
        lightPosYSpin->setValue(25.000000000000000);

        horizontalLayout_13->addWidget(lightPosYSpin);

        lightPosZSpin = new QDoubleSpinBox(diffuseLightTab);
        lightPosZSpin->setObjectName(QString::fromUtf8("lightPosZSpin"));
        lightPosZSpin->setMinimum(-99999.000000000000000);
        lightPosZSpin->setMaximum(99999.000000000000000);
        lightPosZSpin->setSingleStep(0.100000000000000);
        lightPosZSpin->setValue(25.000000000000000);

        horizontalLayout_13->addWidget(lightPosZSpin);


        gridLayout_5->addLayout(horizontalLayout_13, 0, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_13 = new QLabel(diffuseLightTab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);

        horizontalLayout_15->addWidget(label_13);

        lightLd1Spin = new QDoubleSpinBox(diffuseLightTab);
        lightLd1Spin->setObjectName(QString::fromUtf8("lightLd1Spin"));
        lightLd1Spin->setSingleStep(0.100000000000000);
        lightLd1Spin->setValue(1.000000000000000);

        horizontalLayout_15->addWidget(lightLd1Spin);

        lightLd2Spin = new QDoubleSpinBox(diffuseLightTab);
        lightLd2Spin->setObjectName(QString::fromUtf8("lightLd2Spin"));
        lightLd2Spin->setSingleStep(0.100000000000000);
        lightLd2Spin->setValue(1.000000000000000);

        horizontalLayout_15->addWidget(lightLd2Spin);

        lightLd3Spin = new QDoubleSpinBox(diffuseLightTab);
        lightLd3Spin->setObjectName(QString::fromUtf8("lightLd3Spin"));
        lightLd3Spin->setSingleStep(0.100000000000000);
        lightLd3Spin->setValue(1.000000000000000);

        horizontalLayout_15->addWidget(lightLd3Spin);


        gridLayout_5->addLayout(horizontalLayout_15, 2, 0, 1, 1);

        mainTabs->addTab(diffuseLightTab, QString());

        gridLayout->addWidget(mainTabs, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 747, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(mainTabs, persVerticalAngleSpin);
        QWidget::setTabOrder(persVerticalAngleSpin, persVerticalAngleSlider);
        QWidget::setTabOrder(persVerticalAngleSlider, persNearSpin);
        QWidget::setTabOrder(persNearSpin, persNearSlider);
        QWidget::setTabOrder(persNearSlider, persFarSpin);
        QWidget::setTabOrder(persFarSpin, persFarSlider);
        QWidget::setTabOrder(persFarSlider, lookEyeXSpin);
        QWidget::setTabOrder(lookEyeXSpin, lookEyeYSpin);
        QWidget::setTabOrder(lookEyeYSpin, lookEyeZSpin);
        QWidget::setTabOrder(lookEyeZSpin, lookCenterXSpin);
        QWidget::setTabOrder(lookCenterXSpin, lookCenterYSpin);
        QWidget::setTabOrder(lookCenterYSpin, lookCenterZSpin);
        QWidget::setTabOrder(lookCenterZSpin, lookUpXSpin);
        QWidget::setTabOrder(lookUpXSpin, lookUpYSpin);
        QWidget::setTabOrder(lookUpYSpin, lookUpZSpin);
        QWidget::setTabOrder(lookUpZSpin, scaleSpin);
        QWidget::setTabOrder(scaleSpin, translateXSpin);
        QWidget::setTabOrder(translateXSpin, translateYSpin);
        QWidget::setTabOrder(translateYSpin, translateZSpin);
        QWidget::setTabOrder(translateZSpin, rotateAngleSpin);
        QWidget::setTabOrder(rotateAngleSpin, rotateXSpin);
        QWidget::setTabOrder(rotateXSpin, rotateYSpin);
        QWidget::setTabOrder(rotateYSpin, rotateZSpin);
        QWidget::setTabOrder(rotateZSpin, rotateAngleSlider);
        QWidget::setTabOrder(rotateAngleSlider, textureFileEdit);
        QWidget::setTabOrder(textureFileEdit, browseTextureBtn);
        QWidget::setTabOrder(browseTextureBtn, lightPosXSpin);
        QWidget::setTabOrder(lightPosXSpin, lightPosYSpin);
        QWidget::setTabOrder(lightPosYSpin, lightPosZSpin);
        QWidget::setTabOrder(lightPosZSpin, lightKd1Spin);
        QWidget::setTabOrder(lightKd1Spin, lightKd2Spin);
        QWidget::setTabOrder(lightKd2Spin, lightKd3Spin);
        QWidget::setTabOrder(lightKd3Spin, lightLd1Spin);
        QWidget::setTabOrder(lightLd1Spin, lightLd2Spin);
        QWidget::setTabOrder(lightLd2Spin, lightLd3Spin);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addSeparator();
        menu_File->addAction(actionE_xit);
        menu_Help->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        mainTabs->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OBJ-Reader", nullptr));
        action_Open->setText(QApplication::translate("MainWindow", "&Open OBJ", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About &Qt", nullptr));
        actionE_xit->setText(QApplication::translate("MainWindow", "E&xit", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "OBJ Viewer", nullptr));
        label->setText(QApplication::translate("MainWindow", "Vertical Angle (Zoom) :", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Near Plane :", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Far Plane :", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(perspectiveTab), QApplication::translate("MainWindow", "Perspective", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Eye (X,Y,Z) :", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Center (X,Y,Z) :", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Up (X,Y,Z) :", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(lookAtTab), QApplication::translate("MainWindow", "Look At", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Scale :", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Translate (X,Y,Z) :", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Rotate (Angle,X,Y,Z) :", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Rotate (-360 : +360) :", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(transformTab), QApplication::translate("MainWindow", "Transformation", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Texture File :", nullptr));
        browseTextureBtn->setText(QApplication::translate("MainWindow", "Browse", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(textureTab), QApplication::translate("MainWindow", "Texture", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Kd (Diffuse Reflectivity) :", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Position (X,Y,Z) :", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Ld (Light Source Intensity) :", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(diffuseLightTab), QApplication::translate("MainWindow", "Diffuse", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
