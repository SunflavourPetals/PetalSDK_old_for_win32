#pragma once

#ifndef Petal_Header_MessageLoopMac_Included
#define Petal_Header_MessageLoopMac_Included

#include <Petal~Types.h>

class Petal_Class_MessageLoopU256 : public PCBase
{
	ptbool			pt_use_peek_message;
public:
	cppint exec();
public:
	Petal_Class_MessageLoopU256(ptbool use_peek_message_function = true);
	~Petal_Class_MessageLoopU256();
};

class Petal_Class_MessageLoopA256 : public PCBase
{
	ptbool			pt_use_peek_message;
public:
	cppint exec();
public:
	Petal_Class_MessageLoopA256(ptbool use_peek_message_function = true);
	~Petal_Class_MessageLoopA256();
};

#include <../Source/Petal~MessageLoopMac.petal>
#endif