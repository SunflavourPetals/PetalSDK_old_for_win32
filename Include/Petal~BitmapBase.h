#pragma once

#ifndef Petal_Header_BitmapBase_Included
#define Petal_Header_BitmapBase_Included

#include <Petal~Define.h>

class Petal_Class_BitmapBase : public PCBase
{
public:
	enum { image_type_bitmap = IMAGE_BITMAP, image_type_icon = IMAGE_ICON, image_type_cursor = IMAGE_CURSOR };
	enum { default_width = 0, default_height = 0, default_size = 0 };
protected:
	cppint pt_image_type;
	winuint pt_load_style;
public:
	Petal_Class_BitmapBase(cppint image_type = image_type_bitmap);
	virtual ~Petal_Class_BitmapBase();
	ptvoid SetLoadStyle(winuint load_style);
	ptvoid AddLoadStyle(winuint load_style);
	ptvoid EraseLoadStyle(winuint load_style_for_erase);
	handle32 LoadImageFromFile(cppint image_type, ptcvoidp image_name, winuint zoom_width = default_width, winuint zoom_height = default_height, ptbool use_unicode = Petal_Define_UseUnicode);
	handle32 LoadImageFromResource(cppint image_type, cppint resource_id, winuint zoom_width = default_width, winuint zoom_height = default_height, ptbool use_unicode = Petal_Define_UseUnicode);
	cppint ImageType();
	virtual ptbool Release() = 0;
};

#pragma comment(lib, "Petal~BitmapBase.lib")
#endif