#ifndef CREDITS_H
#define CREDITS_H

#include <QDialog>

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
    void creditsWindowClosed();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Credits *ui;
};

#endif // CREDITS_H
