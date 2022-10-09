#pragma once

#ifndef Petal_Header_Window_Included
#define Petal_Header_Window_Included

#include <Petal~WindowBase.h>
#include <Petal~MouseEvent.h>
#include <Petal~TimerEvent.h>
#include <Petal~KeyboardEvent.h>

#ifdef CreateWindow
#undef CreateWindow
#endif
#ifdef PostMessage
#undef PostMessage
#endif

rst32 CALLBACK Petal_Function_WindowProcessU(hwin32 hWnd, winuint Msg, wprm32 wParam, lprm32 lParam);
rst32 CALLBACK Petal_Function_WindowProcessA(hwin32 hWnd, winuint Msg, wprm32 wParam, lprm32 lParam);

class Petal_Class_WindowU : public Petal_Class_WindowBaseU
{
	PetalParameters
private:
	ptbool						pt_in_window_set;
	ptbool						pt_is_main_window;

	paintstruct288				pt_paint_struct;

	rect128						pt_remember_window_rect;
	ptbool						pt_fullscreen_on;

	PetalOperations
private:
	virtual ptbool ptf_RegisterWindowSet() final;

protected:
	virtual void BeforeMake();
	virtual void ProcessUserMessage(PCReceivedMessage message);
	virtual void WindowDestroyedEvent();
	virtual void MouseEvent(PCMouseEvent messgae);
	virtual void KeyboardEvent(PCKeyboardEvent keyboard_event);
	virtual void PaintEvent();
	virtual void TimerEvent(PCTimerEvent timer_event);
	virtual void MediaTimerEvent(PCTimerEvent timer_event);

protected:
	virtual void SetMainWindow(ptbool yes = true) final;
	virtual ptbool MakeWindow() final;
	virtual void PostMessage(PCWindowUP target_window, winuint message_code, wprm32 wParam, lprm32 lParam) final;
	virtual void PostMessage(PCWindowAP target_window, winuint message_code, wprm32 wParam, lprm32 lParam) final;
	virtual void PostMessage(hwin32 target_window, winuint message_code, wprm32 wParam, lprm32 lParam) final;
	virtual void PostUserMessage(PCWindowUP target_window, int16 user_message, wprm32 wParam, lprm32 lParam) final;
	virtual void PostUserMessage(PCWindowAP target_window, int16 user_message, wprm32 wParam, lprm32 lParam) final;
	virtual void PostUserMessage(hwin32 target_window, int16 user_message, wprm32 wParam, lprm32 lParam) final;

public:
	virtual hwin32 WindowHandle() final;
	virtual ptbool show(winuint show_method = sw_show) final;
	virtual void Show(winuint show_method = sw_show) final;
	virtual void Hide() final;
	virtual void ShowNormal() final;
	virtual void ShowMaximize() final;
	virtual void ShowMinimize() final;
	virtual void ShowFullScreen() final;
	virtual void QuitFullScreen() final;
	virtual rect128 ClientRect() final;
	virtual void SetParent(hwin32 parent_window) final;
	virtual void SetParent(PCWindowUP parent_window) final;
	virtual void SetParent(PCWindowAP parent_window) final;
	virtual void RePaint(winuint flags = RDW_INVALIDATE | RDW_UPDATENOW) final;
	virtual void MoveWindow(pos64 position) final;
	virtual void MoveWindow(cppint x, cppint y) final;
	virtual void SetWindowTitle(ptcustr title) final;
	virtual void Resize(size2d64 size) final;
	virtual void Resize(cppint width, cppint height) final;
	virtual size2d64 GetSystemResolution() final;
	virtual size2d64 GetScreenResolution() final;
	virtual float32 GetSystemScale() final;
	virtual int32 ChangeResolution(size2d64 size) final;
	virtual int32 ChangeResolution(cppint width, cppint height) final;

public:
	Petal_Class_WindowU(hwin32 parent_window = NULL);
	Petal_Class_WindowU(PCWindowUP parent_window);
	Petal_Class_WindowU(PCWindowAP parent_window);
	virtual ~Petal_Class_WindowU();
	friend rst32				CALLBACK Petal_Function_WindowProcessU(hwin32 hWnd, winuint Msg, wprm32 wParam, lprm32 lParam);
	friend void					CALLBACK Petal_Function_TimerProcess(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
	friend class				Petal_Class_WindowSetU;
	friend class				Petal_Class_PaintDevice;
	friend class				Petal_Class_WindowA;
	friend class				Petal_Class_Timer;
};

class Petal_Class_WindowA : public Petal_Class_WindowBaseA
{
	PetalParameters
private:
	ptbool						pt_in_window_set;
	ptbool						pt_is_main_window;

	paintstruct288				pt_paint_struct;

	rect128						pt_remember_window_rect;
	ptbool						pt_fullscreen_on;

	PetalOperations
private:
	virtual ptbool ptf_RegisterWindowSet() final;

protected:
	virtual void BeforeMake();
	virtual void ProcessUserMessage(PCReceivedMessage message);
	virtual void WindowDestroyedEvent();
	virtual void MouseEvent(PCMouseEvent messgae);
	virtual void KeyboardEvent(PCKeyboardEvent keyboard_event);
	virtual void PaintEvent();
	virtual void TimerEvent(PCTimerEvent timer_event);
	virtual void MediaTimerEvent(PCTimerEvent timer_event);

protected:
	virtual void SetMainWindow(ptbool yes = true) final;
	virtual ptbool MakeWindow() final;
	virtual void PostMessage(PCWindowUP target_window, winuint message_code, wprm32 wParam, lprm32 lParam) final;
	virtual void PostMessage(PCWindowAP target_window, winuint message_code, wprm32 wParam, lprm32 lParam) final;
	virtual void PostMessage(hwin32 target_window, winuint message_code, wprm32 wParam, lprm32 lParam) final;
	virtual void PostUserMessage(PCWindowUP target_window, int16 user_message, wprm32 wParam, lprm32 lParam) final;
	virtual void PostUserMessage(PCWindowAP target_window, int16 user_message, wprm32 wParam, lprm32 lParam) final;
	virtual void PostUserMessage(hwin32 target_window, int16 user_message, wprm32 wParam, lprm32 lParam) final;

public:
	virtual hwin32 WindowHandle() final;
	virtual ptbool show(winuint show_method = sw_show) final;
	virtual void Show(winuint show_method = sw_show) final;
	virtual void Hide() final;
	virtual void ShowNormal() final;
	virtual void ShowMaximize() final;
	virtual void ShowMinimize() final;
	virtual void ShowFullScreen() final;
	virtual void QuitFullScreen() final;
	virtual rect128 ClientRect() final;
	virtual void SetParent(hwin32 parent_window) final;
	virtual void SetParent(PCWindowUP parent_window) final;
	virtual void SetParent(PCWindowAP parent_window) final;
	virtual void RePaint(winuint flags = RDW_INVALIDATE | RDW_UPDATENOW) final;
	virtual void MoveWindow(pos64 position) final;
	virtual void MoveWindow(cppint x, cppint y) final;
	virtual void SetWindowTitle(ptcastr title) final;
	virtual void Resize(size2d64 size) final;
	virtual void Resize(cppint width, cppint height) final;
	virtual size2d64 GetSystemResolution() final;
	virtual size2d64 GetScreenResolution() final;
	virtual float32 GetSystemScale() final;
	virtual int32 ChangeResolution(size2d64 size) final;
	virtual int32 ChangeResolution(cppint width, cppint height) final;

public:
	Petal_Class_WindowA(hwin32 parent_window = NULL);
	Petal_Class_WindowA(PCWindowUP parent_window);
	Petal_Class_WindowA(PCWindowAP parent_window);
	virtual ~Petal_Class_WindowA();
	friend rst32				CALLBACK Petal_Function_WindowProcessA(hwin32 hWnd, winuint Msg, wprm32 wParam, lprm32 lParam);
	friend void					CALLBACK Petal_Function_TimerProcess(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
	friend class				Petal_Class_WindowSetA;
	friend class				Petal_Class_PaintDevice;
	friend class				Petal_Class_WindowU;
	friend class				Petal_Class_Timer;
};

class Petal_Class_WindowSetU : public PCBase
{
	PCWindowUP* pt_windows;
	ptuint			pt_count;

public:
	ptbool Petal_Function_PushBack(PCWindowUP window);
	ptbool Petal_Function_Erase(PCWindowUP window);
	ptuint Petal_Function_Find(PCWindowUP window);
	PCWindowUP Petal_Function_SameHwin(hwin32 hwin);

public:
	Petal_Class_WindowSetU();
	~Petal_Class_WindowSetU();
	friend class	Petal_Class_WindowU;
	friend rst32	CALLBACK Petal_Function_WindowProcessU(hwin32 hWnd, winuint Msg, wprm32 wParam, lprm32 lParam);
};

class Petal_Class_WindowSetA : public PCBase
{
	PCWindowAP* pt_windows;
	ptuint			pt_count;

public:
	ptbool Petal_Function_PushBack(PCWindowAP window);
	ptbool Petal_Function_Erase(PCWindowAP window);
	ptuint Petal_Function_Find(PCWindowAP window);
	PCWindowAP Petal_Function_SameHwin(hwin32 hwin);

public:
	Petal_Class_WindowSetA();
	~Petal_Class_WindowSetA();
	friend rst32	CALLBACK Petal_Function_WindowProcessA(hwin32 hWnd, winuint Msg, wprm32 wParam, lprm32 lParam);
	friend class	Petal_Class_WindowA;
};

#pragma comment(lib, "Petal~Window.lib")
#endif