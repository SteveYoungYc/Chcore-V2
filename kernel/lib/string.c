#include <common/types.h>

char *strcpy(char *dest, const char *src)
{
        size_t i;
        for (i = 0; src[i] != '\0'; i++) {
                dest[i] = src[i];
        }
        dest[i] = '\0';
        return dest;
}

char *strncpy(char *dest, const char *src, size_t n)
{
        size_t i;
        for (i = 0; i < n && src[i] != '\0'; i++) {
                dest[i] = src[i];
        }
        for (; i < n; i++) {
                dest[i] = '\0';
        }
        return dest;
}

int strcmp(const char *s1, const char *s2)
{
        while (*s1 && *s1 == *s2) {
                s1++;
                s2++;
        }
        return (int)((u8)*s1 - (u8)*s2);
}

int strncmp(const char *s1, const char *s2, size_t n)
{
        while (n && *s1 && *s1 == *s2) {
                n--;
                s1++;
                s2++;
        }
        return n == 0 ? 0 : (int)((u8)*s1 - (u8)*s2);
}

size_t strlen(const char *s)
{
        size_t i;
        for (i = 0; *s; i++) {
                s++;
        }
        return i;
}

char *strstr(const char *haystack, const char *needle)
{
        size_t needle_len = strlen(needle);
        for (size_t i = 0; haystack[i] != '\0'; i++) {
                if (strncmp(haystack + i, needle, needle_len) == 0) {
                        return (char *)haystack + i;
                }
        }
        return NULL;
}

char *strcat(char *dest, const char *src)
{
        size_t dest_len = strlen(dest);
        size_t i;
        for (i = 0; src[i] != '\0'; i++) {
                dest[dest_len + i] = src[i];
        }
        dest[dest_len + i] = '\0';
        return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
        size_t dest_len = strlen(dest);
        size_t i;
        for (i = 0; i < n && src[i] != '\0'; i++) {
                dest[dest_len + i] = src[i];
        }
        dest[dest_len + i] = '\0';
        return dest;
}
