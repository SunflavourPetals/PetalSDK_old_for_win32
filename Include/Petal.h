#pragma once

#ifndef Petal_HeaderAndSource_Petal_Included
#define Petal_HeaderAndSource_Petal_Included

#include <Petal~Window.h>
#if defined(_MAC)
#include <Petal~MessageLoopMac.h>
#else
#include <Petal~MessageLoop.h>
#endif
#include <Petal~PaintDevice.h>
#include <Petal~Pen.h>
#include <Petal~Font.h>
#include <Petal~Brush.h>

#include <Petal~Timer.h>

#include <Petal~TimerEvent.h>

#include <Petal~MouseEvent.h>

#include <Petal~KeyboardEvent.h>

#include <Petal~Bitmap.h>

#endif