#include <stdio.h>
#include "myfifo.h"
int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    fifo(s);
}