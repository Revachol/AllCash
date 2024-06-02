#include "opencredit.h"
#include "ui_opencredit.h"
#include "../Main/financemanager.h"


OpenCredit::OpenCredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenCredit)
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

    ui->creditAmountLabel->setText(QString::number(ui->creditAmountSlider->value()));
    ui->creditTermLabel->setText(QString::number(ui->creditTermSlider->value()));

    connect(ui->creditAmountSlider, &QSlider::valueChanged, this, &OpenCredit::on_creditAmountSlider_valueChanged);
    connect(ui->creditTermSlider, &QSlider::valueChanged, this, &OpenCredit::on_creditTermSlider_valueChanged);
}

OpenCredit::~OpenCredit()
{
    delete ui;
}

void OpenCredit::closeEvent(QCloseEvent *event)
{
    emit openCreditsWindowClosed();
    QDialog::closeEvent(event);
}

void OpenCredit::on_backButton_clicked()
{
    emit openCreditsWindowClosed();
    close();
}

void OpenCredit::on_openCreditButton_clicked()
{
    long long int creditAmount = ui->creditAmountSlider->value();
    int creditTerm = ui->creditTermSlider->value();

    FinanceManager& fm = FinanceManager::getInstance();
    fm.setCreditDetails(creditAmount, 3.5, creditTerm, QDate(2021, 6, 1), QDate(2021 + creditTerm, 6, 1));
    fm.setAccountDetails(fm.getAccountNumber(), fm.getAccountHolderName(), fm.getAccountBalance(),
                         fm.getAccountType(), fm.getOpeningDate(), fm.getCurrency(), true, fm.isDeposit());

    close();
}

void OpenCredit::on_creditAmountSlider_valueChanged(int value)
{
    int step = 50000;
    int adjustedValue = (value / step) * step;

    if (adjustedValue != value) {
        ui->creditAmountSlider->setValue(adjustedValue);
        return;
    }
    ui->creditAmountLabel->setText(QString::number(value));
}

void OpenCredit::on_creditTermSlider_valueChanged(int value)
{
    ui->creditTermLabel->setText(QString::number(value));
}


