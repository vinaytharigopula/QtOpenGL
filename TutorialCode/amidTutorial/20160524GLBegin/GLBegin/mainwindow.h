#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// www.amin-ahmadi.com

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_x_rot_slider_valueChanged(int value);

    void on_y_rot_slider_valueChanged(int value);

    void on_z_rot_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
