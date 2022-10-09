#pragma once

#ifndef Petal_Header_KeyboardEvent_Included
#define Petal_Header_KeyboardEvent_Included

#include <Petal~Define.h>

class Petal_Class_KeyboardEvent : public PCBase
{
	hwin32 pt_window_handle;
	winuint pt_message;
	wprm32 pt_word_param;
	lprm32 pt_long_param;
	ptbool pt_use_unicode;
	union charactor
	{
		char8 pt_ANSI;
		char16 pt_Unicode;
		word16 pt_virtual_key;
	} pt_charactor;

public:
	Petal_Class_KeyboardEvent(hwin32 window_handle = NULL, winuint message = 0, wprm32 word_param = 0, lprm32 long_param = 0, ptbool unicode_char = Petal_Define_UseUnicode);
	~Petal_Class_KeyboardEvent();

	ptvoid SetParameters(hwin32 window_handle, winuint message, wprm32 word_param, lprm32 long_param, ptbool unicode_char = Petal_Define_UseUnicode);

	hwin32 WindowHandle();
	winuint Message();
	wprm32 WordParam();
	lprm32 LongParam();
	word16 VirtualKey();
	ptbool UseUnicode();
	char16 CharUnicode();
	char8 CharANSI();

	word16 ScanCode();
	ptbool ExtendedKeyFlag();
	ptbool PrevKeyStateFlag();
	word16 RepeatCount();
	ptbool TransitionStateFlag();
	ptbool DialogMode();
	ptbool MenuMode();
	ptbool AltDown();
};

#pragma comment(lib, "Petal~KeyboardEvent.lib")
#endif