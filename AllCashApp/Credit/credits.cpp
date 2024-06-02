#include "credits.h"

#include "ui_credits.h"

Credits::Credits(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::Credits),
      manager(FinanceManager::getInstance()) {
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

  connect(&manager, &FinanceManager::dataChanged, this, &Credits::updateView);
  updateView();
}

Credits::~Credits() { delete ui; }

void Credits::updateView() {
  ui->creditAmountLabel->setText(
      QString::number(manager.getCreditAmount(), 'f', 0) + " рублей");
  ui->interestRateLabel->setText(QString::number(manager.getInterestRate()) +
                                 "%");
  ui->termLabel->setText(QString::number(manager.getCreditTerm()) + " лет");
  ui->startDateLabel->setText(manager.getCreditStartDate().toString());
  ui->endDateLabel->setText(manager.getCreditEndDate().toString());
  ui->monthlyPaymentLabel->setText(
      QString::number(manager.getMonthlyPayment(), 'f', 2) + " рублей");
}

void Credits::closeEvent(QCloseEvent *event) {
  emit creditsWindowClosed();
  QDialog::closeEvent(event);
}

void Credits::on_backButton_clicked() {
  emit creditsWindowClosed();
  close();
}
