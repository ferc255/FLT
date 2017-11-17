#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 200

void parse_non_term(char input[BUFFER_SIZE], int* start)
{
    char temp[BUFFER_SIZE];
    int i;
    for (i = *start; input[i] != '}'; i++)
    {
        temp[i - *start] = input[i];
    }
    temp[i - *start] = '\0';
    
    printf("            {\n                .type = \"%s\",\n", temp);
    printf("                .data = \"\",\n            },\n");
    *start = i + 1;
}

void parse_term(char input[BUFFER_SIZE], int* start)
{
    char temp[BUFFER_SIZE];
    bool comma = false;
    int i;
    for (i = *start; ; i++)
    {
        if (input[i] == ',')
        {
            comma = true;
            break;
        }
        if (input[i] == '>')
        {
            break;
        }
        temp[i - *start] = input[i];
    }
    temp[i - *start] = '\0';
    *start = i + 1;
    
    printf("            {\n                .type = \"%s\",\n", temp);
    if (!comma)
    {
        printf("                .data = \"\",\n            },\n");
    }
    else
    {
        for (i = *start; input[i] != '>'; i++)
        {
            temp[i - *start] = input[i];
        }
        temp[i - *start] = '\0';
        
        printf("                .data = \"%s\",\n            },\n", temp);
    }
    *start = i + 1;
}

void parse_rule(char input[BUFFER_SIZE], int idx)
{
    char temp[BUFFER_SIZE];
    
    if (idx == 0)
    {
        int i;
        for (i = 1; input[i] != '}'; i++)
        {
            temp[i - 1] = input[i];
        }
        temp[i - 1] = '\0';
        
        printf("    {\n        .list = (pair_t[])\n        {\n");
        printf("            {\n                .type = \"^\",\n");
        printf("                .data = \"\",\n");
        printf("            },\n");
        
        printf("            {\n                .type = \"%s\",\n", temp);
        printf("                .data = \"\",\n");
        printf("            },\n        },\n        .size = 2,\n    },\n");
    }
    
    printf("    {\n        .list = (pair_t[])\n        {\n");
    
    int size = 0;
    int i;
    for (i = 0; i < strlen(input); )
    {
        if (input[i] == '{')
        {
            size++;
            i++;
            parse_non_term(input, &i);
        }
        else if (input[i] == '<')
        {
            size++;
            i++;
            parse_term(input, &i);
        }
    }
    
    printf("        },\n        .size = %d,\n    },\n", size);
}

int main()
{
    char input[BUFFER_SIZE];
    int count = 0;
    
    printf(".prod = (prod_t[])\n{\n");
    
    while (fgets(input, sizeof input, stdin))
    {
        input[strlen(input) - 1] = '\0';
        parse_rule(input, count);
        count++;
        //printf("%s\n", temp);
    }
    
    printf("},\n.size = %d,\n", count + 1);
}