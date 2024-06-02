#ifndef OPENDEPOSIT_H
#define OPENDEPOSIT_H

#include <QDialog>

namespace Ui {
class OpenDeposit;
}

class OpenDeposit : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDeposit(QWidget *parent = nullptr);
    ~OpenDeposit();


signals:
    void openDepositWindowClosed();

private slots:
    void on_openDepositButton_clicked();
    void on_backButton_clicked();

    void on_depositOpenButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void depositOpened();

private:
    Ui::OpenDeposit *ui;
};

#endif // OPENDEPOSIT_H
