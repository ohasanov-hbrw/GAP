#pragma once

#include <cassert>
#include "raylib.h"

#define assertm(exp, msg) assert(exp && msg)
#define GAP_ASSERT(condition, error) assertm(condition, error)
#define LOG_WARN(msg, ...) TraceLog(LOG_WARNING, msg, __VA_ARGS__)