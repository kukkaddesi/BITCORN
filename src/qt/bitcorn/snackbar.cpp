// Copyright (c) 2019 The BITCORN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/bitcorn/snackbar.h"
#include "qt/bitcorn/forms/ui_snackbar.h"
#include "qt/bitcorn/qtutils.h"
#include <QTimer>


SnackBar::SnackBar(BITCORNGUI* _window, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SnackBar),
    window(_window)
{
    ui->setupUi(this);

    this->setStyleSheet(parent->styleSheet());
    ui->snackContainer->setProperty("cssClass", "container-snackbar");
    ui->label->setProperty("cssClass", "text-snackbar");
    ui->pushButton->setProperty("cssClass", "ic-close");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
    if (window)
        connect(window, SIGNAL(windowResizeEvent(QResizeEvent*)), this, SLOT(windowResizeEvent(QResizeEvent*)));
    else {
        ui->horizontalLayout->setContentsMargins(0,0,0,0);
        ui->label->setStyleSheet("font-size: 15px; color:white;");
    }
}

void SnackBar::windowResizeEvent(QResizeEvent* event){
    this->resize(qobject_cast<QWidget*>(parent())->width(), this->height());
    this->move(QPoint(0, window->height() - this->height() ));
}

void SnackBar::showEvent(QShowEvent *event){
    QTimer::singleShot(3000, this, SLOT(hideAnim()));
}

void SnackBar::hideAnim(){
    if (window) closeDialog(this, window);
    QTimer::singleShot(310, this, SLOT(hide()));
}



void SnackBar::sizeTo(QWidget* widget){

}

void SnackBar::setText(QString text){
    ui->label->setText(text);
}

SnackBar::~SnackBar(){
    delete ui;
}
