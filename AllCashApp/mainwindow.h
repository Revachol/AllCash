#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "account.h"
#include "credits.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButtonCredits_clicked();  // Слот для кнопки открытия окна Credits
    void showMainWindow();  // Слот для показа главного окна

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Account *accountWindow;
    Credits *creditsWindow;
};

#endif // MAINWINDOW_H
