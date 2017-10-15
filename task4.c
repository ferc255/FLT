#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


const int BUFFER_SIZE = 300;
const int ERROR_STATE = -1;
const int NO_MATCH = -1;


typedef struct automaton_t
{
    int size;
    char* abbrev;
    bool* final;
    int** table;
} automaton_t;

typedef struct automaton_list_t
{
    int count;
    automaton_t* list;
} automaton_list_t;


int calc_max_match(automaton_t* automaton, char* input, int start_pos)
{
    int cur_state = 0;
    int result = automaton->final[0] ? 0 : NO_MATCH;
    
    int i;
    for (i = start_pos; i < strlen(input); i++)
    {
        cur_state = automaton->table[cur_state][input[i]];
        if (cur_state == ERROR_STATE)
        {
            return result;
        }
        if (automaton->final[cur_state])
        {
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


int main()
{
    automaton_list_t automs =
    {
        .count = 9,
        .list = (automaton_t[])
        {
            {
                .size = 4,
                .abbrev = "OP",
                .final = (bool[])
                {
                    false, true, true, true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['='] = 1,
                        ['<'] = 2,
                        ['>'] = 3, 
                        ['+'] = 1,
                        ['-'] = 1,
                        ['*'] = 1,
                        ['/'] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['='] = 1,
                        ['>'] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['='] = 1,
                    },
                },
            },
            {
                .size = 22,
                .abbrev = "KW",
                .final = (bool[])
                {
                    [0 ... 30] = false,
                    [21] = true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['b'] = 1,
                        ['e'] = 5,
                        ['i'] = 9,
                        ['l'] = 10,
                        ['t'] = 12,
                        ['v'] = 15,
                        ['w'] = 17,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['e'] = 2,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['g'] = 3,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['i'] = 4,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['n'] = 21,
                    },
                    (int[]) // 5
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['l'] = 6,
                        ['n'] = 8,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['s'] = 7,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['e'] = 21,
                    },
                    (int[]) // 8
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['d'] = 21,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['f'] = 21,
                        ['n'] = 21,
                    },
                    (int[]) // 10
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['e'] = 11,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['t'] = 21,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['h'] = 13,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['e'] = 14,
                    },
                    (int[]) // 14
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['n'] = 21,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['a'] = 16
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['l'] = 21,
                    },
                    (int[]) // 17
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['h'] = 18,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['i'] = 19,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['l'] = 20,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['e'] = 21,
                    },
                    (int[]) // 21
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                    },
                },
            },
            {
                .size = 3,
                .abbrev = "LC",
                .final = (bool[])
                {
                    false, false, true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['#'] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['f'] = 2,
                        ['t'] = 2,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                    },
                },
            },
            {
                .size = 3,
                .abbrev = "ID",
                .final = (bool[])
                {
                    false, true, true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['a' ... 'z'] = 1,
                        ['A' ... 'Z'] = 1,
                        ['<'] = 2,
                        ['>'] = 2,
                        ['!'] = 2,
                        ['#'] = 2,
                        ['+'] = 2,
                        ['-'] = 2,
                        ['*'] = 2,
                        ['/'] = 2,
                        ['&'] = 2,
                        ['$'] = 2,
                        ['@'] = 2,
                        ['~'] = 2,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['a' ... 'z'] = 1,
                        ['A' ... 'Z'] = 1,
                        ['0' ... '9'] = 1,
                        ['_'] = 1,
                        ['\''] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['<'] = 2,
                        ['>'] = 2,
                        ['!'] = 2,
                        ['#'] = 2,
                        ['+'] = 2,
                        ['-'] = 2,
                        ['*'] = 2,
                        ['/'] = 2,
                        ['&'] = 2,
                        ['$'] = 2,
                        ['@'] = 2,
                        ['~'] = 2,
                    },
                },
            },
            {
                .size = 2,
                .abbrev = "WS",
                .final = (bool[])
                {
                    false, true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        [' '] = 1,
                        ['\n'] = 1,
                        ['\t'] = 1,
                        ['\r'] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        [' '] = 1,
                        ['\n'] = 1,
                        ['\t'] = 1,
                        ['\r'] = 1,
                    },
                },
            },
            {
                .size = 2,
                .abbrev = "IN",
                .final = (bool[])
                {
                    false, true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 1,
                    },
                },
            },
            {
                .size = 7,
                .abbrev = "NM",
                .final = (bool[])
                {
                    [0 ... 6] = false,
                    [3] = true,
                    [6] = true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 1,
                        ['.'] = 2,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 1,
                        ['.'] = 3,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 3,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 3,
                        ['e'] = 4,
                        ['E'] = 4,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 6,
                        ['+'] = 5,
                        ['-'] = 5,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 6,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['0' ... '9'] = 6,
                    },
                },
            },
            {
                .size = 2,
                .abbrev = "LP",
                .final = (bool[])
                {
                    false, true
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        ['('] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                    },
                },
            },
            {
                .size = 2,
                .abbrev = "RP",
                .final = (bool[])
                {
                    false, true,
                },
                .table = (int*[])
                {
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                        [')'] = 1,
                    },
                    (int[])
                    {
                        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
                    },
                },
            },
        },
    }; 
    
    
    char input[BUFFER_SIZE];
    char temp[BUFFER_SIZE];
    while (fgets(temp, sizeof temp, stdin))
    {
        strcat(input, temp);
    }
    //printf("%s\n", input);
    
    int i;
    for (i = 0; i < strlen(input); )
    {
        char* abbrev;
        int max_match = NO_MATCH;
        int j;
        for (j = 0; j < automs.count; j++)
        {
            int cur_match = calc_max_match(&automs.list[j], input, i);
            if (cur_match > max_match)
            {
                max_match = cur_match;
                abbrev = automs.list[j].abbrev;
            }
        }
        
        if (max_match == NO_MATCH)
        {
            printf("Error while parsing.\n");
            return 0;
        }
        
        print_token(abbrev, input, i, max_match);
        i += max_match;
    }
    
    return 0;
}