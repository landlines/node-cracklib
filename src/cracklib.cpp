#include <node.h>
#include <crack.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"

DISABLE_WCAST_FUNCTION_TYPE
#include <v8.h>
#include <nan.h>
DISABLE_WCAST_FUNCTION_TYPE_END

using namespace v8;
using namespace std;

/*!
 * \brief   Checks a password against the default cracklib dictionary
 * \param   password Password string to check
 * \param   dictionaryPath Optional path to custom dictionary.
 * \return  Cracklib check result
 * 
 * The return value will be a dictionary object with a single member
 * named "message". If "message" is NULL the password is acceptable, in
 * all other cases "message" will contain the reason the password was rejected.
 */
void fascistCheck (const Nan::FunctionCallbackInfo<v8::Value>& info) {

  if (info.Length() < 1) {
    Nan::ThrowError(Nan::Error("fascistCheck(password[, dictionaryPath])"));
  }

  v8::Isolate* isolate = info.GetIsolate();
  v8::String::Utf8Value spass(isolate, info[0]);

  const char *passwd = *spass; 
  const char *dict;

  if (info.Length() == 2) {
    v8::String::Utf8Value sdict(isolate, info[1]);
    dict = strdup(*sdict);
  } else {
    dict = GetDefaultCracklibDict();
  }

  char *msg = (char*)FascistCheck(passwd, dict);

  v8::Local<v8::Object> ret = Nan::New<v8::Object>();

  if (!msg) {
    Nan::Set(ret, Nan::New("message").ToLocalChecked(), Nan::Null());
  } else {
    Nan::Set(ret, Nan::New("message").ToLocalChecked(), 
      Nan::New(msg).ToLocalChecked());
  }
  info.GetReturnValue().Set(ret);
}

/*!
 * \brief   Checks a password / user combination against the default cracklib
 *          dictionary.
 * \param   password  Password string to check
 * \param   user User to check.
 * \param   dictionaryPath Optional path to custom dictionary.
 * \return  Cracklib check result
 * 
 * The return value will be a dictionary object with a single member
 * named "message". If "message" is NULL the password is acceptable, in
 * all other cases "message" will contain the reason the password was rejected.
 */
void fascistCheckUser (const Nan::FunctionCallbackInfo<v8::Value>& info) {
  
  if (info.Length() < 2) {
    Nan::ThrowError(Nan::Error("fascistCheckUser(password, user[, dictionaryPath])"));
  }

  v8::Isolate* isolate = info.GetIsolate();
  v8::String::Utf8Value spass(isolate, info[0]);
  v8::String::Utf8Value suser(isolate, info[1]);

  const char *passwd  = *spass;
  const char *user    = *suser;
  const char *dict;

  if (info.Length() == 3) {
    v8::String::Utf8Value sdict(isolate, info[1]);
    dict = strdup(*sdict);
  } else {
    dict = GetDefaultCracklibDict();
  }
  char *msg           = (char*)FascistCheckUser(passwd, dict, user, NULL);

  v8::Local<v8::Object> ret = Nan::New<v8::Object>();

  if (!msg) {
    Nan::Set(ret, Nan::New("message").ToLocalChecked(), Nan::Null());
  } else {
    Nan::Set(ret, Nan::New("message").ToLocalChecked(), 
      Nan::New(msg).ToLocalChecked());
  }
  info.GetReturnValue().Set(ret);
}
    
void InitAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  Nan::SetMethod(exports, "fascistCheck", fascistCheck);
  Nan::SetMethod(exports, "fascistCheckUser", fascistCheckUser);
}

DISABLE_WCAST_FUNCTION_TYPE
NODE_MODULE(cracklib, InitAll)
DISABLE_WCAST_FUNCTION_TYPE_END
