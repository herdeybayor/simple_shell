#include "shell.h"

void prompt(char *c)
{
    while (*c != '\0')
    {
        _putchar(*c);
        c++;
    }
}
