#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char *decodeStringCore(char **s)
{
    int num = 0;
    char *ret = (char *)calloc(5000, 1);
    char *pret = NULL;
    int ret_len = 0;

    while (**s != '\0')
    {
        if (isalpha(**s))
        {
            ret[ret_len++] = **s;
        }
        else if (isdigit(**s))
        {
            num = num * 10 + **s - '0';
        }
        else if (**s == '[')
        {
            (*s)++;
            pret = decodeStringCore(s);
            for (int i = 0; i < num; i++)
            {
                strcpy(ret + ret_len, pret);
                ret_len += strlen(pret);
            }
            
            free(pret);
            num = 0;
        }
        else // ']'
        {
            return ret;
        }

        (*s)++;
    }

    return ret;
}

char *decodeString(char *s)
{
    return decodeStringCore(&s);
}

int main(void)
{
    char *s = "60[lee]";

    char *ret = decodeString(s);
    printf("ret=%s\n", ret);
    free(ret);
}


