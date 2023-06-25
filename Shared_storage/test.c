#include<stdio.h>
#include "shared_storage.h"
int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    talker(s);
    listener();
    return 0;
}