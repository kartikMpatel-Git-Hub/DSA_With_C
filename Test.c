#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void swap(char *str1,char *str2){
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}
void main(){
    char *str1 = "hello";
    char *str2 = "world";

    // printf("%s\t%s",str1,str2);
    swap(str1,str2);
    printf("%s\t%s",str1,str2);
}