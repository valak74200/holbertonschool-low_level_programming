#include "main.h"
#include <stdio.h>

/**
 * *rot13 - rotate by 13 places
 * @str: string to be encoded
 * @base: base of uppercases or smallercases
 * Return: the resulting string
 */
char *rot13(char *str)
{
    char *ptr = str;
    int i = 0;

    while (str[i])
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            char base = (str[i] >= 'a') ? 'a' : 'A';
            str[i] = ((str[i] - base + 13) % 26) + base;
        }
        i++;
    }
    return ptr;
}

int main(void)
{
    char str[] = "ROT13 (\"rotate by 13 places\", sometimes hyphenated ROT-13)\
    is a simple letter substitution cipher.";

    printf("%s\n", rot13(str));

    return (0);
}