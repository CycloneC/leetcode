#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* left = head;
    struct ListNode* right = NULL;

    if (head->next)
    {
        right = head->next;
    }
    else
    {
        return NULL;
    }

    for (int i = 1; i < n; i++)
    {
        right = right->next;
    }

    if (right == NULL)
    {
        return head->next;
    }

    while (right->next)
    {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;

    return head;
}

struct ListNode *test_data_creat(int *list, int size)
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

    return head;
}

/* 遍历链表 */
void traverse_list(struct ListNode *List)
{
    struct ListNode *ptr = List;

    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }

    printf("\n");
}

int main(void)
{
    int nums[] = {-1,-2,-3,-4,-5};
    int pos = 5;

    struct ListNode *head = test_data_creat(nums, sizeof(nums)/sizeof(int));
    traverse_list(head);
    struct ListNode *ret = removeNthFromEnd(head, pos);
    traverse_list(ret);

    return 0;
}
