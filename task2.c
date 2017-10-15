#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N 9


    const int BUFFER_SIZE = 300;
    const int ERROR_STATE = 5;
    const int ILLEGAL_CHAR = -1;
    const int NO_MATCH = -1;
    
    
int calc_max_match(int automaton[N][4], char* input, int start_pos, int* c2n, 
    bool* is_final)
{
    int cur_state = 0;
    int pos = start_pos;
    int result = is_final[0] ? 0 : NO_MATCH;
    
    for (;;)
    {
        if (pos >= strlen(input))
        {
            return result;
        }
        
        int symbol = c2n[input[pos]];
        if (symbol == ILLEGAL_CHAR)
        {
            return result;
        }
        
        cur_state = automaton[cur_state][symbol];
        if (cur_state == ERROR_STATE)
        {
            return result;
        }
        else if (is_final[cur_state])
        {
            result = pos - start_pos + 1;
        }
        pos++;
    }
}


int main()
{
    int c2n[(1 << CHAR_BIT)] = 
    {
        [0 ... (1 << CHAR_BIT) - 1] = ILLEGAL_CHAR,
        ['0' ... '9'] = 0,
        ['.'] = 1,
        ['e'] = 2,
        ['E'] = 2,
        ['+'] = 3,
        ['-'] = 3,
    };
    
    int automaton[N][4] =
    {
        {          6,           2, ERROR_STATE,           1},
        {          6,           2, ERROR_STATE, ERROR_STATE},
        {          7, ERROR_STATE, ERROR_STATE, ERROR_STATE},
        {          8, ERROR_STATE, ERROR_STATE,           4},
        {          8, ERROR_STATE, ERROR_STATE, ERROR_STATE},
        {ERROR_STATE, ERROR_STATE, ERROR_STATE, ERROR_STATE},
        {          6,           7,           3, ERROR_STATE},
        {          7, ERROR_STATE,           3, ERROR_STATE},
        {          8, ERROR_STATE, ERROR_STATE, ERROR_STATE},
    };
    
    bool is_final[] = 
    {
        false, false, false, false, false, false, true, true, true,
    };
    
    char input[BUFFER_SIZE];
    scanf("%s", input);
    
    int i;
    for (i = 0; i < strlen(input); )
    {
        int max_match = calc_max_match(automaton, input, i, c2n, is_final);
        if (max_match == NO_MATCH)
        {
            i++;
        }
        else
        {
            int j;
            for (j = 0; j < max_match; j++)
            {
                printf("%c", input[i++]);
            }
            printf("\n");
        }
    }
}