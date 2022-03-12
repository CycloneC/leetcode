#include <stdio.h>
#include <stdlib.h>

/* 暴力法 超时未通过测试*/
// int maxArea(int *height, int heightSize)
// {
//     int max = 0;

//     if ((height == NULL) || (heightSize < 2))
//     {
//         return 0;
//     }

//     for (int i = 0; i < heightSize - 1; i++)
//     {
//         for (int j = i + 1; j < heightSize; j++)
//         {
//             int width = j - i;
//             int high = height[i] > height[j] ? height[j] : height[i];
//             int area = width * high;
//             max = area > max ? area : max;
//         }
//     }

//     return max;
// }

//双指针
int maxArea(int *height, int heightSize)
{
    int max = 0;
    int temp = 0;
    int *left = NULL;
    int *right = NULL;

    if ((height == NULL) || (heightSize < 2))
    {
        return 0;
    }

    left = &height[0];
    right = &height[heightSize - 1];

    while (left != right)
    {
        if (*left > *right)
        {
            temp = (right - left) * (*right);
            right--;
        }
        else
        {
            temp = (right - left) * (*left);
            left++;
        }

        max = max > temp ? max : temp;
    }
    
    return max;
}

int main(void)
{
    // int height[] = {1,8,6,2,5,4,8,3,7}; //49
    // int height[] = {1,1}; //1
    int height[] = {4,3,2,1,4}; //16
    // int height[] = {1,2,1}; //2
    
    int ret = maxArea(height, sizeof(height)/sizeof(int));
    printf("ret = %d\n", ret);

    printf("test over\n");
    return 0;
}
