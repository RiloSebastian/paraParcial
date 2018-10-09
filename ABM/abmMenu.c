#include <stdio.h>
#include <stdlib.h>
#include "structsAbm.h"
#include "validations.h"
#define eLEN 1000

int menu(void)
{
    structure list[eLEN];
    int option;
    int flag=0;

    if(structure_init(list,eLEN))
    {
		if(structure_isEmpty(list,eLEN)>0)
		{
			flag=1;
		}
        do
        {
            printf("\n 1. ADD '_'\n");
            printf(" 2. MODIFY '_'\n");
            printf(" 3. REMOVE '_'\n");
            printf(" 4. SHOW\n");
            printf(" 5. EXIT\n");
            printf("\n Choose an option: ");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                if(structure_add(list,eLEN))
                {
                    printf("\n  '_' succesfully added.\n");
                    flag=1;
                }
                else
                {
                    printf(" Error. something happened.\n");
                }
                break;
            case 2:
                if(flag==1)
                {
                    structure_print(list,eLEN);
                    if(structure_modify(list,eLEN))
                    {
                        printf("\n  '_' succesfully modified.\n");
                    }
                    else
                    {
                        printf(" the '_' you tried to modify doesn't exist.\n");
                    }
                }
                else
                {
                    printf(" You can't modify an '_' if you haven't added any yet.\n");
                }
                break;
            case 3:
                if(flag==1)
                {
                    structure_print(list,eLEN);
                    if(structure_remove(list,eLEN))
                    {
                        printf("\n  '_' succesfully removed.\n");
                    }
                    else
                    {
                        printf(" the '_' you tried to remove doesn't exist.\n");
                    }
                }
                else
                {
                    printf(" You can't remove an '_' if you haven't added any yet.\n");
                }
                break;
            case 4:
                if(flag==1)
                {
                    if(structure_printSorted(list,eLEN))
                    {
                        printf("\n structure's list printed.\n");
                    }
                    else
                    {
                        printf("\n An error has ocurred.\n");
                    }
                }
                else
                {
                    printf(" You can't inform about the structures if you haven't added any yet.\n");
                }
                break;
            case 5:
                //salir
                break;
            default :
                printf("\n This option doesn't exist.\n");
                break;
            }
        }
        while(option!=5);
    }
    return 0;
}
