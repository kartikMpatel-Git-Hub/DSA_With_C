#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int empId;
    char *name;
    int age;
    int salary;
}Employee;

void getDetails(Employee *e){
    printf("\nEnter id :");
    scanf("%d",&e->empId);

    e->name = (char *)calloc(20,sizeof(char));
    printf("\nEnter Name :");
    scanf("%s",e->name);
    printf("\nEnter Age :");
    scanf("%d",&e->age);
    printf("\nEnter Salary :");
    scanf("%d",&e->salary);
}
void createEmployee(Employee *e,int noOfEmp){
    getDetails(&e[noOfEmp]);
}

void display(Employee *e,int n){
    Employee *temp = e;
    for(int i = 0; i < n; i++){
        printf("\nName : %s",temp->name);
        temp++;
    }
}

void main(){
    int ch = 1, size = 1,n = 0;
    Employee *e = (Employee *)calloc(size,sizeof(Employee));;
    printf("%d",e);
    while (1)
    {
        printf("\n0.Exit\t1.Add Employee\t2.Display");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                if(n == size){
                    printf("Realloc !");
                    size += size / 2;
                    e = (Employee *)realloc(e,size*sizeof(Employee));
                }
                createEmployee(e,n);
                n += 1;
                break;
            case 2:
                display(e,n);
                break;  
            case 0:
                return;
        }
        
    }
}