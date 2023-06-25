#include <stdio.h>
#include "socket.h"
int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    client(s);
    return 0;
}