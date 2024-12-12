#ifndef ICD_H
#define ICD_H

#pragma pack(1)

#include <QString>

typedef struct ButtonClickEvent_t
{
    int buttonId;      /*������*/
    int hour;          //ʱ���-ʱ
    int minute;        //ʱ���-��
    int second;        //ʱ���-��
    int millisecond;   //ʱ���-����
    int status;        //�ؼ�״̬ 0-���� 1-��ʾ
}ButtonClickEvent;

#pragma pack()

#endif // ICD_H
