#include "eventitem.h"
#include "ui_eventitem.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "eventchilditem.h"

//任务下的事件列表
EventItem::EventItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EventItem)
{
    ui->setupUi(this);
    static int i=0;

    connect(this, &EventItem::getTriggerTime, this, [=](){
        for(int i=0; i<ui->eventItemLayout->count(); i++)
        {
            QLayoutItem* item = ui->eventItemLayout->itemAt(i);
            if (!item) continue;

            QWidget* widget = item->widget();
            if (widget)
            {
                EventChildItem* eventChildItem = qobject_cast<EventChildItem*>(widget);
                if (eventChildItem) {
                    if(i==0)
                    {
                        setTimeString(eventChildItem->getTime());
                    }
                    i++;
                }
            }
        }
    });



}

EventItem::~EventItem()
{
    delete ui;
}

void EventItem::on_add_child_clicked()
{

    EventChildItem *item = new EventChildItem(this);
    connect(item, &EventChildItem::requestDeletion, this, [item](){
        item->deleteLater();
    });

    ui->eventItemLayout->addWidget(item);

}

void EventItem::on_delete_child_clicked()
{
   // if(ui->eventItemLayout->count() > 0)
   // {
   //     QLayoutItem* item = ui->eventItemLayout->takeAt(ui->eventItemLayout->count() - 1);
   //     if (QWidget* widget = item->widget()) {
   //         widget->deleteLater();
   //     }
   //     delete item;
   // }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "确认删除", "您确定要删除这个事件吗？",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 用户选择了“是”，在这里执行删除操作
        // ...
        emit requestDeletion();
    
    } else {
        // 用户选择了“否”，取消删除操作
    }





}

void EventItem::set_task_event(QString task_event)
{
    ui->task_event->setText(task_event);
}

QString EventItem::task_event()
{
    return ui->task_event->text();
}

void EventItem::set_trigger_event(QString trigger_event)
{
    QStringList trigger_event_list = trigger_event.split('-');
    for(int i=0; i<trigger_event_list.size(); i++)
    {
        EventChildItem *eventChildItem = new EventChildItem;
        if(i!=0)
        {
            eventChildItem->setItemReadonly();
        }
        eventChildItem->set_trigger_event(trigger_event_list.at(i).toInt());

        ui->eventItemLayout->addWidget(eventChildItem);
    }
}

QString EventItem::trigger_event()
{
    QStringList trigger_event_list;
    for(int i=0; i<ui->eventItemLayout->count(); i++)
    {
        QLayoutItem* item = ui->eventItemLayout->itemAt(i);
        if (!item) continue;

        QWidget* widget = item->widget();
        if (widget)
        {
            EventChildItem* eventChildItem = qobject_cast<EventChildItem*>(widget);
            if (eventChildItem) {
                trigger_event_list << QString::number(eventChildItem->trigger_event());
            }
        }
    }
    return trigger_event_list.join('-');
}

QString EventItem::getTime()
{
    return this->TimeString;
}

void EventItem::setTimeString(QString str)
{
    this->TimeString=str;
}
