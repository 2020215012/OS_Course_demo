#include<stdio.h>
#include "mysem.h"
int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    mysem(s);
    return 0;
}