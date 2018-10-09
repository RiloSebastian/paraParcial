#include <stdio.h>
#include <stdlib.h>
#include "abmMenu.h"
int main()
{
    int flag=1;
    flag=menu();
    if(flag==0)
    {
        printf("menu has ended.\n");
    }
    return 0;
}
