#ifndef CREDITS_H
#define CREDITS_H

#include <QDate>
#include <QDialog>

#include "../Main/financemanager.h"

namespace Ui {
class Credits;
}

class Credits : public QDialog {
  Q_OBJECT

 public:
  explicit Credits(QWidget *parent = nullptr);
  ~Credits();

 signals:
  void creditsWindowClosed();

 private slots:
  void updateView();
  void on_backButton_clicked();

 protected:
  void closeEvent(QCloseEvent *event) override;

 private:
  Ui::Credits *ui;
  FinanceManager &manager;
};

#endif  // CREDITS_H
