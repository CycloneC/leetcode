#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// 破解超时
// bool hasCycle(struct ListNode *head) {
//     struct ListNode *temp = head;
//     struct ListNode *temp1;

//     if ((head == NULL) || (head->next == NULL))
//     {
//         return false;
//     }

//     while (temp->next)
//     {
//         temp1 = head;
//         while(temp1 && temp1 != temp)
//         {
//             if (temp->next == temp1)
//             {
//                 return true;
//             }

//             temp1 = temp1->next;
//         }

//         temp = temp->next;
//     }

//     return false;
// }

bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast)
    {
        slow = slow->next;
        if (fast->next == NULL)
        {
            return false;
        }
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
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
    int nums[] = {-1,-2,-3,-4};
    int pos = 2;

    struct ListNode *head = test_data_creat(nums, sizeof(nums)/sizeof(int), pos);
    bool ret = hasCycle(head);
    printf("%s", ret ? "true": "false");

    return 0;
}
