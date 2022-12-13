#include "functions.h"

using v8::FunctionTemplate;

NAN_MODULE_INIT(InitAll) 
{
    Nan::Set(target, Nan::New("fascistCheck").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(fascistCheck))
        .ToLocalChecked());
    Nan::Set(target, Nan::New("fascistCheckAsync").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(fascistCheckAsync))
        .ToLocalChecked());
    Nan::Set(target, Nan::New("fascistCheckUser").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(fascistCheckUser))
        .ToLocalChecked());
    Nan::Set(target, Nan::New("fascistCheckUserAsync").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(fascistCheckUserAsync))
        .ToLocalChecked());
}

DISABLE_WCAST_FUNCTION_TYPE
NODE_MODULE(cracklib, InitAll);
DISABLE_WCAST_FUNCTION_TYPE_END