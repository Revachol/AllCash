#ifndef OPENDEPOSIT_H
#define OPENDEPOSIT_H

#include <QDialog>
#include "../Main/financemanager.h"
#include "../Calculation/calculationstrategy.h"

namespace Ui {
class OpenDeposit;
}

class OpenDeposit : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDeposit(QWidget *parent = nullptr);
    ~OpenDeposit();

    void setCalculationStrategy(CalculationStrategy *strategy);

signals:
    void openDepositWindowClosed();

private slots:
    void on_backButton_clicked();
    void on_depositOpenButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void depositOpened();

private:
    Ui::OpenDeposit *ui;
    FinanceManager &manager;
    CalculationStrategy *calculationStrategy;

};

#endif // OPENDEPOSIT_H
