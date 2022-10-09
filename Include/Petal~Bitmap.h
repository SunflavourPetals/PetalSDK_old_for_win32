#pragma once

#ifndef Petal_Header_Bitmap_Included
#define Petal_Header_Bitmap_Included

#include <Petal~BitmapBase.h>

class Petal_Class_Bitmap : public Petal_Class_BitmapBase
{
	hbitmap32 pt_bitmap_handle;
public:
	Petal_Class_Bitmap();
	Petal_Class_Bitmap(ptcvoidp image_name, ptbool load_now = yes, winuint zoom_width = default_width, winuint zoom_height = default_height, ptbool use_unicode = Petal_Define_UseUnicode);
	Petal_Class_Bitmap(cppint resource_id, ptbool load_now = yes, winuint zoom_width = default_width, winuint zoom_height = default_height, ptbool use_unicode = Petal_Define_UseUnicode);
	virtual ~Petal_Class_Bitmap();
#ifdef LoadImage
#undef LoadImage
#endif
	hbitmap32 LoadImage(ptcvoidp image_name, winuint zoom_width = default_width, winuint zoom_height = default_height, ptbool use_unicode = Petal_Define_UseUnicode);
	hbitmap32 LoadImage(cppint resource_id, winuint zoom_width = default_width, winuint zoom_height = default_height, ptbool use_unicode = Petal_Define_UseUnicode);
	hbitmap32 BitmapHandle();
	ptbool Release();
};

#pragma comment(lib, "Petal~Bitmap.lib")
#endif