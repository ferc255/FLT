#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "values.h"

int all_size = 0;
pair_t all_tokens[NM];
int used[NM];
item_list_t scheme[NM];

int get_token_id(pair_t* token)
{
    int result = NOT_FOUND;
    int i;
    for (i = 0; i < all_size; i++)
    {
        if (strcmp(all_tokens[i].type, token->type) == 0)
        {
            if (strcmp(all_tokens[i].data, token->data) == 0)
            {
                return i;
            }
            if (strcmp(all_tokens[i].data, "") == 0)
            {
                result = i;
            }
        }
    }
    
    return result;
}

bool contains(set_t* set, int item)
{
    int i;
    for (i = 0; i < set->size; i++)
    {
        if (set->list[i] == item)
        {
            return true;
        }
    }
    return false;
}

void merge_sets(set_t* left, set_t* right)
{
	int i;
	for (i = 0; i < right->size; i++)
	{
	    if (!contains(left, right->list[i]))
		{
			left->list[left->size++] = right->list[i];
		}
	}
}


void calc_first(pair_t* pair, grammar_t* grammar, first_t* first)
{
    //printf("%s\n", pair->type);
    //exit(0);
    int idx = get_token_id(pair);
    if (used[idx] == 2)
    {
        return;
    }
    if (used[idx] == 1)
    {
        printf("Bad grammar\n");
        exit(0);
    }
    
    used[idx] = 1;
    
    bool found = false;
    int i;
	for (i = 0; i < grammar->size; i++)
	{
		if (strcmp(grammar->prod[i].list[0].type, pair->type) == 0)
		{
		    found = true;
			calc_first(&grammar->prod[i].list[1], grammar, first);
			int neigh = get_token_id(&grammar->prod[i].list[1]);
			merge_sets (&first->set[idx], &first->set[neigh]);
		}
	}
	
	if (!found)
	{
	    first->set[idx].list[first->set[idx].size++] = idx;
	}

	used[idx] = 2;
}

void add_points(int idx, grammar_t* grammar)
{
	bool added[NM][NM];
	int i;
	for (i = 0; i < NM; i++)
	{
	    int j;
	    for (j = 0; j < NM; j++)
	    {
		    added[i][j] = false;
	    }
	}

	for (i = 0; i < scheme[idx].size; i++)
	{
		item_t item = scheme[idx].list[i];
		if (item.pos < grammar->prod[item.num].size)
		{
			token_t token = grammar->prod[item.num].list[item.pos];
			int cur = get_token_id(token);
			

			int j;
			for (j = 0; j < grammar->size; j++)
			{
			    if (strcmp(grammar->prod[j][0].type, token.type))
			    {
    			    if (item.pos + 1 < grammar->prod[item.num].size)
    			    {
    			        int neigh = get_token_id(grammar->prod[item.num].list[item.pos + 1]);
    			        int k;
    			        for (k = 0; k < first.set[neigh].size; k++)
    			        {
    			            if (!added[cur][neigh])
    			            {
    			                scheme[idx].list[scheme[idx].size].num = j;
    			                scheme[idx].list[scheme[idx].size].pos = 0;
    			                scheme[idx].list[scheme[idx].size].end = neigh;
    			                
    			                scheme[idx].size++;
    			            }
    			        }
    			    }
    			    else
    			    {
    			        if (!added[cur][item.end])
    			    }
			    }
			    
				if (strcmp(grammar->prod[j][0].type, token.type))
				{
					scheme->scheme[idx].list[scheme->scheme[idx].size]
						.grammar_num = j;
					scheme->scheme[idx].list[scheme->scheme[idx].size]
						.position = 0;
				
					scheme->scheme[idx].size++;
				}
			}
		}
	}

	qsort(scheme->scheme[idx].list, scheme->scheme[idx].size,
		  sizeof(point_t), comparator);
}


void build_scheme(grammar_t* grammar, graph_t* graph)
{
	graph->size = 1;
	scheme->scheme[0].list[0].grammar_num = 0,
	scheme->scheme[0].list[0].position = 0;
	scheme->scheme[0].size = 1;
	add_points(0, grammar);
	int i;
	for (i = 0; i < graph->size; i++) 
	{
		int j;
		for (j = 0; j < TOKENS; j++)
		{
	  		make_transition(i, j, grammar, graph, scheme, term_non_term);
		}
	}	
}


int main()
{
    grammar_t grammar = 
    {
        .size = 4,
        .prod = (prod_t[])
        {
            {
                .size = 2,
                .list = (pair_t[])
                {
                    {
                        .type = "sen1",
                        .data = "",
                    },
                    {
                        .type = "sen",
                        .data = "",
                    },
                },
            },
            {
                .size = 5,
                .list = (pair_t[])
                {
                    {
                        .type = "sen",
                        .data = "",
                    },
                    {
                        .type = "RR",
                        .data = "",
                    },
                    {
                        .type = "TOK",
                        .data = "ca",
                    },
                    {
                        .type = "RR",
                        .data = "",
                    },
                    {
                        .type = "C",
                        .data = "",
                    },
                },
            },
            {
                .size = 3,
                .list = (pair_t[])
                {
                    {
                        .type = "C",
                        .data = "",
                    },
                    {
                        .type = "TOK",
                        .data = "",
                    },
                    {
                        .type = "C",
                        .data = "",
                    },
                },
            },
            {
                .size = 3,
                .list = (pair_t[])
                {
                    {
                        .type = "C",
                        .data = "",
                    },
                    {
                        .type = "RR",
                        .data = "",
                    },
                    {
                        .type = "TOK",
                        .data = "kut",
                    },
                },
            },
        },
    };
    
    int i;
    for (i = 0; i < grammar.size; i++)
    {
        int j;
        for (j = 0; j < grammar.prod[i].size; j++)
        {
            
            bool found = false;
            int z;
            for (z = 0; z < all_size; z++)
            {
                if (strcmp(grammar.prod[i].list[j].type, all_tokens[z].type) == 0 &&
                    strcmp(grammar.prod[i].list[j].data, all_tokens[z].data) == 0)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                strcpy(all_tokens[all_size].type, grammar.prod[i].list[j].type);
                strcpy(all_tokens[all_size].data, grammar.prod[i].list[j].data);
                all_size++;
            }
        }
    }
    
    first_t first;
    for (i = 0; i < all_size; i++)
    {
        calc_first(&all_tokens[i], &grammar, &first);
        printf("%s %s\n", all_tokens[i].type, all_tokens[i].data);//first.list[i]);
        int j;
        for (j = 0; j < first.set[i].size; j++)
        {
            printf("%d ", first.set[i].list[j]);
        }
        printf("\n");
    }
    
    //graph_t graph;
    //build_scheme(&grammar, &graph);
    
    
    
    
    return 0;
}