#include <stdio.h>
int main()
{
    FILE *file_pointer;
    float a=0, b=0, c=0, d=0;
    file_pointer = fopen("//home//dong//CLionProjects//file.IN","r");
    fscanf(file_pointer,"%f%f%f%f",&a,&b,&c,&d);
    fclose(file_pointer);
    printf("The average of this numbers is %f",(a+b+c+d)/4);

}