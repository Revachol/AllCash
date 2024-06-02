#ifndef CREDITS_H
#define CREDITS_H

#include <QDialog>
#include <QDate>
#include "../Main/financemanager.h"

namespace Ui {
class Credits;
}

class Credits : public QDialog
{
    Q_OBJECT

public:
    explicit Credits(QWidget *parent = nullptr);
    ~Credits();

signals:
    void updateView();
    void creditsWindowClosed();

private slots:
    void on_backButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Credits *ui;
    FinanceManager &manager;
};

#endif // CREDITS_H
