#ifndef ICD_H
#define ICD_H

#pragma pack(1)

#include <QString>

typedef struct ButtonClickEvent_t
{
    int buttonId;      /*按键号*/
    int hour;          //时间戳-时
    int minute;        //时间戳-分
    int second;        //时间戳-秒
    int millisecond;   //时间戳-毫秒
    int status;        //控件状态 0-隐藏 1-显示
}ButtonClickEvent;

#pragma pack()

#endif // ICD_H
