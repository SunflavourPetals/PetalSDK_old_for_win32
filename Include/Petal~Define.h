#pragma once

#ifndef Petal_Header_Define_Included
#define Petal_Header_Define_Included

// Define Unicode Set Flag
#if defined(_UNICODE)
#define Petal_Define_UseUnicode true
#define Petal_Define_Unicode _UNICODE
#elif defined(UNICODE)
#define Petal_Define_UseUnicode true
#define Petal_Define_Unicode UNICODE
#else
#define Petal_Define_UseUnicode false
#endif

// Define Debug Mode Flag
#if defined(_DEBUG)
#define Petal_Define_DebugMode _DEBUG
#define Petal_Define_Debug _DEBUG
#elif defined(DEBUG)
#define Petal_Define_DebugMode DEBUG
#define Petal_Define_Debug DEBUG
#endif

// Defing Const Text Format
#define Petal_Define_ConstStringUnicode(const_text_string)		L##const_text_string
#define Petal_Define_ConstStringANSI(const_text_string)			const_text_string
#if defined(Petal_Define_Unicode)
#define Petal_Define_ConstString(const_text_string)				L##const_text_string
#else
#define Petal_Define_ConstString(const_text_string)				const_text_string
#endif
#define PDUCSTR(quote)					Petal_Define_ConstStringUnicode(quote)
#define PDACSTR(quote)					Petal_Define_ConstStringANSI(quote)
#define PDCSTR(quote)					Petal_Define_ConstString(quote)
#define ptxtu(quote)					Petal_Define_ConstStringUnicode(quote)
#define ptxta(quote)					Petal_Define_ConstStringANSI(quote)
#define ptxt(quote)						Petal_Define_ConstString(quote)

// Define Default Petal_Class_WindowClass->pt_class_name
#define Petal_Define_ClassNameU			PDUCSTR("Petal~with~Windows")
#define Petal_Define_ClassNameA			PDACSTR("Petal~with~Windows")
#define Petal_Define_ClassName			PDCSTR("Petal~with~Windows")
#define Petal_Define_WindowNameU		PDUCSTR("Petal Window")
#define Petal_Define_WindowNameA		PDACSTR("Petal Window")
#define Petal_Define_WindowName			PDCSTR("Petal Window")

// Define Default Petal_Class_WindowClass->pt_window_process
#define Petal_Function_WindowProcess_DefWindowProcU DefWindowProcW
#define Petal_Function_WindowProcess_DefWindowProcA DefWindowProcA
#if defined(Petal_Define_Unicode)
#define Petal_Function_WindowProcess_DefWindowProc DefWindowProcW
#else
#define Petal_Function_WindowProcess_DefWindowProc DefWindowProcA
#endif

// Define Default Cursor
#define Petal_Function_LoadArrowCursorU	LoadCursorW(NULL, (ptcustr)IDC_ARROW)
#define Petal_Function_LoadArrowCursorA	LoadCursorA(NULL, (ptcastr)IDC_ARROW)
#define Petal_Define_DefaultCursorU		Petal_Function_LoadArrowCursorU
#define Petal_Define_DefaultCursorA		Petal_Function_LoadArrowCursorA
#if defined(Petal_Define_Unicode)
#define Petal_Define_DefaultCursor		Petal_Define_DefaultCursorU
#else
#define Petal_Define_DefaultCursor		Petal_Define_DefaultCursorA
#endif

#include <Petal~Types.h>

// Define Type ( Unicode(wchar) || ANSI(char) )

#if defined(Petal_Define_Unicode)
typedef Petal_TypeDefine_wchar		Petal_TypeDefine_char;
#if defined(_W64)
typedef Petal_TypeDefine_ustr		Petal_TypeDefine_str;
typedef Petal_TypeDefine_custr		Petal_TypeDefine_cstr;
#endif
typedef Petal_Class_WindowClassU	Petal_Class_WindowClass;
typedef Petal_Class_WindowBaseU		Petal_Class_WindowBase;
typedef Petal_Class_WindowSetU		Petal_Class_WindowSet;
typedef Petal_Class_WindowU			Petal_Class_Window;
typedef Petal_Class_MessageLoopU	Petal_Class_MessageLoop;
typedef PCWindowUP					PCWindowP;
#else
typedef Petal_TypeDefine_achar		Petal_TypeDefine_char;
#if defined(_W64)
typedef Petal_TypeDefine_astr		Petal_TypeDefine_str;
typedef Petal_TypeDefine_castr		Petal_TypeDefine_cstr;
#endif
typedef Petal_Class_WindowClassA	Petal_Class_WindowClass;
typedef Petal_Class_WindowBaseA		Petal_Class_WindowBase;
typedef Petal_Class_WindowSetA		Petal_Class_WindowSet;
typedef Petal_Class_WindowA			Petal_Class_Window;
typedef Petal_Class_MessageLoopA	Petal_Class_MessageLoop;
typedef PCWindowAP					PCWindowP;
#endif
typedef Petal_TypeDefine_char		PTchar, ptchar;
#if defined(_W64)
typedef Petal_TypeDefine_str		PTstr,	ptstr;
typedef Petal_TypeDefine_cstr		PTcstr,	ptcstr;
#endif
typedef Petal_Class_WindowClass		PCWindowClass;
typedef Petal_Class_WindowBase		PCWindowBase;
typedef Petal_Class_WindowSet		PCWindowSet;
typedef Petal_Class_Window			PCWindow;
typedef Petal_Class_MessageLoop		PCMessageLoop;

#define PetalParameters
#define PetalFunctions
#define PetalOperations

#endif