#pragma once

#include <QWidget>

namespace Ui {
class ReplayListItem;
}

class ReplayListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ReplayListItem(QWidget *parent = nullptr);
    ~ReplayListItem();

private slots:
    void on_delete_2_clicked();

private:
    Ui::ReplayListItem *ui;
};
