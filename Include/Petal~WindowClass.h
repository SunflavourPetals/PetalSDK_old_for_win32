#pragma once

#ifndef Petal_Header_WindowClass_Included
#define Petal_Header_WindowClass_Included

#include <Petal~Define.h>

class Petal_Class_WindowClassU : public PCBase
{
public:
    typedef struct Petal_Class_WindowClassDesc
    {
        winuint				pt_class_size;
        winuint				pt_class_style;
        winprc32			pt_function_window_process;
        cppint				pt_class_extra_bytes;
        cppint				pt_window_extra_bytes;
        hins32				pt_handle_instance;
        hicon32				pt_handle_icon;
        hcursor32			pt_handle_cursor;
        hbrush32			pt_handle_brush_background;
        ptcustr				pt_custr_menu_name;
        ptcustr				pt_custr_class_name;
        hicon32				pt_handle_icon_sm;
    } PCWindowClassDesc;

    PetalParameters
protected:
    PCWindowClassDesc		pt_window_class_desc;
    ptbool					pt_window_class_registered;
    ptbool                  pt_use_default_class_name;

    PetalOperations
protected:
    virtual word16			BeforeMake_RegisterWindowClass() final;

    virtual Petal_Class_WindowClassDesc BeforeMake_WindowClass() final;
    virtual winuint         BeforeMake_ClassStyle() final;
    virtual void            BeforeMake_SetClassStyle(winuint style) final;
    virtual void            BeforeMake_AddClassStyle(winuint style) final;
    virtual void            BeforeMake_RemoveClassStyle(winuint style) final;
    virtual cppint          BeforeMake_ClassExtraBytes() final;
    virtual void            BeforeMake_SetClassExtraBytes(cppint bytes_count) final;
    virtual cppint          BeforeMake_WindowExtraBytes() final;
    virtual void            BeforeMake_SetWindowExtraBytes(cppint bytes_count) final;
    virtual hicon32         BeforeMake_Icon() final;
    virtual void            BeforeMake_SetIcon(hicon32 icon_handle) final;
    virtual hcursor32       BeforeMake_Cursor() final;
    virtual void            BeforeMake_SetCursor(hcursor32 cursor_handle) final;
    virtual hbrush32        BeforeMake_BackgroundBrush() final;
    virtual void            BeforeMake_SetBackground(hbrush32 background_brush_handle) final;
    virtual cppint          BeforeMake_MenuNameSize() final;
    virtual ptustr          BeforeMake_MenuName(ptustr name, cppint string_size) final;
    virtual void            BeforeMake_SetMenuName(ptcustr menu_name) final;
    virtual cppint          BeforeMake_ClassNameSize() final;
    virtual ptustr          BeforeMake_ClassName(ptustr name, cppint string_size) final;
    virtual void            BeforeMake_SetClassName(ptcustr class_name) final;
    virtual hicon32         BeforeMake_IconSm() final;
    virtual void            BeforeMake_SetIconSm(hicon32 icon_handle) final;
    virtual void            BeforeMake_UseDefaultClassName() final;
    virtual void            BeforeMake_UseDefaultWindowClass() final;
public:
    Petal_Class_WindowClassU();
    virtual ~Petal_Class_WindowClassU();
};

class Petal_Class_WindowClassA : public PCBase
{
public:
    typedef struct Petal_Class_WindowClassDesc
    {
        winuint				pt_class_size;
        winuint				pt_class_style;
        winprc32			pt_function_window_process;
        cppint				pt_class_extra_bytes;
        cppint				pt_window_extra_bytes;
        hins32				pt_handle_instance;
        hicon32				pt_handle_icon;
        hcursor32			pt_handle_cursor;
        hbrush32			pt_handle_brush_background;
        ptcastr				pt_castr_menu_name;
        ptcastr				pt_castr_class_name;
        hicon32				pt_handle_icon_sm;
    } PCWindowClassDesc;

    PetalParameters
protected:
    PCWindowClassDesc		pt_window_class_desc;
    ptbool					pt_window_class_registered;
    ptbool                  pt_use_default_class_name;

    PetalOperations
protected:
    virtual word16			BeforeMake_RegisterWindowClass() final;

    virtual Petal_Class_WindowClassDesc BeforeMake_WindowClass() final;
    virtual winuint         BeforeMake_ClassStyle() final;
    virtual void            BeforeMake_SetClassStyle(winuint style) final;
    virtual void            BeforeMake_AddClassStyle(winuint style) final;
    virtual void            BeforeMake_RemoveClassStyle(winuint style) final;
    virtual cppint          BeforeMake_ClassExtraBytes() final;
    virtual void            BeforeMake_SetClassExtraBytes(cppint bytes_count) final;
    virtual cppint          BeforeMake_WindowExtraBytes() final;
    virtual void            BeforeMake_SetWindowExtraBytes(cppint bytes_count) final;
    virtual hicon32         BeforeMake_Icon() final;
    virtual void            BeforeMake_SetIcon(hicon32 icon_handle) final;
    virtual hcursor32       BeforeMake_Cursor() final;
    virtual void            BeforeMake_SetCursor(hcursor32 cursor_handle) final;
    virtual hbrush32        BeforeMake_BackgroundBrush() final;
    virtual void            BeforeMake_SetBackground(hbrush32 background_brush_handle) final;
    virtual cppint          BeforeMake_MenuNameSize() final;
    virtual ptastr          BeforeMake_MenuName(ptastr name, cppint string_size) final;
    virtual void            BeforeMake_SetMenuName(ptcastr menu_name) final;
    virtual cppint          BeforeMake_ClassNameSize() final;
    virtual ptastr          BeforeMake_ClassName(ptastr name, cppint string_size) final;
    virtual void            BeforeMake_SetClassName(ptcastr class_name) final;
    virtual hicon32         BeforeMake_IconSm() final;
    virtual void            BeforeMake_SetIconSm(hicon32 icon_handle) final;
    virtual void            BeforeMake_UseDefaultClassName() final;
    virtual void            BeforeMake_UseDefaultWindowClass() final;
public:
    Petal_Class_WindowClassA();
    virtual ~Petal_Class_WindowClassA();
};

#pragma comment(lib, "Petal~WindowClass.lib")
#endif