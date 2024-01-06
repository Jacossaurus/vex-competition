#pragma once

#include "images/cat.h"

void loadImages()
{
	Brain.Screen.drawImageFromBuffer(_cat_buffer, 0, 0, sizeof(_cat_buffer));
}