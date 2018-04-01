#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include"tts.h"
#include"Robotmove.hpp"
#include<iostream>
int main()
{

	m_Comm1.openport(L"COM3", 115200);
	Sleep(100);
	light(0x01);
	Sleep(500);
	char* login_params = "appid = 59c066c4, work_dir = .";
	MSPLogin(NULL, NULL, login_params);
	tts("您好,我是服务机器人小周，现在我给您展示一下我的基本动作，献丑了。");
	mciSendString(L"open 1.wma Alias DebuggingMusic", NULL, 0, NULL);
	mciSendString(L"play DebuggingMusic", NULL, 0, NULL);
	Sleep(6000);
	arm_motion(0x0b);
	Sleep(10000);
	Sleep(5500);
	arm_motion(0x0c);

	Sleep(10000);
	Sleep(9000);

	Sleep(1000);
	arm_motion(0x0b);
	Sleep(10000);
	Sleep(5500);
	arm_motion(0x0c);
	Sleep(10000);
	Sleep(9000);

	mciSendString(L"pause DebuggingMusic", NULL, 0, NULL);
	mciSendString(L"close DebuggingMusic", NULL, 0, NULL);

	Sleep(1000);
	tts("谢谢");
	arm_motion(0x06);
	Sleep(6000);
	light(0x02);
	Sleep(200);
	
	m_Comm1.~Comm();
	//std::cout << 1;
}