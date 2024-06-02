#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Account/account.h"
#include "../Calculation/annuityintereststrategy.h"
#include "../Calculation/depositcalculationstrategy.h"
#include "../Credit/credits.h"
#include "../Credit/opencredit.h"
#include "../Deposit/deposit.h"
#include "../Deposit/opendeposit.h"
#include "../FactoryMethod/factorymethod.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();
  void on_pushButtonCredits_clicked();
  void showMainWindow();
  void showCreditsWindow();
  void showDepositWindow();

  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();

 private:
  Ui::MainWindow *ui;
  Account *accountWindow;
  Credits *creditsWindow;
  Deposit *depositWindow;
  OpenCredit *openCreditWindow;
  OpenDeposit *openDepositWindow;
  FactoryMethod *factory;
};

#endif  // MAINWINDOW_H
