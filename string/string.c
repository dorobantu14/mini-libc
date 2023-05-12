// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    char *dest = destination;
    const char *src = source;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    char *dest = destination;
    const char *src = source;

    for (int i = 0; i < (int)len; i++)
    {
        *dest = src[i];
        dest++;
    }

    return destination;
}

char *strcat(char *destination, const char *source)
{
    char *dest = destination;
    const char *src = source;
    if (dest == NULL)
    {
        return (char *)source;
    }
    else
    {
        strcpy(dest + strlen(dest), src);
        return destination;
    }
}

char *strncat(char *destination, const char *source, size_t len)
{
    char *dest = destination + strlen(destination);
    const char *src = source;

    while (*src != '\0' && len--)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
    if (strlen(str1) > strlen(str2))
    {
        return 1;
    }
    else if (strlen(str1) < strlen(str2))
    {
        return -1;
    }
    else
    {
        while (*str1 != '\0' && *str2 != '\0')
        {
            if (*str1 != *str2)
            {
                if (*str1 > *str2)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                str1++;
                str2++;
            }
        }

        return 0;
    }
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    for (int i = 0; i < (int)len; i++)
    {
        if (str1[i] != str2[i])
        {
            return -1;
        }
    }

    return 0;
}

size_t strlen(const char *str)
{
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c)
{
    while (*str != '\0')
    {
        if (*str == c)
        {
            return (char *)str;
        }
        str++;
    }

    return NULL;
}

char *strrchr(const char *str, int c)
{
    const char *string = str;
    const char *initialString = str;
    while (*str != '\0')
    {
        if (*str == c)
        {
            string = str;
        }
        str++;
    }
    if (string != initialString)
    {
        return (char *)string;
    }
    else
    {
        return NULL;
    }
}

char *strstr(const char *haystack, const char *needle)
{
    while (*haystack != '\0')
    {
        if (*haystack == *needle)
        {
            if (strncmp(haystack, needle, strlen(needle)) == 0)
            {
                return (char *)haystack;
            }
        }
        haystack++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    char *finalHaystack = (char *)haystack;
    char *initialHaystack = (char *)haystack;
    while (*haystack != '\0')
    {
        if (*haystack == *needle)
        {
            if (strncmp(haystack, needle, strlen(needle)) == 0)
            {
                finalHaystack = (char *)haystack;
            }
        }
        haystack++;
    }
    if (finalHaystack != initialHaystack)
    {
        return finalHaystack;
    }
    else
    {
        return NULL;
    }
}

void *memcpy(void *destination, const void *source, size_t num)
{
    char *dest = destination;
    const char *src = source;
    for (int i = 0; i < (int)num; i++)
    {
        dest[i] = src[i];
    }

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = destination;
    const char *src = source;

    if (src < dest && src + num > dest)
    {
        src += num;
        dest += num;
        while (num--)
        {
            *--dest = *--src;
        }
    }
    else
    {
        while (num--)
        {
            *dest++ = *src++;
        }
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    const char *dest = ptr1;
    const char *src = ptr2;
    for (int i = 0; i < (int)num; i++)
    {
        if (dest[i] != src[i])
        {
            return -1;
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
    char *src = source;
    for (int i = 0; i < (int)num; i++)
    {
        src[i] = value;
    }

    return source;
}
