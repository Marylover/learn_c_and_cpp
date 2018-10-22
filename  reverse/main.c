#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

/*
 * leetcode 第7题，翻转整数，注意判断溢出时机
 */
int  reverse(int);

int  reverse(int x)
{
    int result = 0;
    while(x != 0 ) //把这一句改为while(x)能显著提高运行速度
    {
        if (abs(result)> INT_MAX/10)  //溢出判断的时机和方式很重要，此处如果用if (abs(result*10)> INT_MAX)达不到目的,因为result*10会溢出
            return 0;
        result = result * 10;
        int carry = x %10;
        result = result + carry;
        x = x /10;
    }
    //result = result + x;
    return result;
}

int main() {
    printf("%d",reverse(1534236462));
    return 0;
}