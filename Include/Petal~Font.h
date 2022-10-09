#pragma once

#ifndef Petal_Header_Font_Included
#define Petal_Header_Font_Included

#include <Petal~Define.h>

class Petal_Class_Font : public PCBase
{
	hfont32 pt_font_handle;
	cppint pt_height;
	cppint pt_width;
	cppint pt_escapement;
	cppint pt_orientation;
	cppint pt_weight;
	ptbool pt_italic;
	ptbool pt_underline;
	ptbool pt_strike_out;
	dword32 pt_character_set;
	dword32 pt_out_precision;
	dword32 pt_clip_precision;
	dword32 pt_quality;
	dword32 pt_pitch_and_family;
	char8 pt_face_name_a[32];
	char16 pt_face_name_u[32];
	ptbool pt_use_unicode;
public:
	Petal_Class_Font();
	Petal_Class_Font(ptcustr face_name, dword32 character_set = DEFAULT_CHARSET,
		cppint height = 0, cppint width = 0, cppint escapement = 0, cppint orientation = 0, cppint weight = 0,
		ptbool Italic = no, ptbool Underline = no, ptbool Strike_out = no,
		dword32 out_precision = 0, dword32 clip_precision = 0, dword32 quality = 0, dword32 pitch_and_family = 0);
	Petal_Class_Font(ptcastr face_name, dword32 character_set = DEFAULT_CHARSET,
		cppint height = 0, cppint width = 0, cppint escapement = 0, cppint orientation = 0, cppint weight = 0, 
		ptbool Italic = no, ptbool Underline = no, ptbool Strike_out = no, 
		dword32 out_precision = 0, dword32 clip_precision = 0, dword32 quality = 0, dword32 pitch_and_family = 0);
	virtual ~Petal_Class_Font();

	ptvoid Describe(ptcvoidp face_name, ptbool use_unicode = Petal_Define_UseUnicode, dword32 character_set = DEFAULT_CHARSET,
		cppint height = 0, cppint width = 0, cppint escapement = 0, cppint orientation = 0, cppint weight = 0,
		ptbool Italic = no, ptbool Underline = no, ptbool Strike_out = no,
		dword32 out_precision = 0, dword32 clip_precision = 0, dword32 quality = 0, dword32 pitch_and_family = 0);
	hfont32 MakeFont();
	hfont32 MakeFont(ptcustr face_name);
	hfont32 MakeFont(ptcastr face_name);
	hfont32 FontHandle();
	cppint Height();
	cppint Width();
	cppint Escapement();
	cppint Orientation();
	cppint Weight();
	ptbool IsItalic();
	ptbool IsUnderline();
	ptbool IsStrikeOut();
	dword32 CharacterSet();
	dword32 OutPrecision();
	dword32 ClipPrecision();
	dword32 Quality();
	dword32 PitchAndFamily();
	ptcustr FaceName(ptustr res);
	ptcastr FaceName(ptastr res);
	ptbool UseUnicode();
	ptbool Release();
};

#pragma comment(lib, "Petal~Font.lib")
#endif