.size = 3,
.final = (char*[])
{
    [0 ... 2] = "",
    [1] = "calpha",
    [2] = "dalpha",
},
.table = (int*[])
{
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
        ['c'] = 1,
        ['d'] = 2,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
    },
    (int[])
    {
        [0 ... (1 << CHAR_BIT) - 1] = ERROR_STATE,
    },
},
