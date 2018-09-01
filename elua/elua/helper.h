#pragma once

#include <windows.h>
#include "string.h"
#include <algorithm>

char* zy_vsprint(const char* fmt, ...);
char* zy_clone_text(const char* text);
char* zy_clone_textlen(const char* text, int len);