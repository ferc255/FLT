.grammar_size = (int[])
{
    1, 3, 1, 2, 1, 1, 2, 
},
.grammar_left = (int[])
{
    1, 2, 2, 3, 3, 5, 5, 
},
.token_list = 
{
    .size = 9,
    .list = (token_t[])
    {
        {
            .type = "$",
            .data = "",
        },
        {
            .type = "^",
            .data = "",
        },
        {
            .type = "S",
            .data = "",
        },
        {
            .type = "L",
            .data = "",
        },
        {
            .type = "EQ",
            .data = "",
        },
        {
            .type = "R",
            .data = "",
        },
        {
            .type = "MUL",
            .data = "",
        },
        {
            .type = "DIG",
            .data = "",
        },
        {
            .type = "DIG",
            .data = "12",
        },
    },
},
.trans = (table_cell_t*[])
{
    (table_cell_t[])
    {
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_SHIFT, 1},
        {AC_SHIFT, 2},
        {AC_ERROR, 0},
        {AC_SHIFT, 3},
        {AC_SHIFT, 4},
        {AC_SHIFT, 5},
        {AC_SHIFT, 6},
    },
    (table_cell_t[])
    {
        {AC_ACCEPT, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 5},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_SHIFT, 7},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 2},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
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
        {AC_SHIFT, 8},
        {AC_ERROR, 0},
        {AC_SHIFT, 9},
        {AC_SHIFT, 4},
        {AC_SHIFT, 5},
        {AC_SHIFT, 10},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 4},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_REDUCE, 4},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 4},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_SHIFT, 11},
        {AC_REDUCE, 4},
        {AC_SHIFT, 12},
        {AC_SHIFT, 13},
        {AC_SHIFT, 14},
        {AC_SHIFT, 15},
    },
    (table_cell_t[])
    {
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_SHIFT, 11},
        {AC_ERROR, 0},
        {AC_SHIFT, 16},
        {AC_SHIFT, 13},
        {AC_SHIFT, 14},
        {AC_SHIFT, 15},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 5},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_REDUCE, 5},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 3},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_REDUCE, 3},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 4},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_SHIFT, 8},
        {AC_REDUCE, 4},
        {AC_SHIFT, 17},
        {AC_SHIFT, 4},
        {AC_SHIFT, 5},
        {AC_SHIFT, 10},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 5},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 6},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
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
        {AC_SHIFT, 11},
        {AC_ERROR, 0},
        {AC_SHIFT, 18},
        {AC_SHIFT, 13},
        {AC_SHIFT, 14},
        {AC_SHIFT, 15},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 4},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 4},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_SHIFT, 11},
        {AC_ERROR, 0},
        {AC_SHIFT, 12},
        {AC_SHIFT, 13},
        {AC_SHIFT, 14},
        {AC_SHIFT, 15},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 1},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 6},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_REDUCE, 6},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
    (table_cell_t[])
    {
        {AC_REDUCE, 3},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
        {AC_ERROR, 0},
    },
},
