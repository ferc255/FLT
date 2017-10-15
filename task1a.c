#include <limits.h>
#include <stdio.h>
#include <string.h>

#define N 9

    const int BUFFER_SIZE = 300;
    const int ERROR_STATE = 8;
    const int ILLEGAL_CHAR = -1;

int main()
{
    int c2n[(1 << CHAR_BIT)] =
    {
        [0 ... (1 << CHAR_BIT) - 1] = ILLEGAL_CHAR,
        ['('] = 0,
        ['['] = 1,
        ['{'] = 2,
        [')'] = 3,
        [']'] = 4,
        ['}'] = 5,
    };
    
    int automaton[N][6] = 
    {
        {          4,           2,           1, ERROR_STATE, ERROR_STATE, ERROR_STATE},
        {          5,           3, ERROR_STATE, ERROR_STATE, ERROR_STATE,           0},
        {          6, ERROR_STATE,           3, ERROR_STATE,           0, ERROR_STATE},
        {          7, ERROR_STATE, ERROR_STATE, ERROR_STATE,           1,           2},
        {ERROR_STATE,           6,           5,           0, ERROR_STATE, ERROR_STATE},
        {ERROR_STATE,           7, ERROR_STATE,           1, ERROR_STATE,           4},
        {ERROR_STATE, ERROR_STATE,           7,           2,           4, ERROR_STATE},
        {ERROR_STATE, ERROR_STATE, ERROR_STATE,           3,           5,           6},
        {ERROR_STATE, ERROR_STATE, ERROR_STATE, ERROR_STATE, ERROR_STATE, ERROR_STATE},
    };

    char input[BUFFER_SIZE];
    scanf("%s", input);

    int cur_state = 0;
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        int symbol = c2n[input[i]];
        if (symbol == ILLEGAL_CHAR)
        {
            cur_state = ERROR_STATE;
        }
        else
        {
            cur_state = automaton[cur_state][symbol];
        }
    }

    if (cur_state == 0)
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }
    
    return 0;
}