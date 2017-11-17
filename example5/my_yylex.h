#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "values.h"

#define BUFFER_SIZE 300
//const int BUFFER_SIZE = 300;
const int ERROR_STATE = -1;
const int NO_MATCH = -1;


typedef struct automaton_t
{
    int size;
    char** final;
    int** table;
} automaton_t;

typedef struct automaton_list_t
{
    int count;
    automaton_t* list;
} automaton_list_t;


int calc_max_match(automaton_t* automaton, char* input, int start_pos, char** abbrev)
{
    int cur_state = 0;
    int result;
    if (automaton->final[0] == "")
    {
        result = NO_MATCH;
    }
    else
    {
        result = 0;
        *abbrev = automaton->final[0];
    }
    
    int i;
    for (i = start_pos; i < strlen(input); i++)
    {
        cur_state = automaton->table[cur_state][input[i]];
        
        if (cur_state == ERROR_STATE)
        {
            return result;
        }
        if (automaton->final[cur_state] != "")
        {
            *abbrev = automaton->final[cur_state];
            result = i - start_pos + 1;
        }
    }
    
    return result;
}


void print_token(char* abbrev, char* input, int start_pos, int len)
{
    printf("<%s, '", abbrev);
    
    int i;
    for (i = 0; i < len; i++)
    {
        char symbol = input[start_pos + i];
        if (symbol == 9)
        {
            printf("\\t");
        }
        else if (symbol == 10)
        {
            printf("\\n");
        }
        else if (symbol == 13)
        {
            printf("\\r");
        }
        else
        {
            printf("%c", symbol);
        }
    }
    
    printf("'>\n");
}


token_t my_yylex()
{
    automaton_t automaton =
    {
        #include "lex_automaton.h"
    }; 
    
    static bool is_initialized = false;
    static char input[BUFFER_SIZE];
    if (!is_initialized)
    {
        char temp[BUFFER_SIZE];
        while (fgets(temp, sizeof temp, stdin))
        {
            strcat(input, temp);
        }
        
        is_initialized = true;
    }
    
    static int i = 0;
    for (; i < strlen(input); )
    {
        token_t result;
        //printf("%d\n", i);
        int max_match = calc_max_match(&automaton, input, i, &result.type);
        
        if (max_match == NO_MATCH)
        {
            printf("[my_yylex.h] Error while parsing at %d position.\n", i);
            exit(0);
        }
        
        result.data = malloc(max_match);
        memcpy(result.data, input + i, max_match);
        
        i += max_match;
        
        if (strcmp(result.type, "WS") == 0)
        {
            continue;
        }
        
        return result;
    }
    
    token_t result = 
    {
        .type = "$",
        .data = "", //// ????????????? remove
    };
    
    return result;
}