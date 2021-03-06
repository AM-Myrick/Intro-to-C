#include <stdio.h>
#include <string.h>
#include <strings.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    int length = strlen(y);
    for(int i = 0; i < length; i ++) {
        *x = *y;
        x++;
        y++;   
    }
    printf("%s\n", x); 
    printf("%s\n", y); 
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c) 
{
    while (*str != '\0')
    {
        if (*str == c)
        {
            char *ret_val = str;
            printf("%s", ret_val);
            return ret_val;
        }
        str++;
    }
    return 0;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{   
    char *temp = needle;

    while(*haystack != '\0') 
    {
        if(*haystack == *needle) 
        {
            char *first_inst = haystack;
            while(*needle == *haystack && *needle != '\0') 
            {
                needle++;
                haystack++;
            }
            if(*needle == '\0') 
            {
                return first_inst;
            }
            needle = temp;
        }
        haystack++;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
