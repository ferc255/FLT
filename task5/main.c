#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "values.h"
#include "my_yylex.h"


int get_token_id(token_list_t* token_list, token_t* token)
{
    int result = NOT_FOUND;
    int i;
    for (i = 0; i < token_list->size; i++)
    {
        if (strcmp(token_list->list[i].type, token->type) == 0)
        {
            //printf("-----\n");
            //printf("%s %s\n", token_list->list[i].data, token->data);
            if (strcmp(token_list->list[i].data, token->data) == 0)
            {
                //printf("YES, ENTER\n");
                return i;
            }
            if (strcmp(token_list->list[i].data, "") == 0)
            {
                result = i;
            }
            //printf("----------\n");
        }
    }
    
    return result;
}


bool syntax_parse(tables_t* tables)
{
    int state[100] = {};
    int state_top = 0;
    
    token_t input = my_yylex();
    printf("%s %s\n", input.type, input.data);
    
    int derivation[100];
    int derivation_ptr = 0;
    while (true)
    {
        int cur_state = state[state_top];
        int column = get_token_id(&tables->token_list, &input);
        if (column == NOT_FOUND)
        {
            printf("Invalid token for the grammar.\n");
            return false;
        }
        //printf("%d\n", column);
        table_cell_t cell = tables->trans[cur_state][column];
        printf("%d %d %d %d\n", cur_state, column, cell.action, cell.num);
        switch (cell.action)
        {
            case AC_SHIFT:
                state[++state_top] = cell.num;
                input = my_yylex();
                printf("%s %s\n", input.type, input.data);
                break;
            case AC_REDUCE:
                derivation[derivation_ptr++] = cell.num;
                state_top -= tables->grammar_size[cell.num];
                cur_state = state[state_top];
                printf("%d\n", cur_state);
                state[++state_top] = 
                    tables->trans[cur_state][tables->grammar_left[cell.num]].num;
                printf("%d\n", state[state_top]);
                break;
            case AC_ERROR:
                printf("Column = %d\n", column);
                printf("Invalid token for %d-th state\n", cur_state);
                return false;
                
            case AC_ACCEPT:
                printf("Rightmost derivation: ");
                
                int i;
                for (i = derivation_ptr - 1; i >= 0; i--)
                {
                    printf("%d ", derivation[i]);
                }
                printf("\n");
                
                return true;
        }
    }
    return true;
}


int main()
{
    /*
    tables_t tables =
    {
        .grammar_size = (int[])
        {
            2, 2, 1,
        },
        .grammar_left = (int[])
        {
            3, 4, 4,
        },
        .token_list = 
        {
            .size = 5,
            .list = (token_t[])
            {
                {
                    .type = "calpha",
                    .data = "",
                },
                {
                    .type = "dalpha",
                    .data = "", ////// ???????? remove
                },
                {
                    .type = "$",
                    .data = "",
                },
                {
                    .type = "S",
                    .data = "",
                },
                {
                    .type = "C",
                    .data = "",
                },
            },
        },
        .trans = (table_cell_t*[])
        {
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 3},
        		{AC_SHIFT, 4},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 1},
        		{AC_SHIFT, 2},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ACCEPT, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 6},
        		{AC_SHIFT, 7},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 5},
        	},
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 3},
        		{AC_SHIFT, 4},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 8},
        	},
        	(table_cell_t[])
        	{
        		{AC_REDUCE, 0},
        		{AC_REDUCE, 2},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_REDUCE, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 6},
        		{AC_SHIFT, 7},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 9},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_REDUCE, 2},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_REDUCE, 1},
        		{AC_REDUCE, 1},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_REDUCE, 1},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        },
    };
    */
    
    tables_t tables =
    {
        .grammar_size = (int[])
        {
            4, 2, 2,
        },
        .grammar_left = (int[])
        {
            4, 5, 5,
        },
        .token_list = 
        {
            .size = 7,
            .list = (token_t[])
            {
                {
                    .type = "RR",
                    .data = "",
                },
                {
                    .type = "TOK",
                    .data = "kut",
                },
                {
                    .type = "TOK",
                    .data = "ca",
                },
                {
                    .type = "TOK",
                    .data = "",
                },
                {
                    .type = "sen",
                    .data = "",
                },
                {
                    .type = "C",
                    .data = "",
                },
                {
                    .type = "$",
                    .data = "",
                },
            },
        },
        .trans = (table_cell_t*[])
        {
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 1},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 4},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 2},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 3},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 7},
        		{AC_SHIFT, 6},
        		{AC_SHIFT, 6},
        		{AC_SHIFT, 6},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 5},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ACCEPT, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_REDUCE, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_SHIFT, 7},
        		{AC_SHIFT, 6},
        		{AC_SHIFT, 6},
        		{AC_SHIFT, 6},
        		{AC_ERROR, 0},
        		{AC_SHIFT, 8},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_SHIFT, 9},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_REDUCE, 1},
        	},
        	(table_cell_t[])
        	{
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_ERROR, 0},
        		{AC_REDUCE, 2},
        	},
        },
    };
    
    if (!syntax_parse(&tables))
    {
        return (EXIT_FAILURE);
    }
    
    return (EXIT_SUCCESS);
    //printf("%d\n", tables.trans[0][2].num);
}