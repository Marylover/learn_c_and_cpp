#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int myAtoi(char *);

int myAtoi(char *str)
{

    int flag = 0 ;
    int i = 0,  num = 0;
    long long number = 0;


    while(str[i] == ' ')
        i++;
    if(str[i] == '-')
    {
        flag = 1;
        i ++ ;
    }
    else if (str[i] == '+')
    {
        flag = 0;
        i ++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        num = str[i] - '0';
        number = number* 10 + num;
        //注意一定要在这个循环中判断范围，否则可能会因为最终的结果超出范围而运行错误
        if(number > INT_MAX)
            return flag? INT_MIN:INT_MAX;
        i ++ ;
    }
     if(flag)
        return -number;
    else
        return number;


}

int main() {
    printf("%d",myAtoi("922337203685477580000"));
    return 0;
}