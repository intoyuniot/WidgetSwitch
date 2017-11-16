/*
************************************************************************
* 作者:  IntoRobot Team 
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
开关：开关控制

所需器件:

*/

#include <WidgetSwitch.h>

#define    SWITCH_PIN    D0 //定义开关控制引脚

WidgetSwitch switchCtrl = WidgetSwitch();

void switchCb(void)
{
	if(switchCtrl.getSwitch())
	{
		switchCtrl.control(SWITCH_PIN,1);// 打开开关
	}
	else
	{
		switchCtrl.control(SWITCH_PIN,0);// 关闭开关
	}
}

void setup()
{
	//接收开关控制命令
	switchCtrl.begin(switchCb);
}

void loop()
{
}
