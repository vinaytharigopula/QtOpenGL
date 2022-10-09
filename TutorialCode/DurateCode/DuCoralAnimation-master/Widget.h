#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class DuCoralScene;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
    DuCoralScene *mScene;
};

#endif // WIDGET_H
