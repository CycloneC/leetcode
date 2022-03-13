/*
*    https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void* a , const void* b)
{
    return *(int*)a - *(int*)b;
}

int findUnsortedSubarray(int* nums, int numsSize)
{
    int left = 0;
    int right = 0;

    if ((nums == NULL) || (numsSize <= 1))
    {
        return 0;
    }

    int *p = (int *)malloc(numsSize * sizeof(int));
    memcpy(p, nums, numsSize * sizeof(int));

    //升序排序
    qsort(p, numsSize, sizeof(int), cmp_int);

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == p[i])
        {
            left++;
        }
        else
        {
            break;
        }
    }

    if (left == numsSize)
    {
        return 0;
    }

    for (int i = numsSize - 1; i >= 0; i--)
    {
        if(nums[i] == p[i])
        {
            right++;
        }
        else
        {
            break;
        }
    }
    
    return (numsSize - left - right);
}

/*双指针法*/
// int findUnsortedSubarray(int* nums, int numsSize)
// {
//     int max = nums[0], min = nums[numsSize - 1];
//     int begin = 0, end = -1;

//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] >= max)
//         {
//             max = nums[i];
//         }
//         else
//         {
//             end = i;
//         }

//         if (nums[numsSize - 1 - i] <= min)
//         {
//             min = nums[numsSize - 1 - i];
//         }
//         else
//         {
//             begin = numsSize - 1 - i;
//         }
//     }

//     printf("begin=%d, end=%d", begin, end);
//     return (end - begin + 1);
// }

int main(int argc, char **argv)
{
    int nums[] = {1,2,3,4,5};

    int ret = findUnsortedSubarray(nums, sizeof(nums)/sizeof(int));
    printf("ret = %d\n", ret);

    return 0;
}
