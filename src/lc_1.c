#include <stdio.h>
#include <stdlib.h>

/* ±©Á¦·¨ */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    if ((nums == NULL) || (returnSize == NULL) || (numsSize < 2))
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *ret = calloc(2, sizeof(int));
                if(ret == NULL)
                {
                    *returnSize = 0;
                    return NULL;
                }

                ret[0] = i;
                ret[1] = j;

                *returnSize = 2;
                return ret;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int main(void)
{
    int returnSize;
    int target = 6;
    int nums[] = {3,2,4};
    
    int *p = twoSum(nums, sizeof(nums)/sizeof(int), target, &returnSize);
    if (p != NULL)
    {
        printf("p0 = %d, p1 = %d\n", p[0], p[1]);
    }
    free(p);

    printf("test over\n");
    return 0;
}
