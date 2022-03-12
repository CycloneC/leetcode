#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* a , const void* b)
{
    return *(int*)a - *(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int *left = NULL;
    int *middle = NULL;
    int *right = NULL;
    int sum = 0;

    *returnSize = 0;
    if (nums == NULL || numsSize < 3)
    {
        return NULL;
    }

    //升序排序
    qsort(nums, numsSize, sizeof(int), cmp_int);

    //申请内存空间    为什么要申请numsSize * numsSize的空间???有这么多个结果吗?
    int** ret = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize *sizeof(int));

    for (int i = 0; i < numsSize - 2; i++)
    {
        left = &nums[i];

        if (*left > 0)
        {
            return ret;
        }

        if ((i > 0) && (*left == *(left - 1)))
        {
            continue;
        }

        middle = left + 1;
        right = &nums[numsSize - 1];
        while (middle < right)
        {
            sum = *left + *middle + *right;
            if (sum == 0)
            {
                ret[*returnSize] = (int*)malloc(sizeof(int)*3);
                ret[*returnSize][0] = *left;
                ret[*returnSize][1] = *middle;
                ret[*returnSize][2] = *right;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while((middle < right) && (*middle == *(++middle)));
                while((middle < right) && (*right == *(--right)));
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                middle++;
            }
        }
    }

    return ret;
}

int main(void)
{
    int nums[] = {-1,0,1,2,-1,-4}; //[[-1,-1,2],[-1,0,1]]
    // int nums[] = {-1,2,-1}; //[[-1,-1,2],[-1,0,1]]
    // int nums[] = {0,0,0}; //[[-1,-1,2],[-1,0,1]]
    int returnSize = 0;
    int *returnColumnSizes = NULL;

    int **ret = threeSum(nums, sizeof(nums)/sizeof(int), &returnSize, &returnColumnSizes);
    printf("[ ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[ ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ret[i][j]);
        }
        printf("] ");
    }
    printf("] \n");

    printf("test over\n");
    return 0;
}

