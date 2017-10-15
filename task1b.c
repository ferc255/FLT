#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


    const int BUFFER_SIZE = 300;
    const int ERROR_STATE = 8;
    const int ILLEGAL_CHAR = -1;
    
    
typedef struct
{
    int size;
    int* states_list;
} state_t;

typedef struct 
{
    int size;
    state_t* col;
} autom_row_t;

typedef struct
{
    int count;
    autom_row_t* row;
} automaton_t;


int main()
{
    int c2n[(1 << CHAR_BIT)] = 
    {
        [0 ... (1 << CHAR_BIT) - 1] = ILLEGAL_CHAR,
        ['L'] = 0,
        ['R'] = 1,
    };
    
    automaton_t automaton =
    {
        .count = 7,
        .row = (autom_row_t[])
        {
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            4, 2, 1,
                        },
                    },
                    {
                        .size = 1,
                        .states_list = (int[])
                        {
                            ERROR_STATE,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            5, 3, ERROR_STATE,
                        },
                    },
                    {
                        .size = 2,
                        .states_list = (int[])
                        {
                            ERROR_STATE, 0,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            6, ERROR_STATE, 3,
                        },
                    },
                    {
                        .size = 2,
                        .states_list = (int[])
                        {
                            ERROR_STATE, 0,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 2,
                        .states_list = (int[])
                        {
                            7, ERROR_STATE,
                        },
                    },
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            ERROR_STATE, 1, 2,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            ERROR_STATE, 6, 5,
                        },
                    },
                    {
                        .size = 2,
                        .states_list = (int[])
                        {
                            0, ERROR_STATE,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 2,
                        .states_list = (int[])
                        {
                            7, ERROR_STATE,
                        },
                    },
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            1, ERROR_STATE, 4,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 2,
                        .states_list = (int[])
                        {
                            ERROR_STATE, 7,
                        },
                    },
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            2, 4, ERROR_STATE,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 1,
                        .states_list = (int[])
                        {
                            ERROR_STATE,
                        },
                    },
                    {
                        .size = 3,
                        .states_list = (int[])
                        {
                            3, 5, 6,
                        },
                    },
                },
            },
            {
                .size = 2,
                .col = (state_t[])
                {
                    {
                        .size = 1,
                        .states_list = (int[])
                        {
                            ERROR_STATE,
                        },
                    },
                    {
                        .size = 1,
                        .states_list = (int[])
                        {
                            ERROR_STATE,
                        },
                    },
                },
            },
        }
    };

    char input[BUFFER_SIZE];
    scanf("%s", input);

    bool cur_states[automaton.count];
    memset(cur_states, false, sizeof cur_states);
    cur_states[0] = true;
    
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        int symbol = c2n[input[i]];
        if (symbol == ILLEGAL_CHAR)
        {
            memset(cur_states, false, sizeof cur_states);
            break;
        }
        else
        {	
            bool new_states[automaton.count];
            memset(new_states, false, sizeof new_states);
            
            bool good_state_is_found = false;
            int j;
            for (j = 0; j < automaton.count; j++)
            {
                if (cur_states[j])
                {
                    int k;
                    for (k = 0; k < automaton.row[j].col[symbol].size; k++)
                    {
                        new_states[automaton.row[j].col[symbol].states_list[k]]
                            = true;
                    }
                    good_state_is_found |= j < ERROR_STATE;
                }
            }
            memcpy(cur_states, new_states, sizeof cur_states);
            
            if (!good_state_is_found)
            {
                break;
            }
        }
    }

    if (cur_states[0])
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    } 
    
    return 0;
}