#include "functions.h"
#include "check.h"
#include <crack.h>

NAN_METHOD(fascistCheck) 
{
    if (info.Length() < 1)
    {
        Nan::ThrowError(Nan::Error("fascistCheck(password[, dictionaryPath]"));
    }

    char *msg;

    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value passwd(isolate, info[0]);

    if (info.Length() == 2)
    {
        v8::String::Utf8Value dict(isolate, info[1]);
        msg = check(*passwd, *dict);
    }
    else
    {
        msg = check(*passwd, GetDefaultCracklibDict());
    }

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();

    if (!msg)
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), Nan::Null());
    }
    else
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), 
            Nan::New(msg).ToLocalChecked());
    }

    info.GetReturnValue().Set(obj);
}

NAN_METHOD(fascistCheckAsync)
{
    if (info.Length() < 2)
    {
        Nan::ThrowError(Nan::Error("fascistCheckAsync(password[, dictionaryPath], callback"));
    }

    char *msg;

    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value passwd(isolate, info[0]);

    if (info.Length() == 2)
    {
        // passwd, callback
        msg = check(*passwd, GetDefaultCracklibDict());
    }
    else 
    {
        v8::String::Utf8Value dict(isolate, info[1]);
        msg = check(*passwd, *dict);
    }

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();

    if (!msg)
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), Nan::Null());
    }
    else
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), 
            Nan::New(msg).ToLocalChecked());
    }

    v8::Local<v8::Function> cb = info[info.Length() - 1].As<v8::Function>();
    Nan::AsyncResource* resource = new Nan::AsyncResource(
        Nan::New<v8::String>("Callcb").ToLocalChecked());
    int argc = 1;
    v8::Local<v8::Value> argv[] = { obj };
    resource->runInAsyncScope(Nan::GetCurrentContext()->Global(), cb, argc, 
        argv);
}

NAN_METHOD(fascistCheckUser)
{
    if (info.Length() < 3)
    {
        Nan::ThrowError(
            Nan::Error("fascistCheckUser(password, username, gecos[, dictionaryPath]")
        );
    }

    char *msg;

    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value passwd(isolate, info[0]);
    v8::String::Utf8Value user(isolate, info[1]);
    v8::String::Utf8Value gecos(isolate, info[2]);

    if (info.Length() == 3)
    {
        msg = checkUser(*passwd, GetDefaultCracklibDict(), *user, *gecos);
    }
    else 
    {
        v8::String::Utf8Value dict(isolate, info[3]);
        msg = checkUser(*passwd, *dict, *user, *gecos);
    }

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();

    if (!msg)
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), Nan::Null());
    }
    else
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), 
            Nan::New(msg).ToLocalChecked());
    }

    info.GetReturnValue().Set(obj);
}

NAN_METHOD(fascistCheckUserAsync)
{
    if (info.Length() < 4)
    {
        Nan::ThrowError(
            Nan::Error(
                "fascistCheckUser(password, username, gecos[, dictionaryPath], callback")
        );
    }

    char *msg;

    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value passwd(isolate, info[0]);
    v8::String::Utf8Value user(isolate, info[1]);
    v8::String::Utf8Value gecos(isolate, info[2]);

    if (info.Length() == 4)
    {
        msg = checkUser(*passwd, GetDefaultCracklibDict(), *user, *gecos);
    }
    else 
    {
        v8::String::Utf8Value dict(isolate, info[3]);
        msg = checkUser(*passwd, *dict, *user, *gecos);
    }

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();

    if (!msg)
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), Nan::Null());
    }
    else
    {
        Nan::Set(obj, Nan::New("message").ToLocalChecked(), 
            Nan::New(msg).ToLocalChecked());
    }

    v8::Local<v8::Function> cb = info[info.Length() - 1].As<v8::Function>();
    Nan::AsyncResource* resource = new Nan::AsyncResource(
        Nan::New<v8::String>("Callcb").ToLocalChecked());
    int argc = 1;
    v8::Local<v8::Value> argv[] = { obj };
    resource->runInAsyncScope(Nan::GetCurrentContext()->Global(), cb, argc, 
        argv);
}