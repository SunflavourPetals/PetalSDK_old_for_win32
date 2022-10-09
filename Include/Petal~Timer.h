#pragma once

#ifndef Petal_Header_Timer_Included
#define Petal_Header_Timer_Included

#include <Petal~Window.h>
#include <mmsystem.h>

ptbool KillTimer(PCWindowUP window, winuint timer_ID);
ptbool KillTimer(PCWindowAP window, winuint timer_ID);

class Petal_Class_Timer : public PCBase
{
	enum { default_timer_id = 0, default_timer_elapse = 0 };
	hwin32 pt_window_handle;
	winuint pt_id;
	winuint pt_elapse;
	timerprc32 pt_timer_process;
	winuint pt_kill_id;
	ptbool pt_started;
public:
	Petal_Class_Timer(hwin32 window_handle = NULL, winuint timer_id = default_timer_id);
	Petal_Class_Timer(PCWindowUP window_handle, winuint timer_id = default_timer_id);
	Petal_Class_Timer(PCWindowAP window_handle, winuint timer_id = default_timer_id);
	~Petal_Class_Timer();

	ptvoid SetWindowHandle(hwin32 window_handle);
	ptvoid SetID(winuint id);
	ptvoid SetElapse(winuint elapse);
	ptvoid SetTimerProcess(timerprc32 timer_process);

	winuint Start(winuint ms = default_timer_elapse);
	ptbool Die();

	winuint ID();
	winuint Elapse();
	hwin32 WindowHandle();
	timerprc32 TimerProcess();
	winuint IDForKiller();
};

void CALLBACK Petal_Function_TimerProcess(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

ptbool KillMediaTimer(winuint killerID);

class Petal_Class_MediaTimer : public PCBase
{
	enum { default_timer_delay = 0, default_timer_resolution = 0, mode_oneshot = TIME_ONESHOT, mode_periodic = TIME_PERIODIC };
	winuint pt_delay;
	winuint pt_resolution;
	hwin32 pt_window_handle;
	mmrst32 pt_timer_id;
	winuint pt_shot_mode;
public:
	Petal_Class_MediaTimer(hwin32 window_handle = NULL, winuint delay = default_timer_delay, winuint resolution = default_timer_resolution, ptbool shot_once = no);
	Petal_Class_MediaTimer(PCWindowUP window_handle, winuint delay = default_timer_delay, winuint resolution = default_timer_resolution, ptbool shot_once = no);
	Petal_Class_MediaTimer(PCWindowAP window_handle, winuint delay = default_timer_delay, winuint resolution = default_timer_resolution, ptbool shot_once = no);
	~Petal_Class_MediaTimer();

	ptvoid SetWindowHandle(hwin32 window_handle);
	ptvoid SetDelay(winuint delay_ms);
	ptvoid SetResolution(winuint resolution);
	ptvoid SetShotOnceMode(ptbool shot_once = yes);
	ptvoid SetShotEveryMode(ptbool shot_every = yes);

	winuint Start(winuint ms = default_timer_delay);
	ptbool Die();

	winuint ID();
	winuint Delay();
	winuint Resolution();
	winuint ShotMode();
	hwin32 WindowHandle();
	winuint IDForKiller();
};

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Petal~Timer.lib")
#endif