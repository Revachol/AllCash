#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "../Main/financemanager.h"
#include <QDate>
#include <QDialog>
#include <QString>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog {
  Q_OBJECT

public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

signals:
  void depositWindowClosed();

private slots:
  void updateView();
  void on_backButton_clicked();

protected:
  void closeEvent(QCloseEvent *event) override;

private:
  Ui::Deposit *ui;
  FinanceManager &manager;
};

#endif // Deposit
