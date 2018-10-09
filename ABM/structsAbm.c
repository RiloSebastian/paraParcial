#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structsAbm.h"
#include "validations.h"

int structure_init(structure array[], int len)
{
    int i;
    int flag=1;
    if(array != NULL)
    {
        for(i=0; i<len; i++)
        {
            /*strncpy(array[i].name,"---",sizeof(array[i].name));
            strncpy(array[i].lastName,"---",sizeof(array[i].lastName));
            array[i].sector=0;
            array[i].salary=0;
            array[i].isEmpty=1;*/
        }

        /*int id[5]= {1,2,3,4,5};
        char name[5][51]= {"Juan","Luis","Maria","Jose","emiliano"};
        char lastName[5][51]= {"juanes","alvarez","balbin","iglesias","johnson"};
        int sector[5]= {1,1,2,3,3};
        float salary[5]= {13.50,150.25,400.60,80.75,1500.30};
        int isEmpty[5]= {0,0,0,0,0};*/

        for(i=0; i<5; i++)
        {
            /*strncpy(array[i].name,name[i],sizeof(array[i].name));
            strncpy(array[i].lastName,lastName[i],sizeof(array[i].lastName));
            array[i].sector=sector[i];
            array[i].salary=salary[i];
            array[i].id=id[i];
            array[i].isEmpty=isEmpty[i];*/
        }

    }
    return flag;
}


int structure_printSorted(structure array[], int len)
{
     int flag=0;
    int order=-1;
    int i;

    if(array != NULL && len >0)
    {
            printf("descendant(0) or ascendant(1) order?: ");
            order=set_marginInt(order,0,1);
            structure_sort(array,len,order);
           /* printf("  sector       last name                name                 id        salary\n");
            printf("---------------------------------------------------------------------------------\n");*/
            for(i=0; i<len; i++)
            {
                structure_printOne(array,len,i);
                flag=1;
            }
            //structure_averageSalary(array,len);
    }
    return flag;
}



int structure_print(structure array[], int len)
{
    int flag=0;
    int i;

    if(array != NULL && len >0)
    {
            /*structure_sort(array,len,1);
            printf("\n  Sector       Last name                Name                 Id        Salary\n");
            printf("---------------------------------------------------------------------------------\n");*/
            for(i=0; i<len; i++)
            {
                structure_printOne(array,len,i);
                flag=1;
            }

    }
    return flag;
}

int structure_printOne(structure array[],int len,int id)
{
    int flag=0;
    if(array != NULL && len>0 && id < len && id >= 0 && array[id].isEmpty==0)
    {
       /* printf(" %5d       %10s            %10s            %5d         $%5.2f\n",array[id].sector,array[id].lastName,array[id].name,array[id].id,array[id].salary);
        flag=1;*/
    }

    return flag;
}

int search_closestEmptySpace(structure array[], int len)
{
    int index=0;
    int i;

    if(array != NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if((array[i].isEmpty)==1)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int structure_isEmpty(structure array[], int len)
{
    int notEmpty=0;
    int i;
	
	if(array != NULL)
	{	
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==0)
			{
				notEmpty++;
			}
		}
	}
	return notEmpty;
}

int structure_setId(structure array[], int len)
{
    static int id=0;
    static int flag=0;
    int i;
    if(array != NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
           if(array[i].isEmpty==0 && array[i].id > id && flag==0)
           {
               id= array[i].id;
           }
        }
        id=id+1;
        flag=1;
    }

    return id;
}

int structure_add(structure array[], int len)
{
    int flag=0;
    int index;
    int id;
    char name[50];
    char lastName[50];
    float salary=0;
    int sector=0;
    int isEmpty=0;

    if(array != NULL && len >0)
    {
        index=search_closestEmptySpace(array,len);
        /*printf(" Set the name: ");
        set_name(name,sizeof(name));
        printf(" Set the last name: ");
        set_name(lastName,sizeof(lastName));
        printf(" Set sector(1/10): ");
        sector=set_marginInt(sector,1,10);
        printf(" Set salary: ");
        salary= set_float(salary);*/
        id=structure_setId(array,len);
        isEmpty=0;

        /*strncpy(array[index].name,name,sizeof(array[index].name));
        strncpy(array[index].lastName,lastName,sizeof(array[index].lastName));
        array[index].sector=sector;
        array[index].salary=salary;*/
        array[index].id=id;
        array[index].isEmpty=isEmpty;
        /*printf("\n  Sector       Last name                Name                 Id        Salary\n");
        printf("---------------------------------------------------------------------------------\n");*/
        structure_printOne(array,len,index);
        flag=1;
    }

    return flag;
}

int structure_remove(structure array[], int len)
{
    int flag=0;
    int id=0;
    int index=0;
    int isEmpty=1;
    printf(" Choose an '_' by id to remove: ");
    id=set_marginInt(id,1,len);
    index=structure_findById(array,len,id);
    if(index> -1)
    {
        array[index].isEmpty=isEmpty;
        flag=1;
    }

    return flag;
}



int structure_findById(structure array[], int len, int id)
{
    int i;
    int index=-1;
    if(array!= NULL && len>0 && id< len && id > 0)
    {
        for(i=0; i<len; i++)
        {
            if(array[i].id==id && array[i].isEmpty==0)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}


int structure_modify(structure array[], int len)
{
    int flag=0;
    int option;
    char stay;
    int index;
    int id=0;
    /*char name[50];
    char lastName[50];
    float salary=0;
    int sector=0;*/

    if(array != NULL && len >0)
    {
        printf(" Choose an '_' by id to modify: ");
        id=set_marginInt(id,1,len);
        index=structure_findById(array,len,id);
        if(index> -1)
        {
            do
            {
                printf(" What do you want to change?\n name(1)  last name(2)  sector(3)  salary(4)\n option: ");
                option=set_marginInt(option,1,4);
                switch(option)
                {
                case 1:

                    /*printf(" Set the name: ");
                    set_name(name,sizeof(name));
                    strncpy(array[index].name,name,sizeof(array[index].name));*/
                    break;
                case 2:
                    /*printf(" Set the last name: ");
                    set_name(lastName,sizeof(lastName));
                    strncpy(array[index].lastName,lastName,sizeof(array[index].lastName));*/
                    break;
                case 3:
                    /*printf(" Set sector(1/10): ");
                    sector=set_marginInt(sector,1,10);
                    array[index].sector=sector;*/
                    break;
                case 4:
                    /*printf(" Set salary: ");
                    salary= set_float(salary);
                    array[index].salary=salary;*/
                    break;
                default :
                    printf(" This option doesn't exist.\n");
                    break;
                }
               /* printf("\n  Sector       Last name                Name                 Id        Salary\n");
                printf("---------------------------------------------------------------------------------\n");*/
                structure_printOne(array,len,index);
                printf("\n Do you want to make more changes?(s to stay): ");
                stay=getc(stdin);
            }
            while(stay == 's');
            flag=1;

        }
    }

    return flag;
}

int structure_sort(structure array[], int len, int order)
{
    int flag=0;
    int i;
    int j;
    structure aux;

    if(array != NULL && len > 0)
    {

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(order==0)
                {
                    if(array[i]. < array[j].)
                    {
                        aux=array[i];
                        array[i]=array[j];
                        array[j]= aux;
                    }
                    else if(array[i]. == array[j]. && strcmp(array[i]. ,array[j].)<0)
                    {
                        aux=array[i];
                        array[i]=array[j];
                        array[j]= aux;
                        flag=1;
                    }
                }
                else if(order==1)
                 {
                    if(array[i]. > array[j].)
                    {
                        aux= array[j];
                        array[j]= array[i];
                        array[i]= aux;
                        flag=1;
                    }
                    else if(array[i]. == array[j]. && strcmp(array[i]. ,array[j].)>0)
                    {
                        aux= array[j];
                        array[j]= array[i];
                        array[i]= aux;
                        flag=1;
                    }
                 }
            }
        }
    }
    return flag;
}


int structure_averageSalary(structure array[], int len)
{
    int flag=0;
    int ammountOfstructures=0;
    float totalSalary=0;
    float averageSalary=0;
    int i;
    int j;

    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty==0)
            {
                ammountOfstructures++;
                totalSalary= totalSalary+array[i].salary;
            }
        }
        averageSalary=totalSalary/ammountOfstructures;
        printf("\n The total salary is of: $%.2f\n",totalSalary);
        printf(" The average salary is of: $%.2f\n",averageSalary);
        printf("\n structures with an above average salary:");
        printf("\n  Sector       Last name                Name                 Id        Salary\n");
        printf("---------------------------------------------------------------------------------\n");
        for(j=0;j<len;j++)
        {
            if(array[j].salary > averageSalary)
            {
                structure_printOne(array,len,j);
            }
        }
    }
    return flag;
}

