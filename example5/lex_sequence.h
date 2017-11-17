.rule = (lex_rule_t[])
{
    {
        .abbrev = "b",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'b',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'g',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'i',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'n',
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
        .abbrev = "e",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'n',
            },
            {
                .type = NT_CAT,
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
        .size = 9,
    },
    {
        .abbrev = "V",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'v',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'a',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'l',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 2,
            },
        },
        .size = 9,
    },
    {
        .abbrev = "I",
        .prior = 0,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_LPAREN,
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
                .symbol = 'b',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'c',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'd',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'f',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'g',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'h',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'i',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'j',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'k',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'l',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'm',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'n',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'o',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'p',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'q',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'r',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 's',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 't',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'u',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'v',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'w',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'x',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'y',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'z',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'A',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'B',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'C',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'D',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'E',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'F',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'G',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'H',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'I',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'J',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'K',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'L',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'M',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'N',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'O',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'P',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'Q',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'R',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'S',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'T',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'U',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'V',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'W',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'X',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'Y',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'Z',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_LPAREN,
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
                .symbol = 'b',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'c',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'd',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'f',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'g',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'h',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'i',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'j',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'k',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'l',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'm',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'n',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'o',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'p',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'q',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'r',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 's',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 't',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'u',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'v',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'w',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'x',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'y',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'z',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'A',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'B',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'C',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'D',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'E',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'F',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'G',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'H',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'I',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'J',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'K',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'L',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'M',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'N',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'O',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'P',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'Q',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'R',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'S',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'T',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'U',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'V',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'W',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'X',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'Y',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = 'Z',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_STAR,
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 3,
            },
        },
        .size = 216,
    },
    {
        .abbrev = "=",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = '=',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 4,
            },
        },
        .size = 5,
    },
    {
        .abbrev = "W",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'w',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'h',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'i',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'l',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 5,
            },
        },
        .size = 13,
    },
    {
        .abbrev = "L",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'l',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
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
                .symbol = 6,
            },
        },
        .size = 9,
    },
    {
        .abbrev = "i",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'i',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'n',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 7,
            },
        },
        .size = 7,
    },
    {
        .abbrev = "f",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'i',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'f',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 8,
            },
        },
        .size = 7,
    },
    {
        .abbrev = "T",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 't',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'h',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'n',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 9,
            },
        },
        .size = 11,
    },
    {
        .abbrev = "s",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'l',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 's',
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_CHAR,
                .symbol = 'e',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 10,
            },
        },
        .size = 11,
    },
    {
        .abbrev = "X",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
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
                .type = NT_STAR,
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 11,
            },
        },
        .size = 48,
    },
    {
        .abbrev = "+",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = '+',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '-',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 12,
            },
        },
        .size = 7,
    },
    {
        .abbrev = "LP",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = '(',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 13,
            },
        },
        .size = 5,
    },
    {
        .abbrev = "RP",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = ')',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 14,
            },
        },
        .size = 5,
    },
    {
        .abbrev = "WS",
        .prior = 1,
        .list = (rule_token_t[])
        {
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = ' ',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '\n',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '\t',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '\r',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_LPAREN,
            },
            {
                .type = NT_CHAR,
                .symbol = ' ',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '\n',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '\t',
            },
            {
                .type = NT_OR,
            },
            {
                .type = NT_CHAR,
                .symbol = '\r',
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_STAR,
            },
            {
                .type = NT_RPAREN,
            },
            {
                .type = NT_CAT,
            },
            {
                .type = NT_END,
                .symbol = 15,
            },
        },
        .size = 24,
    },
},
.count = 16,
