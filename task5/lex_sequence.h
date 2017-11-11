.rule = (lex_rule_t[])
{
    {
        .abbrev = "TOK",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'c',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'a',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'k',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'u',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 't',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 0,
            },
        },
        .size = 13,
    },
    {
        .abbrev = "RR",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'c',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'b',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = '0',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '1',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '2',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '3',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '4',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '5',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '6',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '7',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '8',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '9',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 1,
            },
        },
        .size = 29,
    },
},
.count = 2,
