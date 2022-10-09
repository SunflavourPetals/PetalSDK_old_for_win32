#pragma once

#ifndef Petal_Header_Pen_Included
#define Petal_Header_Pen_Included

#include <Petal~Types.h>

class Petal_Class_Pen : public PCBase
{
	hpen32 pt_pen_handle;
	ptcolor pt_pen_color;
	cppint pt_pen_width;
	cppint pt_pen_style;
public:
	Petal_Class_Pen();
	Petal_Class_Pen(cppint line_width, ptcolor ink_color = 0, cppint pen_style = PS_SOLID);
	virtual ~Petal_Class_Pen();
	hpen32 MakePen();
	hpen32 MakePen(cppint line_width, ptcolor ink_color, cppint pen_style);
	ptbool Release();
	hpen32 PenHandle();
	ptcolor Color();
	cppint Style();
	cppint PenWidth();
	ptvoid Describe(cppint line_width, ptcolor ink_color, cppint pen_style);
	ptvoid SetWidth(cppint line_width);
	ptvoid SetColor(ptcolor ink_color);
	ptvoid SetStyle(cppint pen_style);
};

#pragma comment(lib, "Petal~Pen.lib")
#endif