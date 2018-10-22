#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <memory.h>

/*
 * leetcode第20题，括号匹配，用栈，腾讯2018秋招
 */


bool isValid(char*);
bool isValid(char* s) {

    int a[strlen(s)+1];
    int i = 0;
    while(*s != '\0')
    {
        switch(*s)
        {
            case '(' :
              a[i] = 0;
              i ++;
                break;
            case  ')':
                if(i == 0)
                    return false;
                else if (a[i-1] != 0)
                    return false;
                else
                    i --;
                break;
            case '[' :
                a[i] = 1;
                i ++;
                break;
            case  ']':
                if(i == 0)
                    return false;
                else if (a[i-1] != 1)
                    return false;
                else
                    i --;
                break;
            case '{' :
                a[i] = 2;
                i ++;
                break;
            case  '}':
                if(i == 0)
                    return false;
                else if (a[i-1] != 2)
                    return false;
                else
                    i --;
                break;
        }
        s++;
    }
    if (i == 0)
        return true;
    else
        return false;

}
int main() {
   if(isValid("()")&&isValid("[]")&&isValid("{}")&&isValid("[]{}()"))
       printf("OK");
   else
       printf("SORRY");
    return 0;
}