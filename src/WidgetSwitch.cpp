
#include "WidgetSwitch.h"


WidgetSwitch::WidgetSwitch(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));  
    sprintf(pCmdSwitchTopic,"channel/switch_%d/cmd/switch",_Item); 
}

WidgetSwitch::~WidgetSwitch()
{
}

void WidgetSwitch::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

void WidgetSwitch::control(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    digitalWrite(ucPin, ucVal);
}

char WidgetSwitch::getSwitch(void)
{
    return _switchKey;
}

void WidgetSwitch::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(payload[0] == '1')
    {
        _switchKey = ON;
    }
    else
    {
        _switchKey = OFF;
    }
    _EventCb();
}




