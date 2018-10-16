//
// Created by dong on 18-9-10.
//
#include<stdio.h>
int main()
{
    char c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11;

    printf("\n***section1***********************\n");
    c1 = 'g';
    c2 = '<';
    c3 = '\n';
    printf("%c %c\n",c1,c2);
    putchar(c1);
    putchar(c2);
    putchar(c3);

    printf("\n***section2***********************\n");
    printf("Enter two characters without spaces,then press enter:\n");
    scanf("%c%c",&c4,&c5);
    putchar(c4);
    putchar(c5);
    printf("\n%d %d \n",c4,c5);

    printf("\n***section3***********************\n");
    printf("Enter two characters without spaces,then press enter:\n");
    getchar();
    c6 = getchar();
    c7 = getchar();
    putchar(c6);
    putchar(c7);
    putchar('\n');

    printf("\n***section4***********************\n");
    printf("Enter two more characters without spaces,then press enter:\n");  //注意two more
    fflush(stdin);  //在新的编译器中，这句话已经不起作用了
    //getchar();
    c8 = getchar();
    c9 = getchar();
     fflush(stdin);
    printf("%c%c \n",c8,c9);

    return 0;
}

