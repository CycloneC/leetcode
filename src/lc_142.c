#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast)
    {
        slow = slow->next;
        if (fast->next == NULL)
        {
            return NULL;
        }
        fast = fast->next->next;

        if (fast != slow)
        {
            continue;
        }

        struct ListNode *p = head;
        while (p != slow)
        {
            p = p->next;
            slow = slow->next;
        }
        return p;
    }

    return NULL;
}

struct ListNode *test_data_creat(int *list, int size, int pos)
{
    struct ListNode *head = NULL;
    struct ListNode *p = NULL;

    if (list == NULL || size == 0)
    {
        return NULL;
    }

    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = list[0];
    head->next = NULL;
    p = head;

    for (int i = 1; i < size; i++)
    {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = list[i];
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }

    if (pos >= 0)
    {
        struct ListNode *temp = head;

        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }

        p->next = temp;
    }

    return head;
}

int main(void)
{
    int nums[] = {-1,-2,-3,-4, -5, -6};
    int pos = 4;

    struct ListNode *head = test_data_creat(nums, sizeof(nums)/sizeof(int), pos);
    struct ListNode *p = detectCycle(head);
    if (p)
    {
        printf("%d\n", p->val);
    }
    else
    {
        printf("NULL\n");
    }

    printf("test over\n");

    return 0;
}
