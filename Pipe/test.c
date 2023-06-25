#include<stdio.h>
#include "mypipe.h"
int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    mypipe(s);
    return 0;
}