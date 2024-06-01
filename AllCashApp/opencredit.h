#ifndef OPENCREDIT_H
#define OPENCREDIT_H

#include <QDialog>

namespace Ui {
class OpenCredit;
}

class OpenCredit : public QDialog
{
    Q_OBJECT

public:
    explicit OpenCredit(QWidget *parent = nullptr);
    ~OpenCredit();

signals:
    void openCreditsWindowClosed();

private slots:
    void on_openCreditButton_clicked();
    void on_creditAmountSlider_valueChanged(int value);
    void on_creditTermSlider_valueChanged(int value);

    void on_backButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void creditOpened();

private:
    Ui::OpenCredit *ui;
};

#endif // OPENCREDIT_H
