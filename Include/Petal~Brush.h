#pragma once

#ifndef Petal_Header_Brush_Included
#define Petal_Header_Brush_Included

#include <Petal~Types.h>
#include <Petal~Bitmap.h>

// Unused Function:
// CreateDIBPatternBrush();
// CreateDIBPatternBrushPt();
// \Unused Function

class Petal_Class_Brush : public PCBase
{
	enum { solid = bs_solid, hatch = bs_hatched, pattern = bs_pattern };
	hbrush32 pt_brush_handle;
	cppint pt_brush_style;
	ptcolor pt_brush_color;
	cppint pt_hatch_style;
	hbitmap32 pt_pattern_bitmap;
public:
	Petal_Class_Brush();
	Petal_Class_Brush(ptcolor ink_color, cppint hatch_style = -1);
	Petal_Class_Brush(hbitmap32 bitmap);
	Petal_Class_Brush(PCBitmap bitmap);
	virtual ~Petal_Class_Brush();

	hbrush32 MakeBrush();
	hbrush32 MakeBrush(cppint brush_style);
	hbrush32 MakeBrush(ptcolor ink_color, cppint hatch_style = -1);
	hbrush32 MakeBrush(PCBitmap bitmap);
	hbrush32 MakeBrush(hbitmap32 bitmap);
	ptbool Release();
	hbrush32 BrushHandle();
	cppint BrushStyle();
	ptcolor Color();
	cppint HatchStyle();
	hbitmap32 BitmapHandle();
	ptvoid Describe(ptcolor ink_color, cppint hatch_style = -1);
	ptvoid Describe(PCBitmap bitmap);
	ptvoid Describe(hbitmap32 bitmap);
	ptvoid SetBrushStyle(cppint brush_style);
	ptvoid SetColor(ptcolor ink_color);
	ptvoid SetHatchStyle(cppint hatch_style);
	ptvoid SetBitmap(PCBitmap bitmap);
	ptvoid SetBitmap(hbitmap32 bitmap);
};

#pragma comment(lib, "Petal~Brush.lib")
#endif