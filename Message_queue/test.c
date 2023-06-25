#include "msg_queue.h"
#include <stdio.h>
int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    talker(s);
    listener();
}