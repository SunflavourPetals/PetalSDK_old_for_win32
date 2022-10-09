#pragma once

#ifndef Petal_Header_MouseEvent_Included
#define Petal_Header_MouseEvent_Included

#include <Petal~Types.h>

class Petal_Class_MouseEvent : public PCBase
{
	hwin32 pt_window_handle;
	winuint pt_message;
	wprm32 pt_word;
	lprm32 pt_long;
	pos64 pt_position;
public:
	Petal_Class_MouseEvent(hwin32 window_handle = NULL, winuint message = 0, wprm32 word_param = 0, lprm32 long_param = 0);
	~Petal_Class_MouseEvent();
	ptvoid SetParameters(hwin32 window_handle, winuint message, wprm32 word_param, lprm32 long_param);
	hwin32 WindowHandle();
	winuint Message();
	wprm32 WordParam();
	lprm32 LongParam();

	ptbool WithLeft();
	ptbool WithRight();
	ptbool WithMiddle();
	ptbool WithShift();
	ptbool WithCtrl();
	ptbool WithX1();
	ptbool WithX2();
	ptbool WithX();
	ptbool WithXX();
	ptbool DoubleClickedX1();
	ptbool DoubleClickedX2();
	ptbool DoubleClickedX();
	ptbool DoubleClickedXX();
	pos64 Position();
};

#pragma comment(lib, "Petal~MouseEvent.lib")
#endif