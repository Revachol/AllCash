#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../Main/financemanager.h"
#include <QDate>
#include <QDialog>
#include <QString>

namespace Ui {
class Account;
}

class Account : public QDialog {
  Q_OBJECT

public:
  explicit Account(QWidget *parent = nullptr);
  ~Account();

signals:
  void accountWindowClosed();

private slots:
  void updateView();
  void on_backButton_clicked();

protected:
  void closeEvent(QCloseEvent *event) override;

private:
  Ui::Account *ui;
  FinanceManager &manager;
};

#endif // ACCOUNT_H
