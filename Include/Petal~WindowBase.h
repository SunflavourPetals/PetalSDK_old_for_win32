#pragma once

#ifndef Petal_Header_WindowBase_Included
#define Petal_Header_WindowBase_Included

#include <Petal~WindowClass.h>

class Petal_Class_WindowBaseU : public Petal_Class_WindowClassU
{
public:
	typedef struct Petal_Class_WindowDesc
	{
		dword32			pt_extended_window_style;
		ptcustr			pt_custr_window_name;
		dword32			pt_window_style;
		winint			pt_x;
		winint			pt_y;
		winint			pt_width;
		winint			pt_height;
		hwin32			pt_handle_parent_window;
		hmenu32			pt_handle_menu;
		void_ptr32		pt_long_pointer_parameter;
	} PCWindowDesc;

	PetalParameters
protected:
	PCWindowDesc		pt_window_desc;
	hwin32				pt_window_handle;
	ptbool				pt_window_created;

	PetalOperations
protected:
	virtual hwin32		BeforeMake_CreateWindow() final;

	virtual dword32		BeforeMake_ExtendedWindowStyle() final;
	virtual void		BeforeMake_SetExtendedWindowStyle(dword32 style) final;
	virtual cppint		BeforeMake_WindowNameSize() final;
	virtual ptustr		BeforeMake_WindowName(ptustr name, cppint string_size);
	virtual void		BeforeMake_SetWindowName(ptcustr window_name) final;
	virtual dword32		BeforeMake_WindowStyle() final;
	virtual void		BeforeMake_SetWindowStyle(dword32 style) final;
	virtual pos64		BeforeMake_WindowPosition() final;
	virtual rect128		BeforeMake_WindowRect() final;
	virtual void		BeforeMake_SetWindowPosition(pos64 position) final;
	virtual void		BeforeMake_SetWindowPosition(int32 x, int32 y) final;
	virtual void		BeforeMake_SetWindowPosition(rect128 rect) final;
	virtual void		SetWindowPosition(pos64 left_top, pos64 right_bottom) final;
	virtual void		BeforeMake_SetWindowPosition(int32 left, int32 top, int32 right, int32 bottom) final;
	virtual size2d64	BeforeMake_WindowSize() final;
	virtual void		BeforeMake_SetWindowSize(size2d64 size) final;
	virtual void		BeforeMake_SetWindowSize(int32 width, int32 height) final;
	virtual hwin32		BeforeMake_Parent() final;
	virtual void		BeforeMake_SetParent(hwin32 parent);
	virtual hmenu32		BeforeMake_Menu() final;
	virtual void		BeforeMake_SetMenuHandle(hmenu32 menu_handle) final;
	virtual void_ptr32	BeforeMake_LPParameter() final;
	virtual void		BeforeMake_SetLPParam(void_ptr32 lpParam) final;
	virtual void		BeforeMake_UseDefaultWindowDesc() final;
public:
	Petal_Class_WindowBaseU(hwin32 parent_window = NULL);
	virtual ~Petal_Class_WindowBaseU();
};

class Petal_Class_WindowBaseA : public Petal_Class_WindowClassA
{
public:
	typedef struct Petal_Class_WindowDesc
	{
		dword32			pt_extended_window_style;
		ptcastr			pt_castr_window_name;
		dword32			pt_window_style;
		winint			pt_x;
		winint			pt_y;
		winint			pt_width;
		winint			pt_height;
		hwin32			pt_handle_parent_window;
		hmenu32			pt_handle_menu;
		void_ptr32		pt_long_pointer_parameter;
	} PCWindowDesc;

	PetalParameters
protected:
	PCWindowDesc		pt_window_desc;
	hwin32				pt_window_handle;
	ptbool				pt_window_created;

	PetalOperations
protected:
	virtual hwin32		BeforeMake_CreateWindow() final;

	virtual dword32		BeforeMake_ExtendedWindowStyle() final;
	virtual void		BeforeMake_SetExtendedWindowStyle(dword32 style) final;
	virtual cppint		BeforeMake_WindowNameSize() final;
	virtual ptastr		BeforeMake_WindowName(ptastr name, cppint string_size);
	virtual void		BeforeMake_SetWindowName(ptcastr window_name) final;
	virtual dword32		BeforeMake_WindowStyle() final;
	virtual void		BeforeMake_SetWindowStyle(dword32 style) final;
	virtual pos64		BeforeMake_WindowPosition() final;
	virtual rect128		BeforeMake_WindowRect() final;
	virtual void		BeforeMake_SetWindowPosition(pos64 position) final;
	virtual void		BeforeMake_SetWindowPosition(int32 x, int32 y) final;
	virtual void		BeforeMake_SetWindowPosition(rect128 rect) final;
	virtual void		BeforeMake_SetWindowPosition(pos64 left_top, pos64 right_bottom) final;
	virtual void		BeforeMake_SetWindowPosition(int32 left, int32 top, int32 right, int32 bottom) final;
	virtual size2d64	BeforeMake_WindowSize() final;
	virtual void		BeforeMake_SetWindowSize(size2d64 size) final;
	virtual void		BeforeMake_SetWindowSize(int32 width, int32 height) final;
	virtual hwin32		BeforeMake_Parent() final;
	virtual void		BeforeMake_SetParent(hwin32 parent);
	virtual hmenu32		BeforeMake_Menu() final;
	virtual void		BeforeMake_SetMenuHandle(hmenu32 menu_handle) final;
	virtual void_ptr32	BeforeMake_LPParameter() final;
	virtual void		BeforeMake_SetLPParam(void_ptr32 lpParam) final;
	virtual void		BeforeMake_UseDefaultWindowDesc() final;
public:
	Petal_Class_WindowBaseA(hwin32 parent_window = NULL);
	virtual ~Petal_Class_WindowBaseA();
};

#pragma comment(lib, "Petal~WindowBase.lib")
#endif