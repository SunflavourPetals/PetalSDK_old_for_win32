#pragma once

#ifndef Petal_Header_PaintDevice_Included
#define Petal_Header_PaintDevice_Included

#include <Petal~Window.h>
#include <Petal~Bitmap.h>
#include <Petal~Pen.h>
#include <Petal~Font.h>
#include <Petal~Brush.h>

#include <Petal~Types.h>

ptcolor ToRGB(uint8 r, uint8 g, uint8 b);
ptcolor ToRGBA(uint8 r, uint8 g, uint8 b, uint8 a);

class Petal_Class_PaintDevice : public PCBase, public paintstruct288
{
	enum { draw_all_charactors = -1 };
	enum { default_bitmap_width = -1, default_bitmap_height = -1 };
	hwin32			pt_window_handle;
	rect128			pt_client_rect;
	hdc32			pt_memory_dc;
	hdc32			pt_buffer_dc;
	hbitmap32		pt_buffer_bitmap;
	hpen32			pt_pen_hendle;
	hfont32			pt_font_handle;
	hbrush32		pt_brush_handle;
public:
	hdc32			BeginPaint();
	cppint			EndPaint();
	ptvoid			SetParent(hwin32 parent_window);
	ptvoid			SetParent(PCWindowUP parent_window);
	ptvoid			SetParent(PCWindowAP parent_window);
	hwin32			ParentWindowHandle();
	rect128			ClientRect();
	pos64			PenPosition();
	ptvoid			UpdateBuffers();

	//
	ptvoid			SetTextBackgroundMode(cppint background_mode);
	ptvoid			SetTransparentBackground(ptbool use_transparent_background = yes);
	ptvoid			SetBackgroundColor(ptcolor color);
	ptvoid			SetTextColor(ptcolor color);
	ptbool			SetPen(PCPen pen);
	ptbool			SetFont(PCFont font);
	ptbool			SetBrush(PCBrush brush);

	// Draw Geo
	ptbool			InvertRect(rect128 rect);
	ptbool			FrameRect(rect128 rect, hbrush32 brush = NULL);
	ptbool			FillRect(rect128 rect, hbrush32 brush = NULL);
	ptbool			MoveTo(pos64 position);
	ptbool			MoveTo(cppint x, cppint y);
	ptbool			LineTo(pos64 position);
	ptbool			LineTo(cppint x, cppint y);
	ptbool			PolyLine(pos64 point_array[], cppint count);
	ptbool			Polygon(pos64 point_array[], cppint count);
	ptbool			PolyBezier(pos64 point_array[], cppint count);
	ptbool			DrawLine(pos64 start_point, pos64 end_point);
	ptbool			DrawLine(pos64 start_point, cppint end_point_x, cppint end_point_y);
	ptbool			DrawLine(cppint start_point_x, cppint start_point_y, pos64 end_point);
	ptbool			DrawLine(cppint start_point_x, cppint start_point_y, cppint end_point_x, cppint end_point_y);
	ptbool			DrawRectangle(rect128 rect);
	ptbool			DrawRectangle(pos64 left_top, pos64 right_bottom);
	ptbool			DrawRectangle(cppint left, cppint top, cppint right, cppint bottom);
	ptbool			DrawEllipse(rect128 rect);
	ptbool			DrawEllipse(pos64 left_top, pos64 right_bottom);
	ptbool			DrawEllipse(cppint left, cppint top, cppint right, cppint bottom);
	ptbool			DrawRoundRect(rect128 rect, size2d64 round);
	ptbool			DrawRoundRect(pos64 left_top, pos64 right_bottom, size2d64 round);
	ptbool			DrawRoundRect(cppint left, cppint top, cppint right, cppint bottom, size2d64 round);

	// Draw Text
#ifdef DrawText
#undef DrawText
#endif
	cppint			DrawText(ptcvoidp text, rect128 rect, winuint format, cppint charactor_count_of_text = draw_all_charactors, ptbool Unicode_yes = Petal_Define_UseUnicode);
	cppint			DrawText(ptcvoidp text, pos64 position, size2d64 size, winuint format, cppint charactor_count_of_text = draw_all_charactors, ptbool Unicode_yes = Petal_Define_UseUnicode);
	cppint			DrawText(ptcvoidp text, pos64 position, cppint width, cppint height, winuint format, cppint charactor_count_of_text = draw_all_charactors, ptbool Unicode_yes = Petal_Define_UseUnicode);
	cppint			DrawText(ptcvoidp text, cppint x, cppint y, size2d64 size, winuint format, cppint charactor_count_of_text = draw_all_charactors, ptbool Unicode_yes = Petal_Define_UseUnicode);
	cppint			DrawText(ptcvoidp text, cppint x, cppint y, cppint width, cppint height, winuint format, cppint charactor_count_of_text = draw_all_charactors, ptbool Unicode_yes = Petal_Define_UseUnicode);

	// Text Out
#ifdef TextOut
#undef TextOut
#endif
	ptbool			TextOut(ptcvoidp text, pos64 position, ptbool Unicode_yes = Petal_Define_UseUnicode);
	ptbool			TextOut(ptcvoidp text, cppint x, cppint y, ptbool Unicode_yes = Petal_Define_UseUnicode);

	// Image Out
	ptbool			BitmapBlt(PCBitmap& bitmap, cppint x = 0, cppint y = 0, cppuint bitmap_x = 0, cppuint bitmap_y = 0, cppint bitmap_width = default_bitmap_width, cppint bitmap_height = default_bitmap_height);
	ptbool			BitmapMaskBlt(PCBitmap& bitmap, PCBitmap& mask_bitmap, cppint x = 0, cppint y = 0, cppuint bitmap_x = 0, cppuint bitmap_y = 0, cppint bitmap_width = default_bitmap_width, cppint bitmap_height = default_bitmap_height);

public:
	Petal_Class_PaintDevice(hwin32 window_handle = NULL);
	Petal_Class_PaintDevice(Petal_Class_WindowU* parent);
	Petal_Class_PaintDevice(Petal_Class_WindowA* parent);
	~Petal_Class_PaintDevice();
};

#pragma comment(lib, "Petal~PaintDevice.lib")
#endif