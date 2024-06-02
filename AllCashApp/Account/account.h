#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <QString>
#include <QDate>
#include "../Main/financemanager.h"

namespace Ui {
class Account;
}

class Account : public QDialog
{
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
