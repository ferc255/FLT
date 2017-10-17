#include <stdio.h>
#include <string.h>

const int BUFFER_SIZE = 300;

void print_token(char* type, char symbol)
{
    printf("            {\n                .type = %s,\n", type);
    
    if (symbol)
    {
        printf("                .symbol = \'");
        if (symbol == '\n')
        {
            printf("\\n");
        }
        else if (symbol == '\t')
        {
            printf("\\t");
        }
        else if (symbol == '\r')
        {
            printf("\\r");
        }
        else
        {
            printf("%c", symbol);
        }
        printf("\',\n");
    }
    
    printf("            },\n");
}

void parse_rule(char input[BUFFER_SIZE])
{
    int first_semic = 0;
    int second_semic = 0;
    int i;
    for (i = 0; second_semic == 0; i++)
    {
        if (input[i] == ':')
        {
            if (first_semic == 0)
            {
                first_semic = i;
            }
            else
            {
                second_semic = i;
            }
        }
    }
    
    char s[BUFFER_SIZE];
    int s_ptr = 0;
    for (i = second_semic + 1; i < strlen(input); )
    {
        if (input[i] == '\\')
        {
            if (input[i + 1] == 'd')
            {
                s[s_ptr++] = '(';
                char j;
                for (j = '0'; j < '9'; j++)
                {
                    s[s_ptr++] = j;
                    s[s_ptr++] = '|';
                }
                s[s_ptr++] = '9';
                s[s_ptr++] = ')';
                
                i += 2;
            }
            else if (input[i + 1] == 'w')
            {
                s[s_ptr++] = '(';
                char j;
                for (j = 'a'; j <= 'z'; j++)
                {
                    s[s_ptr++] = j;
                    s[s_ptr++] = '|';
                }
                for (j = 'A'; j < 'Z'; j++)
                {
                    s[s_ptr++] = j;
                    s[s_ptr++] = '|';
                }
                s[s_ptr++] = 'Z';
                s[s_ptr++] = ')';
                
                i += 2;
            }
            else if (input[i + 1] == 's')
            {
                s[s_ptr++] = '(';
                s[s_ptr++] = ' ';
                s[s_ptr++] = '|';
                s[s_ptr++] = '\\';
                s[s_ptr++] = 'n';
                s[s_ptr++] = '|';
                s[s_ptr++] = '\\';
                s[s_ptr++] = 't';
                s[s_ptr++] = '|';
                s[s_ptr++] = '\\';
                s[s_ptr++] = 'r';
                s[s_ptr++] = ')';
                
                i += 2;
            }
            else
            {
                s[s_ptr++] = input[i++];
            }
        }
        else
        {
            s[s_ptr++] = input[i++];
        }
    }
    s[s_ptr - 1] = '\0';
    
    char temp[BUFFER_SIZE];
    for (i = 0; i < first_semic; i++)
    {
        temp[i] = input[i];
    }
    temp[i] = '\0';

    printf("    {\n        .abbrev = \"%s\",\n", temp);
    
    for (i = first_semic + 1; i < second_semic; i++)
    {
        temp[i - first_semic - 1] = input[i];
    }
    temp[i - first_semic - 1] = '\0';
    
    printf("        .prior = %d,\n        .list = (rule_token_t[])\n        {\n", 
        atoi(temp));
    
    print_token("NT_LPAREN", 0);
    int size = 0;
    for (i = 0; i < strlen(s); )
    {
        if (s[i] == '\\')
        {
            if (s[i + 1] == 'e')
            {
                print_token("NT_EPS", 0);
            }
            else if (s[i] == 'n')
            {
                print_token("NT_CHAR", '\n');
            }
            else if (s[i] == 't')
            {
                print_token("NT_CHAR", '\t');
            }
            else if (s[i] == 'r')
            {
                print_token("NT_CHAR", '\r');
            }
            else
            {
                print_token("NT_CHAR", s[i]);
            }
            
            i += 2;
        }
        else
        {
            if (s[i] == '|')
            {
                print_token
            }
        }
    }
    
    
    
    
    printf("%s\n", s);
}

int main()
{
    char input[BUFFER_SIZE];
    char temp[BUFFER_SIZE];
    int count = 0;
    printf(".rule = (lex_rule_t[])\n{\n");
    while (fgets(temp, sizeof temp, stdin))
    {
        count++;
        strcat(input, temp);
        parse_rule(temp);
    }
    
    printf("%d\n", count); 
    
    
}