#include <stdio.h>  //leetcode题解, 注意最后返回链表时要返回head->next,且注意返回顺序
#include <stdlib.h>
struct ListNode{
    int val;
    struct  ListNode * next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode * head, *s, *t;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    t = head ;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {

        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y +carry;
        carry = sum/10;
        s = (struct ListNode*) malloc(sizeof(struct ListNode));
        s->val = sum%10;
        t->next = s;
        t = s;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;

    }
    if (carry>0)
    {
        s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val = carry;
        t->next = s;
        t = s;
    }
    t->next = NULL;
    return  head->next;
};
int main()
{
    return  0;
}