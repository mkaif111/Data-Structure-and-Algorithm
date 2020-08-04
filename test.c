#include<stdio.h>
#include<string.h>


int main(){
    char c[25];

    gets(c);
    printf("%s",c);
    
    int result = strcmp("kaif",c); // if both string is identical then it return 0 else any other value

    printf("%d\n",result);

    if (result==0){
        printf("Hello");
    }

}