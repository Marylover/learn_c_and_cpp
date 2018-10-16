#include <stdio.h>
int main()
{
    FILE *file_pointer;
    int math,English,Chinese;
    printf("please input your grades in the order of: math, English, Chinese:\n");
    scanf("%d%d%d",&math,&English,&Chinese);
    file_pointer = fopen("//home//dong//CLionProjects//file.OUT","w");
    fprintf(file_pointer,"math: %d\nEnglish: %d\nChinese: %d\nMean: %d",math,English,Chinese,(math+English+Chinese)/3);
    fclose(file_pointer);
    return 0;
}