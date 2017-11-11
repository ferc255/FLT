.rule = (lex_rule_t[])
{
    {
        .abbrev = "calpha",
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
        .size = 5,
    },
    {
        .abbrev = "dalpha",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'd',
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
        .size = 5,
    },
},
.count = 2,
