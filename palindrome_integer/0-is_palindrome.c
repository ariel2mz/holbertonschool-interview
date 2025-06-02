#include <stdio.h>
#include "palindrome.h"

int is_palindrome(unsigned long n)
{
    unsigned long rev = 0, og = n, rem;

    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }

    return (og == rev) ? 1 : 0;
}
