#include <stdio.h>
typedef struct a
{
    char** list; 
} a;

int main()
{
    a b = 
    {
        .list = (char*[])
        {
            "aba","cab",
        }
    };
    
    printf("%s\n", b.list[0]);
}