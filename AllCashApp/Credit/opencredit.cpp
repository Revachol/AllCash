#include "opencredit.h"
#include "ui_opencredit.h"
#include "../Calculation/annuityintereststrategy.h"


OpenCredit::OpenCredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenCredit),
    manager(FinanceManager::getInstance()),
    сalculationStrategy(new AnnuityInterestStrategy)
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

    connect(&manager, &FinanceManager::dataChanged, this, &OpenCredit::updateView);
    updateView();
}

OpenCredit::~OpenCredit()
{
    delete ui;
    delete сalculationStrategy;
}

void OpenCredit::setCalculationStrategy(CalculationStrategy *strategy) {
    if (сalculationStrategy) {
        delete сalculationStrategy;
    }
    сalculationStrategy = strategy;
}

void OpenCredit::updateView(){
    ui->creditAmountLabel->setText(QString::number(ui->creditAmountSlider->value()));
    ui->creditTermLabel->setText(QString::number(ui->creditTermSlider->value()));

    connect(ui->creditAmountSlider, &QSlider::valueChanged, this, &OpenCredit::on_creditAmountSlider_valueChanged);
    connect(ui->creditTermSlider, &QSlider::valueChanged, this, &OpenCredit::on_creditTermSlider_valueChanged);
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

    manager.setCreditAmount(creditAmount);
    manager.setCreditTerm(creditTerm);
    manager.setInterestRate(3.5);
    manager.setCreditStartDate(QDate(2022,6,1));
    manager.setCreditEndDate(QDate(2022 + creditTerm, 6, 1));
    manager.setCreditOpened(true);
    if (сalculationStrategy) {
        double monthlyPayment = сalculationStrategy->calculate(creditAmount, 3.5, creditTerm*12);
        manager.setMonthlyPayment(monthlyPayment);
    }

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


