// Copyright (c) 2019 The BITCORN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MASTERNODESWIDGET_H
#define MASTERNODESWIDGET_H

#include <QWidget>
#include "qt/bitcorn/pwidget.h"
#include "qt/bitcorn/furabstractlistitemdelegate.h"
#include "qt/bitcorn/mnmodel.h"
#include "qt/bitcorn/tooltipmenu.h"
#include <QTimer>

class BITCORNGUI;

namespace Ui {
class MasterNodesWidget;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class MasterNodesWidget : public PWidget
{
    Q_OBJECT

public:

    explicit MasterNodesWidget(BITCORNGUI *parent = nullptr);
    ~MasterNodesWidget();

    void loadWalletModel() override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private slots:
    void onCreateMNClicked();
    void changeTheme(bool isLightTheme, QString &theme) override;
    void onMNClicked(const QModelIndex &index);
    void onEditMNClicked();
    void onDeleteMNClicked();
    void onInfoMNClicked();
    void updateListState();

private:
    Ui::MasterNodesWidget *ui;
    FurAbstractListItemDelegate *delegate;
    MNModel *mnModel = nullptr;
    TooltipMenu* menu = nullptr;
    QModelIndex index;
    QTimer *timer = nullptr;

    void startAlias(QString strAlias);
};

#endif // MASTERNODESWIDGET_H
