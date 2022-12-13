#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include "macros.h"

DISABLE_WCAST_FUNCTION_TYPE
#include <nan.h>
DISABLE_WCAST_FUNCTION_TYPE_END

NAN_METHOD(fascistCheck);
NAN_METHOD(fascistCheckAsync);
NAN_METHOD(fascistCheckUser);
NAN_METHOD(fascistCheckUserAsync);

#endif