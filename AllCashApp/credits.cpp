#include "credits.h"
#include "ui_credits.h"
#include "financemanager.h"

Credits::Credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/logo.png");
    int w = ui->logo->width();
    int h = ui->logo->height();

    ui->logo->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    QPixmap bkgnd(":/resources/img/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    // Получение данных из FinanceManager и установка в UI
    FinanceManager& fm = FinanceManager::getInstance();
    ui->creditAmountLabel->setText(QString::number(fm.getCreditAmount()));
    ui->interestRateLabel->setText(QString::number(fm.getInterestRate()));
    ui->termLabel->setText(QString::number(fm.getTerm()));
    ui->startDateLabel->setText(fm.getCreditStartDate().toString());
    ui->endDateLabel->setText(fm.getCreditEndDate().toString());
}

Credits::~Credits()
{
    delete ui;
}

void Credits::closeEvent(QCloseEvent *event)
{
    emit creditsWindowClosed();
    QDialog::closeEvent(event);
}
