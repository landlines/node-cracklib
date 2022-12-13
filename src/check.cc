#include <stdlib.h>
#include <crack.h>

using namespace std;

char* check(char const passwd[], char const dictPath[])
{
    const char* dict;

    if (dictPath[0] == '\0')
    {
        dict = GetDefaultCracklibDict();
    }
    else
    {
        dict = dictPath;
    }

    return (char*)FascistCheck(passwd, dict);
}

char* checkUser(char const passwd[], char const dictPath[], char const user[],
    char const gecos[])
{
    const char* dict;

    if (dictPath[0] == '\0')
    {
        dict = GetDefaultCracklibDict();
    }
    else
    {
        dict = dictPath;
    }

    return (char*)FascistCheckUser(passwd, dict, user, gecos);
}