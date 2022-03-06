#pragma once

#include <cassert>

#define assertm(exp, msg) assert(exp && msg)
#define GAP_ASSERT(condition, error) assertm(condition, error)
