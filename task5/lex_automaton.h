.size = 7,
.final = (char*[])
{
    [0 ... 6] = "",
    [3] = "TOK",
    [6] = "RR",
},
.table = (int*[])
{
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
        ['c'] = 1,
        ['k'] = 2,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
        ['a'] = 3,
        ['b'] = 4,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
        ['u'] = 5,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
        ['0'] = 6,
        ['1'] = 6,
        ['2'] = 6,
        ['3'] = 6,
        ['4'] = 6,
        ['5'] = 6,
        ['6'] = 6,
        ['7'] = 6,
        ['8'] = 6,
        ['9'] = 6,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
        ['t'] = 3,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
    },
},
