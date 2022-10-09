#pragma once
#ifndef Petal_Header_TimerEvent_Included
#define Petal_Header_TimerEvent_Included

#include <Petal~Types.h>

class Petal_Class_TimerEvent : public PCBase
{
	hwin32 pt_window_handle;
	winuint pt_timer_id;
public:
	Petal_Class_TimerEvent(hwin32 window_handle = NULL, winuint id = 0);
	~Petal_Class_TimerEvent();

	ptvoid SetParameters(hwin32 window_handle, winuint id);
	winuint ID();
	hwin32 WindowHandle();
};

#pragma comment(lib, "Petal~TimerEvent.lib")
#endif