#ifndef SCREENIMPORTITEM_H
#define SCREENIMPORTITEM_H

#include <QWidget>
#include "coordinatedialog.h"
namespace Ui {
class ScreenImportItem;
}

class ScreenImportItem : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenImportItem(QWidget *parent = nullptr);
    ~ScreenImportItem();
    void setScreenPath(QString name);
    QString ScreenPath();
    int GetX();
    int GetY();
    void setX(int x);
    void setY(int y);
    void setCoordinate_X_Y(int x,int y);


public slots:

private slots:
    void on_SetPosition_btn_clicked();

    void on_CloseExe_btn__clicked();

    void on_delete_btn_clicked();

private:
    Ui::ScreenImportItem *ui;
    CoordinateDialog* m_CoordinateDialog;
    int pos_X;
    int pos_Y;
signals:
    void closeExe();
};

#endif // SCREENIMPORTITEM_H
