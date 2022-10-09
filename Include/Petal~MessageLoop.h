#pragma once

#ifndef Petal_Header_MessageLoop_Included
#define Petal_Header_MessageLoop_Included

#include <Petal~Types.h>

class Petal_Class_MessageLoopU224 : public PCBase
{
	ptbool			pt_use_peek_message;
public:
	cppint exec();
public:
	Petal_Class_MessageLoopU224(ptbool use_peek_message_function = true);
	~Petal_Class_MessageLoopU224();
};

class Petal_Class_MessageLoopA224 : public PCBase
{
	ptbool			pt_use_peek_message;
public:
	cppint exec();
public:
	Petal_Class_MessageLoopA224(ptbool use_peek_message_function = true);
	~Petal_Class_MessageLoopA224();
};

#pragma comment(lib, "Petal~MessageLoop.lib")
#endif