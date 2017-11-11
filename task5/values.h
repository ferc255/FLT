#ifndef _VALUES_H_
#define _VALUES_H_



#define NOT_FOUND -1

typedef enum
{
	AC_SHIFT,
	AC_REDUCE,
	AC_ACCEPT,
	AC_ERROR,
} action_t;


typedef struct token_t
{
    char* type;
    char* data;
} token_t;

typedef struct table_cell_t
{
  action_t action;
  int num;
} table_cell_t;

typedef struct column_t
{
    char* type;
    char* data;
    bool is_terminal;
} column_t;

typedef struct token_list_t
{
    int size;
    token_t* list; // Then char*
} token_list_t;

typedef struct tables_t
{
	int* grammar_size;
	int* grammar_left;
	token_list_t token_list;
	table_cell_t** trans;
} tables_t;


#endif /* _VALUES_H_ */
