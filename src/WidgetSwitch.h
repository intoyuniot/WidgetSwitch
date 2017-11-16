#ifndef WIDGET_SWITCH_H_
#define WIDGET_SWITCH_H_

#include "application.h"


class WidgetSwitch: public WidgetBaseClass
{
public:
    WidgetSwitch(uint8_t ucItem = 0);
    ~WidgetSwitch();
    void begin(void (*UserCallBack)(void) = NULL);
    char getSwitch(void);
    void control(uint8_t ucPin, uint8_t ucVal);
    
private:
    char pCmdSwitchTopic[64];
    uint8_t _switchKey = 0;
    uint8_t _Item=0;         
    void (*_EventCb)(void);
    void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
