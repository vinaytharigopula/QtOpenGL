#include "Widget.h"
#include "ui_Widget.h"
#include "DuCoralScene.h"
#include "DuDefines.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mScene = new DuCoralScene(this);
    ui->graphicsView->setScene(mScene);

    setMinimumSize(X_SIZE + 50, Y_SIZE + 50);
    setMaximumSize(X_SIZE + 50, Y_SIZE + 50);
}

Widget::~Widget()
{
    delete ui;
}
