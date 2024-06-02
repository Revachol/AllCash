#ifndef OPENCREDIT_H
#define OPENCREDIT_H

#include "../Calculation/calculationstrategy.h"
#include "../Main/financemanager.h"
#include <QDialog>

namespace Ui {
class OpenCredit;
}

class OpenCredit : public QDialog {
  Q_OBJECT

public:
  explicit OpenCredit(QWidget *parent = nullptr);
  ~OpenCredit();
  void setCalculationStrategy(CalculationStrategy *strategy);

signals:
  void openCreditsWindowClosed();

private slots:
  void on_openCreditButton_clicked();
  void on_creditAmountSlider_valueChanged(int value);
  void on_creditTermSlider_valueChanged(int value);
  void on_backButton_clicked();
  void updateView();

protected:
  void closeEvent(QCloseEvent *event) override;

signals:
  void creditOpened();

private:
  Ui::OpenCredit *ui;
  FinanceManager &manager;
  CalculationStrategy *сalculationStrategy;
};

#endif // OPENCREDIT_H
