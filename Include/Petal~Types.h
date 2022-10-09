#pragma once

#ifndef Petal_Header_Types_Included
#define Petal_Header_Types_Included

// Number at end is bits count of this type
// #nt#		meant	# _Null_terminated_ ( from <winnt.h> ) #
// #h#		meant	# handle #
// #c#		meant	# const #
// #u#		meant	# unsigned #
// #_str#	meant	# ( charactor_type ) pointer #
// #_ptr#	meant	# pointer #

typedef void						void0;

// Float Types
typedef float						float32;
typedef double						float64;

// Integer Types
typedef signed int					oint;
typedef signed char					int8;
typedef signed short				int16;
typedef signed long					int32;
typedef signed long long			int64;
typedef unsigned int				ouint;
typedef unsigned char				uint8;
typedef unsigned short				uint16;
typedef unsigned long				uint32;
typedef unsigned long long			uint64;

typedef const signed int			ocint;
typedef const signed char			cint8;
typedef const signed short			cint16;
typedef const signed long			cint32;
typedef const signed long long		cint64;
typedef const unsigned int			ocuint;
typedef const unsigned char			cuint8;
typedef const unsigned short		cuint16;
typedef const unsigned long			cuint32;
typedef const unsigned long long	cuint64;

// Charactor Types
typedef char						char8;
typedef unsigned char				uchar8;
typedef wchar_t						char16;
typedef const char					cchar8;
typedef const unsigned char			cuchar8;
typedef const wchar_t				cchar16;

// Byte Type
typedef unsigned char				byte8;

// Bool Type
typedef char						bool8;
typedef bool						cppbool8;

// String Types
typedef  char8*						char8_ptr;
typedef  char16*					char16_ptr;
typedef  cchar8*					cchar8_ptr;
typedef  cchar16*					cchar16_ptr;
typedef  char8*						char8_str;
typedef  char16*					char16_str;
typedef  cchar8*					cchar8_str;
typedef  cchar16*					cchar16_str;

typedef unsigned __int64			size_win64_64;
typedef unsigned int				size_win32_32;
#ifdef _WIN64
typedef size_win64_64				size_win;
#else
typedef size_win32_32				size_win;
#endif

#include <Windows.h>
//#include <winnt.h>
#if defined(_W64)
// _Null_terminated_ STR Types
typedef LPSTR						ntstr8;
typedef LPWSTR						ntstr16;
typedef LPCSTR						ntcstr8;
typedef LPCWSTR						ntcstr16;

// _W64 Long Result
typedef LRESULT						rst32;
typedef MMRESULT					mmrst32;
typedef void*						void_ptr32;
typedef const void*					cvoid_ptr32;

// _W64 Parameters
typedef WPARAM						wprm32; // #w#	meant	# WORD((unsigned int)16 bits) # but now (in 32 bits CPU) it is 32 bits.
typedef LPARAM						lprm32; // #l#	meant	# long #
#endif

//#include <WinUser.h>
typedef DWORD						dword32;
typedef WORD						word16;
typedef WNDPROC						winprc32;
typedef TIMERPROC					timerprc32;
typedef PAINTSTRUCT					paintstruct288;
typedef LPTIMECALLBACK				mediatimerprc32;

typedef struct Petal_Class_Message256
{
	HWND        hwnd;
	UINT        message;
	WPARAM      wParam;
	LPARAM      lParam;
	DWORD       time;
	POINT       pt;
	DWORD       lPrivate;
} PTMessage256, message256;
typedef struct Petal_Class_Message224
{
	HWND        hwnd;
	UINT        message;
	WPARAM      wParam;
	LPARAM      lParam;
	DWORD       time;
	POINT       pt;
} PTMessage224, message224;
typedef struct Petal_Class_ReceivedMessage
{
	HWND		received_window;
	UINT		message_code;
	WPARAM		wParam;
	LPARAM		lParam;
	POINT		cursor_point;
} PCReceivedMessage;
#ifdef _MAC
typedef Petal_Class_Message256		Petal_Class_Messgae; // hwin32 uint32 wprm32 lprm32 dword32 POINT{int32, int32} dword32
#else
typedef Petal_Class_Message224		Petal_Class_Message; // hwin32 uint32 wprm32 lprm32 dword32 POINT{int32, int32}
#endif

//#include <windef.h>
// Handle Type
typedef void*						handle32;

// Handle Type
#pragma region Application Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
typedef HWND						hwin32;
typedef HHOOK						hhook32;
#endif


#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
#if !defined(_MAC) || !defined(GDI_INTERNAL)
#ifdef STRICT
typedef HGDIOBJ						hgdiobj32;
#else
DECLARE_HANDLE(HGDIOBJ);
typedef HGDIOBJ						hgdiobj32;
#endif
#endif
#if !defined(_MAC) || !defined(WIN_INTERNAL)
typedef HACCEL						haccel32;
#endif
#if !defined(_MAC) || !defined(GDI_INTERNAL)
typedef HBITMAP						hbitmap32;
typedef HBRUSH						hbrush32;
#endif
#if(WINVER >= 0x0400)
typedef HCOLORSPACE					hcolorspace32;
#endif /* WINVER >= 0x0400 */
#if !defined(_MAC) || !defined(GDI_INTERNAL)
typedef HDC							hdc32;
#endif
typedef HGLRC						hglrc32; // OpenGL
typedef HDESK						hdesk32;
typedef HENHMETAFILE				henhmetafile32;
#if !defined(_MAC) || !defined(GDI_INTERNAL)
typedef HFONT						hfont32;
#endif
typedef HICON						hicon32;
typedef HICON						hcursor32;
#if !defined(_MAC) || !defined(WIN_INTERNAL)
typedef HMENU						hmenu32;
#endif
#if !defined(_MAC) || !defined(GDI_INTERNAL)
typedef HPALETTE					hpalette32;
typedef HPEN						hpen32;
#endif
#if(WINVER >= 0x0400)
typedef HWINEVENTHOOK				hwineventhook32;
#endif /* WINVER >= 0x0400 */
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#if(WINVER >= 0x0500)
#ifndef _MAC
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
typedef HMONITOR					hmonitor32;
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#endif
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef HUMPD						humpd32;
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#endif /* WINVER >= 0x0500 */

//#include <minwindef.h>
// Handle Type
typedef HKEY						hkey32;
typedef HMETAFILE					hmetafile32;
typedef HINSTANCE					hins32;
typedef HRGN						hrgn32;
typedef HRSRC						hrsc32;
typedef HSPRITE						hsprite32;
typedef HLSURF						hlsure32;
typedef HSTR						hstr32;
typedef HTASK						htask32;
typedef HWINSTA						hwinsta32;
typedef HKL							hkl32;

typedef struct { int32 left; int32 top; int32 right; int32 bottom; }	rect128;
typedef struct { int32 x; int32 y; }									point64;
typedef point64															position64, pos64;
typedef struct { int32 width; int32 height; }							size2d64;

// Petal Enum

typedef enum Petal_Enum_BoolValue
{
	no = false,
	yes = true,
} PEBoolValve, PEBV, pebv;

// https://docs.microsoft.com/en-us/windows/win32/winmsg/window-class-styles
typedef enum Petal_Enum_ClassStyle
{
	cs_vertical_redraw = CS_VREDRAW,
	cs_vredraw = cs_vertical_redraw,
	cs_horizontal_redraw = CS_HREDRAW,
	cs_hredraw = cs_horizontal_redraw,
	cs_redraw = cs_vredraw | cs_hredraw,
	cs_double_click = CS_DBLCLKS,
	cs_own_dc = CS_OWNDC,
	cs_class_dc = CS_CLASSDC,
	cs_parent_dc = CS_PARENTDC,
	cs_no_closw = CS_NOCLOSE,
	cs_save_bits = CS_SAVEBITS,
	cs_byte_align_client = CS_BYTEALIGNCLIENT,
	cs_byte_align_window = CS_BYTEALIGNWINDOW,
	cs_global_class = CS_GLOBALCLASS,
	cs_drop_shadow = CS_DROPSHADOW
} PEClassStyle, PECS, pecs;

// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showwindow
typedef enum Petal_Enum_ShowWindow
{
	sw_hide = SW_HIDE,
	sw_normal = SW_NORMAL,
	sw_minimized = SW_SHOWMINIMIZED,
	sw_maximized = SW_SHOWMAXIMIZED,
	sw_maximize = sw_maximized,
	sw_show_no_activate = SW_SHOWNOACTIVATE,
	sw_noactivate = sw_show_no_activate,
	sw_show = SW_SHOW,
	sw_minimize = SW_MINIMIZE,
	sw_show_min_no_active = SW_SHOWMINNOACTIVE,
	sw_min_noactivate = sw_show_min_no_active,
	sw_showna = SW_SHOWNA,
	sw_show_na = sw_showna,
	sw_restore = SW_RESTORE,
	sw_show_default = SW_SHOWDEFAULT,
	sw_default = sw_show_default,
	sw_force_minimize = SW_FORCEMINIMIZE
} PEShowWindow, PESW, pesw;

// https://docs.microsoft.com/en-us/windows/win32/winmsg/window-styles
typedef enum Petal_Enum_WindowStyle
{
	ws_active_caption = WS_ACTIVECAPTION,
	ws_overlapped = WS_OVERLAPPED,
	ws_popup = WS_POPUP,
	ws_child = WS_CHILD,
	ws_minimize = WS_MINIMIZE,
	ws_visible = WS_VISIBLE,
	ws_disabled = WS_DISABLED,
	ws_clip_siblings = WS_CLIPSIBLINGS,
	ws_clip_children = WS_CLIPCHILDREN,
	ws_maximize = WS_MAXIMIZE,
	ws_caption = WS_CAPTION, // -> (WS_BORDER | WS_DLGFRAME)
	ws_border = WS_BORDER,
	ws_dlg_frame = WS_DLGFRAME,
	ws_vertical_scroll = WS_VSCROLL,
	ws_vscroll = ws_vertical_scroll,
	ws_horizontal_scroll = WS_HSCROLL,
	ws_hscroll = WS_HSCROLL,
	ws_sys_menu = WS_SYSMENU,
	ws_thick_frame = WS_THICKFRAME,
	ws_group = WS_GROUP,
	ws_tab_stop = WS_TABSTOP,
	ws_minimize_box = WS_MINIMIZEBOX,
	ws_maximize_box = WS_MAXIMIZEBOX,
	// Common Window Styles Start
	ws_overlapped_window = WS_OVERLAPPEDWINDOW, // -> (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
	ws_popup_window = WS_POPUPWINDOW, // -> (WS_POPUP | WS_BORDER | WS_SYSMENU)
	ws_child_window = WS_CHILDWINDOW, // -> (WS_CHILD)
	// Common Window Styles End
	ws_tiled = WS_TILED, // -> WS_OVERLAPPED
	ws_iconic = WS_ICONIC, // -> WS_MINIMIZE
	ws_size_box = WS_SIZEBOX, // -> WS_THICKFRAME
	ws_tiled_window = WS_TILEDWINDOW, // -> WS_OVERLAPPEDWINDOW
} PEWindowStyle, PEWS, pews;

// https://docs.microsoft.com/en-us/windows/win32/winmsg/extended-window-styles
typedef enum Petal_Enum_ExtendedWindowStyle
{
	ews_dlg_modal_frame = WS_EX_DLGMODALFRAME,
	ews_no_parent_notify = WS_EX_NOPARENTNOTIFY,
	ews_top_most = WS_EX_TOPMOST,
	ews_accept_files = WS_EX_ACCEPTFILES,
	ews_transparent = WS_EX_TRANSPARENT
#if(WINVER >= 0x0400)
	,
	ews_mdi_child = WS_EX_MDICHILD,
	ews_tool_window = WS_EX_TOOLWINDOW,
	ews_window_edge = WS_EX_WINDOWEDGE,
	ews_client_edge = WS_EX_CLIENTEDGE,
	ews_context_help = WS_EX_CONTEXTHELP,
	ews_left = WS_EX_LEFT, // it is default param (0)
	ews_right = WS_EX_RIGHT,
	ews_ltr_reading = WS_EX_LTRREADING, // it is default param (0) // ltr (left to right)
	ews_rtl_reading = WS_EX_RTLREADING, // rtl (right to left)
	ews_letf_to_right_reading = ews_ltr_reading,
	ews_right_to_letf_reading = ews_rtl_reading,
	ews_left_scroll_bar = WS_EX_LEFTSCROLLBAR,
	ews_right_scroll_bar = WS_EX_RIGHTSCROLLBAR, // it is default param (0)
	ews_control_parent = WS_EX_CONTROLPARENT,
	ews_static_edge = WS_EX_STATICEDGE,
	ews_appwindow = WS_EX_APPWINDOW,
	ews_overlapped_window = WS_EX_OVERLAPPEDWINDOW,
	ews_palette_window = WS_EX_PALETTEWINDOW
#endif
#if(_WIN32_WINNT >= 0x0500)
	,
	ews_layered = WS_EX_LAYERED,
	ews_no_inherit_layout = WS_EX_NOINHERITLAYOUT,
	ews_layout_rtl = WS_EX_LAYOUTRTL,
	ews_no_activate = WS_EX_NOACTIVATE
#endif
#if(_WIN32_WINNT >= 0x0501)
	,
	ews_composited = WS_EX_COMPOSITED
#endif
#if(WINVER >= 0x0602)
	,
	ews_no_redirection_bitmap = WS_EX_NOREDIRECTIONBITMAP
#endif
} PEExtendedWindowStyle, PEExWindowStyle, PEEXWS, PEEWS, peexws, peews;

// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-drawtext
typedef enum Petal_Enum_DrawTextFormat
{
	dtf_top = DT_TOP,
	dtf_left = DT_LEFT,
	dtf_right = DT_RIGHT,
	dtf_line_center = DT_CENTER,
	dtf_virticle_center = DT_VCENTER | DT_SINGLELINE,
	dtf_center = DT_CENTER | DT_VCENTER | DT_SINGLELINE,
	dtf_bottom = DT_BOTTOM | DT_SINGLELINE,
	dtf_word_break = DT_WORDBREAK,
	dtf_single_line = DT_SINGLELINE,
	dtf_expand_tabs = DT_EXPANDTABS,
	dtf_tabstop = DT_TABSTOP,
	dtf_noclip = DT_NOCLIP,
	dtf_extern_alleading = DT_EXTERNALLEADING,
	dtf_calcrect = DT_CALCRECT,
	dtf_noprefix = DT_NOPREFIX,
	dtf_internal = DT_INTERNAL
#if defined(WINVER) && (WINVER >= 0x0400)
	,
	dtf_edit_control = DT_EDITCONTROL,
	dtf_path_ellipsis = DT_PATH_ELLIPSIS,
	dtf_end_ellipsis = DT_END_ELLIPSIS,
	dtf_modify_string = DT_MODIFYSTRING,
	dtf_rtlreading = DT_RTLREADING,
	dtf_word_ellipsis = DT_WORD_ELLIPSIS
#endif
#if defined(WINVER) && (WINVER >= 0x0500)
	,
	dtf_no_full_width_charbreak = DT_NOFULLWIDTHCHARBREAK
#endif
#if defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0500)
	,
	dtf_hide_prefix = DT_HIDEPREFIX,
	dtf_prefix_only = DT_PREFIXONLY
#endif
} PEDrawTextFormat, PEDTF, pedtf;

typedef enum Petal_Enum_MouseEvent
{
	me_with_left = MK_LBUTTON,
	me_with_right = MK_RBUTTON,
	me_with_middle = MK_MBUTTON,
	me_with_shift = MK_SHIFT,
	me_with_ctrl = MK_CONTROL,
	me_with_x1 = MK_XBUTTON1,
	me_with_x2 = MK_XBUTTON2,

	me_x1 = XBUTTON1,
	me_x2 = XBUTTON2,

	me_minimize_value = WM_MOUSEFIRST,
	me_move = WM_MOUSEMOVE,
	me_left_down = WM_LBUTTONDOWN,
	me_left_up = WM_LBUTTONUP,
	me_left_double_click = WM_LBUTTONDBLCLK,
	me_right_down = WM_RBUTTONDOWN,
	me_right_up = WM_RBUTTONUP,
	me_right_double_click = WM_RBUTTONDBLCLK,
	me_middle_down = WM_MBUTTONDOWN,
	me_middle_up = WM_MBUTTONUP,
	me_middle_double_click = WM_MBUTTONDBLCLK,
#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
	me_wheel = WM_MOUSEWHEEL,
#endif
#if (_WIN32_WINNT >= 0x0500)
	me_x_down = WM_XBUTTONDOWN,
	me_x_up = WM_XBUTTONUP,
	me_x_double_click = WM_XBUTTONDBLCLK,
#endif
#if (_WIN32_WINNT >= 0x0600)
	me_hwheel = WM_MOUSEHWHEEL,
#endif
	me_maximize_value = WM_MOUSELAST
} PEMouseEvent, PEME, peme;

typedef enum Petal_Enum_KeyboardEvent
{
	ke_down = WM_KEYDOWN,
	ke_up = WM_KEYUP,
	ke_char = WM_CHAR,
	ke_dead_char = WM_DEADCHAR,
	ke_sys_down = WM_SYSKEYDOWN,
	ke_sys_up = WM_SYSKEYUP,
	ke_sys_char = WM_SYSCHAR,
	ke_sys_dead_char = WM_SYSDEADCHAR,
#if(_WIN32_WINNT >= 0x0501)
	ke_unicode_char = WM_UNICHAR,
#endif
} PEKeyboardEvent, PEKE, peke;

// https://docs.microsoft.com/zh-cn/windows/win32/inputdev/virtual-key-codes
#ifndef NOVIRTUALKEYCODES
typedef enum Petal_Enum_VirtualKey
{
	vk_left_mouse_button = VK_LBUTTON,
	vk_right_mouse_button = VK_RBUTTON,
	vk_cancel = VK_CANCEL,
	vk_middle_mouse_button = VK_MBUTTON,
#if(_WIN32_WINNT >= 0x0500)
	vk_x1_mouse_button = VK_XBUTTON1,
	vk_x2_mouse_button = VK_XBUTTON2,
#endif
	vk_back_space = VK_BACK,
	vk_tab = VK_TAB,
	vk_clear = VK_CLEAR,
	vk_enter = VK_RETURN,
	vk_shift = VK_SHIFT,
	vk_ctrl = VK_CONTROL,
	vk_alt = VK_MENU,
	vk_pause = VK_PAUSE,
	vk_caps_lock = VK_CAPITAL,
	vk_kana = VK_KANA,				// IME
	vk_hangul = VK_HANGUL,			// IME
	vk_ime_on = VK_IME_ON,			// IME
	vk_junja = VK_JUNJA,			// IME
	vk_final = VK_FINAL,			// IME
	vk_hanja = VK_HANJA,			// IME
	vk_kanji = VK_KANJI,			// IME
	vk_hanzi = VK_KANJI,			// IME
	vk_ime_off = VK_IME_OFF,		// IME
	vk_escape = VK_ESCAPE,
	vk_convert = VK_CONVERT,		// IME
	vk_nonconvert = VK_NONCONVERT,	// IME
	vk_accept = VK_ACCEPT,			// IME
	vk_mode_change = VK_MODECHANGE,	// IME
	vk_space = VK_SPACE,
	vk_page_up = VK_PRIOR,
	vk_page_down = VK_NEXT,
	vk_end = VK_END,
	vk_home = VK_HOME,
	vk_left = VK_LEFT,
	vk_up = VK_UP,
	vk_right = VK_RIGHT,
	vk_down = VK_DOWN,
	vk_select = VK_SELECT,
	vk_print = VK_PRINT,
	vk_execute = VK_EXECUTE,
	vk_print_screen = VK_SNAPSHOT,
	vk_insert = VK_INSERT,
	vk_delete = VK_DELETE,
	vk_help = VK_HELP,
	vk_0 = 0x30,
	vk_1 = 0x31,
	vk_2 = 0x32,
	vk_3 = 0x33,
	vk_4 = 0x34,
	vk_5 = 0x35,
	vk_6 = 0x36,
	vk_7 = 0x37,
	vk_8 = 0x38,
	vk_9 = 0x39,
	vk_a = 0x41,
	vk_b = 0x42,
	vk_c = 0x43,
	vk_d = 0x44,
	vk_e = 0x45,
	vk_f = 0x46,
	vk_g = 0x47,
	vk_h = 0x48,
	vk_i = 0x49,
	vk_j = 0x4A,
	vk_k = 0x4B,
	vk_l = 0x4C,
	vk_m = 0x4D,
	vk_n = 0x4E,
	vk_o = 0x4F,
	vk_p = 0x50,
	vk_q = 0x51,
	vk_r = 0x52,
	vk_s = 0x53,
	vk_t = 0x54,
	vk_u = 0x55,
	vk_v = 0x56,
	vk_w = 0x57,
	vk_x = 0x58,
	vk_y = 0x59,
	vk_z = 0x5A,
	vk_left_win = VK_LWIN,
	vk_right_win = VK_RWIN,
	vk_apps = VK_APPS,
	vk_sleep = VK_SLEEP,
	vk_num0 = VK_NUMPAD0,
	vk_num1 = VK_NUMPAD1,
	vk_num2 = VK_NUMPAD2,
	vk_num3 = VK_NUMPAD3,
	vk_num4 = VK_NUMPAD4,
	vk_num5 = VK_NUMPAD5,
	vk_num6 = VK_NUMPAD6,
	vk_num7 = VK_NUMPAD7,
	vk_num8 = VK_NUMPAD8,
	vk_num9 = VK_NUMPAD9,
	vk_multiply = VK_MULTIPLY,		// *
	vk_add = VK_ADD,				// +
	vk_separator = VK_SEPARATOR,
	vk_subtract = VK_SUBTRACT,		// -
	vk_decimal = VK_DECIMAL,
	vk_divide = VK_DIVIDE,			// /
	vk_f1 = VK_F1,
	vk_f2 = VK_F2,
	vk_f3 = VK_F3,
	vk_f4 = VK_F4,
	vk_f5 = VK_F5,
	vk_f6 = VK_F6,
	vk_f7 = VK_F7,
	vk_f8 = VK_F8,
	vk_f9 = VK_F9,
	vk_f10 = VK_F10,
	vk_f11 = VK_F11,
	vk_f12 = VK_F12,
	vk_f13 = VK_F13,
	vk_f14 = VK_F14,
	vk_f15 = VK_F15,
	vk_f16 = VK_F16,
	vk_f17 = VK_F17,
	vk_f18 = VK_F18,
	vk_f19 = VK_F19,
	vk_f20 = VK_F20,
	vk_f21 = VK_F21,
	vk_f22 = VK_F22,
	vk_f23 = VK_F23,
	vk_f24 = VK_F24,
#if(_WIN32_WINNT >= 0x0604)
	vk_navigation_view = VK_NAVIGATION_VIEW,
	vk_navigation_menu = VK_NAVIGATION_MENU,
	vk_navigation_up = VK_NAVIGATION_UP,
	vk_navigation_down = VK_NAVIGATION_DOWN,
	vk_navigation_left = VK_NAVIGATION_LEFT,
	vk_navigation_right = VK_NAVIGATION_RIGHT,
	vk_navigation_accept = VK_NAVIGATION_ACCEPT,
	vk_navigation_cancel = VK_NAVIGATION_CANCEL,
#endif
	vk_num_lock = VK_NUMLOCK,
	vk_scroll = VK_SCROLL,
	vk_left_shift = VK_LSHIFT,
	vk_right_shift = VK_RSHIFT,
	vk_left_ctrl = VK_LCONTROL,
	vk_right_ctrl = VK_RCONTROL,
	vk_left_alt = VK_LMENU,
	vk_right_alt = VK_RMENU,

#if(_WIN32_WINNT >= 0x0500)
	vk_browser_back = VK_BROWSER_BACK,
	vk_browser_forward = VK_BROWSER_FORWARD,
	vk_browser_refresh = VK_BROWSER_REFRESH,
	vk_browser_stop = VK_BROWSER_STOP,
	vk_browser_search = VK_BROWSER_SEARCH,
	vk_browser_favorites = VK_BROWSER_FAVORITES,
	vk_browser_home = VK_BROWSER_HOME,
	vk_volume_mute = VK_VOLUME_MUTE,
	vk_volume_down = VK_VOLUME_DOWN,
	vk_volume_up = VK_VOLUME_UP,
	vk_volume_next_song = VK_MEDIA_NEXT_TRACK,
	vk_volume_prev_song = VK_MEDIA_PREV_TRACK,
	vk_volume_stop = VK_MEDIA_STOP,
	vk_volume_play_or_pause = VK_MEDIA_PLAY_PAUSE,
	vk_launch_mail = VK_LAUNCH_MAIL,
	vk_launch_media_select = VK_LAUNCH_MEDIA_SELECT,
	vk_launch_app1 = VK_LAUNCH_APP1,
	vk_launch_app2 = VK_LAUNCH_APP2,
#endif
											// 对应 美国标准键盘
	vk_semicolon_colon = VK_OEM_1,			// ; :
	vk_equal_plus = VK_OEM_PLUS,			// = +
	vk_comma_less = VK_OEM_COMMA,			// , <
	vk_substract_underscore = VK_OEM_MINUS,	// - _
	vk_stop_more = VK_OEM_PERIOD,			// . >
	vk_divide_question = VK_OEM_2,			// / ?
	vk_backtick_tilde = VK_OEM_3,			// ` ~
	vk_open_bracket_brace = VK_OEM_4,		// [ {
	vk_backslash_vertical_bar = VK_OEM_5,	// \ |
	vk_close_bracket_brace = VK_OEM_6,		// ] }
	vk_quotation_marks = VK_OEM_7,			// ' "
	vk_less_more = VK_OEM_102,				// < >
	vk_oem1 = VK_OEM_1,
	vk_oem2 = VK_OEM_2,
	vk_oem3 = VK_OEM_3,
#if(_WIN32_WINNT >= 0x0604)
	vk_gamepad_a = VK_GAMEPAD_A,
	vk_gamepad_b = VK_GAMEPAD_B,
	vk_gamepad_x = VK_GAMEPAD_X,
	vk_gamepad_y = VK_GAMEPAD_Y,
	vk_gamepad_right_shoulder = VK_GAMEPAD_RIGHT_SHOULDER,
	vk_gamepad_left_shoulder = VK_GAMEPAD_LEFT_SHOULDER,
	vk_gamepad_left_trigger = VK_GAMEPAD_LEFT_TRIGGER,
	vk_gamepad_right_trigger = VK_GAMEPAD_RIGHT_TRIGGER,
	vk_gamepad_dpad_up = VK_GAMEPAD_DPAD_UP,
	vk_gamepad_dpad_down = VK_GAMEPAD_DPAD_DOWN,
	vk_gamepad_dpad_left = VK_GAMEPAD_DPAD_LEFT,
	vk_gamepad_dpad_right = VK_GAMEPAD_DPAD_RIGHT,
	vk_gamepad_menu = VK_GAMEPAD_MENU,
	vk_gamepad_view = VK_GAMEPAD_VIEW,
	vk_gamepad_letf_thumbstick_button = VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON,
	vk_gamepad_right_thumbstick_button = VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON,
	vk_gamepad_letf_thumbstick_up = VK_GAMEPAD_LEFT_THUMBSTICK_UP,
	vk_gamepad_letf_thumbstick_down = VK_GAMEPAD_LEFT_THUMBSTICK_DOWN,
	vk_gamepad_letf_thumbstick_right = VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT,
	vk_gamepad_letf_thumbstick_left = VK_GAMEPAD_LEFT_THUMBSTICK_LEFT,
	vk_gamepad_right_thumbstick_up = VK_GAMEPAD_RIGHT_THUMBSTICK_UP,
	vk_gamepad_right_thumbstick_down = VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN,
	vk_gamepad_right_thumbstick_right = VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT,
	vk_gamepad_right_thumbstick_left = VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT,
#endif
	vk_oem4 = VK_OEM_4,
	vk_oem5 = VK_OEM_5,
	vk_oem6 = VK_OEM_6,
	vk_oem7 = VK_OEM_7,
	vk_oem8 = VK_OEM_8,
	vk_oem102 = VK_OEM_102,
#if(WINVER >= 0x0400)
	vk_process_key = VK_PROCESSKEY,			// IME
#endif
#if(_WIN32_WINNT >= 0x0500)
	vk_packet = VK_PACKET,
#endif
	vk_attn = VK_ATTN,
	vk_cr_sel = VK_CRSEL,
	vk_ex_sel = VK_EXSEL,
	vk_erase_end_of_file = VK_EREOF,
	vk_play = VK_PLAY,
	vk_zoom = VK_ZOOM,
	vk_no_name = VK_NONAME,
	vk_pa1 = VK_PA1,
	vk_oem_clear = VK_OEM_CLEAR,
} PEWirtualKey, PEVK, pevk;
#endif

typedef enum Petal_Enum_PenStyle
{
	ps_default = 0x0000,
	ps_solid = PS_SOLID,				// ________________ //
	ps_dash = PS_DASH,					// _ _ _ _ _ _ _ _  //
	ps_dot = PS_DOT,					// ................ //
	ps_dash_dot = PS_DASHDOT,			// _._._._._._._._. //
	ps_dash_dot_dot = PS_DASHDOTDOT,	// _.._.._.._.._.._ //
	ps_dash_double_dot = PS_DASHDOTDOT,	// _.._.._.._.._.._ //
	ps_null = PS_NULL,					//                  //
	ps_transparent = PS_NULL,			//                  //
	ps_inside_frame = PS_INSIDEFRAME,
	ps_user_style = PS_USERSTYLE,
	ps_alternate = PS_ALTERNATE,
	ps_style_mask = PS_STYLE_MASK,

	ps_endcap_default = PS_ENDCAP_ROUND,
	ps_endcap_round = PS_ENDCAP_ROUND,
	ps_endcap_square = PS_ENDCAP_SQUARE,
	ps_endcap_flat = PS_ENDCAP_FLAT,
	ps_endcap_mask = PS_ENDCAP_MASK,

	ps_join_default = PS_JOIN_ROUND,
	ps_join_round = PS_JOIN_ROUND,
	ps_join_bevel = PS_JOIN_BEVEL,
	ps_join_miter = PS_JOIN_MITER,
	ps_join_mask = PS_JOIN_MASK,

	ps_cosmetic = PS_COSMETIC,
	ps_geometric = PS_GEOMETRIC,
	ps_type_mask = PS_TYPE_MASK
} PEPenStyle, PEPS, peps;

typedef enum Petal_Enum_BrushStyle
{
	bs_solid = BS_SOLID,
	bs_null = BS_NULL,
	bs_hollow = BS_HOLLOW,
	bs_hatched = BS_HATCHED,
	bs_pattern = BS_PATTERN,
	bs_indexed = BS_INDEXED,
	bs_DIB_pattern = BS_DIBPATTERN,
	bs_DIB_pattern_pt = BS_DIBPATTERNPT,
	bs_pattern_8x8 = BS_PATTERN8X8,
	bs_DIB_Pattern_8x8 = BS_DIBPATTERN8X8,
	bs_monopattern = BS_MONOPATTERN,

	/* Hatch Styles */
	hs_horizontal = HS_HORIZONTAL,		// ________________ //
	hs_hline = HS_HORIZONTAL,
	hs_vertical = HS_VERTICAL,			// |||||||||||||||| //
	hs_vline = HS_VERTICAL,
	hs_fdiagonal = HS_FDIAGONAL,		// \\\\\\\\\\\\\\\\ //
	hs_fdline = HS_FDIAGONAL,
	hs_bdiagonal = HS_BDIAGONAL,		// //////////////// //
	hs_bdline = HS_BDIAGONAL,
	hs_cross = HS_CROSS,				// ++++++++++++++++ //
	hs_diagcross = HS_DIAGCROSS,		// xxxxxxxxxxxxxxxx //
	hs_dcross = HS_DIAGCROSS,
	hs_api_max = HS_API_MAX
} PEBrushStyle, PEBS, pebs;

// Named
typedef float32						Petal_TypeDefine_float;
typedef float64						Petal_TypeDefine_double;
typedef oint						Petal_TypeDefine_int;
typedef ouint						Petal_TypeDefine_uint;
typedef char8						Petal_TypeDefine_achar;
typedef char16						Petal_TypeDefine_wchar;
#ifdef _W64
typedef ntstr8						Petal_TypeDefine_astr;
typedef ntstr16						Petal_TypeDefine_ustr;
typedef ntcstr8						Petal_TypeDefine_castr;
typedef ntcstr16					Petal_TypeDefine_custr;
#endif
typedef byte8						Petal_TypeDefine_byte;
typedef bool8						Petal_TypeDefine_bool;
typedef void0						Petal_TypeDefine_void;
typedef void_ptr32					Petal_TypeDefine_voidp;
typedef cvoid_ptr32					Petal_TypeDefine_cvoidp;
typedef uint32						Petal_TypeDefine_color;

// Named
typedef Petal_TypeDefine_float		PTfloat,			ptfloat;
typedef Petal_TypeDefine_double		PTdouble,			ptdouble;
typedef Petal_TypeDefine_int		PTint,				ptint;
typedef Petal_TypeDefine_uint		PTuint,				ptuint;
typedef INT							WINint,				winint;
typedef UINT						WINuint,			winuint;
typedef int							CPPint,				cppint;
typedef unsigned int				CPPuint,			cppuint;
typedef Petal_TypeDefine_achar		PTachar,			ptachar;
typedef Petal_TypeDefine_wchar		PTwchar,			ptwchar;
#ifdef _W64
typedef Petal_TypeDefine_astr		PTastr,				ptastr;
typedef Petal_TypeDefine_ustr		PTustr,				ptustr;
typedef Petal_TypeDefine_castr		PTcastr,			ptcastr;
typedef Petal_TypeDefine_custr		PTcustr,			ptcustr;
#endif
typedef Petal_Class_Message			PTmessage,			ptmsg;
typedef Petal_TypeDefine_byte		PTbyte,				ptbyte;
typedef Petal_TypeDefine_bool		PTbool,				ptbool;
typedef Petal_TypeDefine_void		PTvoid,				ptvoid;
typedef Petal_TypeDefine_voidp		PTvoidp,			ptvoidp;
typedef Petal_TypeDefine_cvoidp		PTcvoidp,			ptcvoidp;
typedef Petal_TypeDefine_color		PTcolor,			ptcolor;

// Petal Object
class Petal_Class_Base;

class Petal_Class_WindowClassU;
class Petal_Class_WindowBaseU;
class Petal_Class_WindowSetU;
class Petal_Class_WindowU;
class Petal_Class_MessageLoopU224;
class Petal_Class_MessageLoopU256;

class Petal_Class_WindowClassA;
class Petal_Class_WindowBaseA;
class Petal_Class_WindowSetA;
class Petal_Class_WindowA;
class Petal_Class_MessageLoopA224;
class Petal_Class_MessageLoopA256;

class Petal_Class_PaintDevice;
class Petal_Class_Pen;
class Petal_Class_Brush;
class Petal_Class_Font;
class Petal_Class_MouseEvent;
class Petal_Class_KeyboardEvent;
class Petal_Class_Timer;
class Petal_Class_MediaTimer;
class Petal_Class_TimerEvent;
class Petal_Class_Bitmap;

typedef Petal_Class_Base			PCBase;
typedef Petal_Class_Base*			PCBaseP;

#include <Petal~Object.h>

#ifdef _MAC
typedef Petal_Class_MessageLoopU256	Petal_Class_MessageLoopU;
typedef Petal_Class_MessageLoopA256	Petal_Class_MessageLoopA;
#else
typedef Petal_Class_MessageLoopU224	Petal_Class_MessageLoopU;
typedef Petal_Class_MessageLoopA224	Petal_Class_MessageLoopA;
#endif

typedef Petal_Class_WindowU			PCWindowU;
typedef Petal_Class_WindowA			PCWindowA;
typedef Petal_Class_WindowU*		PCWindowUP;
typedef Petal_Class_WindowA*		PCWindowAP;
typedef Petal_Class_MessageLoopU	PCMessageLoopU;
typedef Petal_Class_MessageLoopA	PCMessageLoopA;

typedef Petal_Class_PaintDevice		PCPaintDevice;
typedef Petal_Class_Pen				PCPen;
typedef Petal_Class_Brush			PCBrush;
typedef Petal_Class_Font			PCFont;
typedef Petal_Class_MouseEvent		PCMouseEvent;
typedef Petal_Class_KeyboardEvent	PCKeyboardEvent;
typedef Petal_Class_Timer			PCTimer;
typedef Petal_Class_MediaTimer		PCMediaTimer;
typedef Petal_Class_TimerEvent		PCTimerEvent;
typedef Petal_Class_Bitmap			PCBitmap;

#endif