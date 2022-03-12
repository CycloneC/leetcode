#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int cmp_int(const void* a , const void* b)
// {
//     return *(int*)a - *(int*)b;
// }

// int findUnsortedSubarray(int* nums, int numsSize)
// {
//     int left = 0;
//     int right = 0;

//     if ((nums == NULL) && (numsSize <= 1))
//     {
//         return 0;
//     }

//     int *p = (int *)malloc(numsSize * sizeof(int));
//     memcpy(p, nums, numsSize * sizeof(int));

//     //升序排序
//     qsort(p, numsSize, sizeof(int), cmp_int);

//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] == p[i])
//         {
//             left++;
//         }
//         else
//         {
//             break;
//         }
//     }

//     if (left == numsSize)
//     {
//         return 0;
//     }

//     for (int i = numsSize - 1; i >= 0; i--)
//     {
//         if(nums[i] == p[i])
//         {
//             right++;
//         }
//         else
//         {
//             break;
//         }
//     }
    
//     return (numsSize - left - right);
// }

int findUnsortedSubarray(int* nums, int numsSize)
{
    int left = 0;
    int right = 0;

    if ((nums == NULL) && (numsSize <= 1))
    {
        return 0;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (left == numsSize - 1)
        {
            return 0;
        }

        if((nums[left] < nums[left + 1]) && (nums[left + 1] < nums[right]))
        {

        }

    }
}

int main(int argc, char **argv)
{
    int nums[] = {2,6,4,8,10,9,15};

    int ret = findUnsortedSubarray(nums, sizeof(nums)/sizeof(int));
    printf("ret = %d\n", ret);

    return 0;
}
