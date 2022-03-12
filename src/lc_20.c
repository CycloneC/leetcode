#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s)
{
    if (s == NULL)
    {
        return false;
    }

    int len = strlen(s);
    if (len == 0)
    {
        return false;
    }

    char *stack = (char *)malloc(len);
    char *p = s;
    char *head = stack;

    while (*p)
    {
        if ((*p == '(') || 
            (*p == '[') || 
            (*p == '{'))
        {
            *head = *p;
            head++;
        }
        else
        {
            if (head == stack)
            {
                return false;
            }
            
            if (((*p == ')') && (*(head - 1) == '(')) || 
                ((*p == ']') && (*(head - 1) == '[')) || 
                ((*p == '}') && (*(head - 1) == '{')))
            {
                head--;
            }
            else
            {
                return false;
            }
        }

        p++;
    }

    if (head != stack)
    {
        return false;
    }
    
    return true;
}

int main(void)
{
    char *s = "()";

    bool ret = isValid(s);
    printf("ret=%s", ret ? "true" : "false");
}
