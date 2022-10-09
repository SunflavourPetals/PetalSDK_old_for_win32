#pragma once

#ifndef Petal_Header_Object_Included
#define Petal_Header_Object_Included

#include <Petal~Types.h>

class Petal_Class_Base
{
public:
	Petal_Class_Base();
	virtual ~Petal_Class_Base();
	ptvoidp operator new(size_win size);
	ptvoidp operator new[](size_win size);
};

class Petal_Class_ObjectList : public Petal_Class_Base
{
	struct node
	{
		node* prev;
		Petal_Class_Base* pt_obj;
	};
	node* single_list_tail;
	node* array_list_tail;
	cppint count_single;
	cppint count_array;
public:
	Petal_Class_ObjectList();
	~Petal_Class_ObjectList();

	ptbool PushBackSingle(PCBaseP petal_object);
	ptbool PushBackArray(PCBaseP petal_object_array);
	ptbool ReleaseSingle();
	ptbool ReleaseArray();
};

#pragma comment(lib, "Petal~Object.lib")
#endif