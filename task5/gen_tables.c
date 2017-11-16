#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "values.h"

int all_size = 0;

int used[NM];
graph_t graph;
first_t first;
pair_t all_tokens[NM];
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


void calc_first(pair_t* pair, grammar_t* grammar)
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
			calc_first(&grammar->prod[i].list[1], grammar);
			int neigh = get_token_id(&grammar->prod[i].list[1]);
			merge_sets (&first.set[idx], &first.set[neigh]);
		}
	}
	
	if (!found)
	{
	    first.set[idx].list[first.set[idx].size++] = idx;
	}

	used[idx] = 2;
}


int comparator(const void* f, const void* s)
{
	item_t* a = ((item_t*) f);
	item_t* b = ((item_t*) s);
	if (a->num != b->num)
	{
	    return a->num - b->num;
	}
	if (a->pos != b->pos)
	{
	    return a->pos - b->pos;
	}
	return a->end - b->end;
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
			pair_t token;
			strcpy(token.type, grammar->prod[item.num].list[item.pos].type);
			strcpy(token.data, grammar->prod[item.num].list[item.pos].data);
			int cur = get_token_id(&token);

			int j;
			for (j = 0; j < grammar->size; j++)
			{
			    if (strcmp(grammar->prod[j].list[0].type, token.type) == 0)
			    {
    			    if (item.pos + 1 < grammar->prod[item.num].size)
    			    {
    			        int neigh = get_token_id(&grammar->prod[item.num].list[item.pos + 1]);
    			        int k;
    			        for (k = 0; k < first.set[neigh].size; k++)
    			        {
    			            if (!added[j][neigh])
    			            {
    			                scheme[idx].list[scheme[idx].size].num = j;
    			                scheme[idx].list[scheme[idx].size].pos = 1;
    			                scheme[idx].list[scheme[idx].size].end = neigh;
    			                scheme[idx].size++;
    			                
    			                added[j][neigh] = true;
    			            }
    			        }
    			    }
    			    else
    			    {
    			        if (!added[j][item.end])
    			        {
    			            scheme[idx].list[scheme[idx].size].num = j;
			                scheme[idx].list[scheme[idx].size].pos = 1;
			                scheme[idx].list[scheme[idx].size].end = item.end;
			                scheme[idx].size++;
			                
			                added[j][item.end] = true;
    			        }
    			    }
			    }
			}
		}
	}

	qsort(scheme[idx].list, scheme[idx].size,
		  sizeof(item_t), comparator);
}


bool is_equal_states(item_list_t a, item_list_t b)
{
	if (a.size != b.size)
	{
		return false;
	}

	int i;
	for (i = 0; i < a.size; i++)
	{
		if (a.list[i].num != b.list[i].num ||
			a.list[i].pos != b.list[i].pos ||
			a.list[i].end != b.list[i].end)
		{
			return false;
		}
	}

	return true;
}


void make_transition(int idx, pair_t* edge, grammar_t* grammar)
{
    printf("%d %s %s\n", idx, edge->type, edge->data);
	bool found = false;
	scheme[graph.size].size = 0;
	int i;
	for (i = 0; i < scheme[idx].size; i++)
	{
		item_t item = scheme[idx].list[i];
		if (item.pos < grammar->prod[item.num].size &&
			strcmp(grammar->prod[item.num].list[item.pos].type, edge->type) == 0 &&
			(strcmp(grammar->prod[item.num].list[item.pos].data, edge->data) == 0 ||
			strcmp(grammar->prod[item.num].list[item.pos].data, "") == 0))
		{
			found = true;
			scheme[graph.size].list[scheme[graph.size].size].num = item.num;
			scheme[graph.size].list[scheme[graph.size].size].pos = item.pos + 1;
			scheme[graph.size].list[scheme[graph.size].size].end = item.end;
			
			printf("%d %d %d\n", scheme[graph.size].list[scheme[graph.size].size].num, scheme[graph.size].list[scheme[graph.size].size].pos, scheme[graph.size].list[scheme[graph.size].size].end);
			
			scheme[graph.size].size++;
		}
	}

    printf("-----\n");
	if (!found)
	{
		return;
	}


	add_points(graph.size, grammar);
	
	found = false;
	for (i = 0; i < graph.size; i++)
	{
		if (is_equal_states(scheme[i], scheme[graph.size]))
		{
			found = true;
			graph.matrix[idx][get_token_id(edge)] = i;
			break;
		}
	}

	if (!found)
	{
		graph.matrix[idx][get_token_id(edge)] = graph.size;
		graph.size++;
	}
}


void build_scheme(grammar_t* grammar)
{
	graph.size = 1;
	scheme[0].list[0].num = 0,
	scheme[0].list[0].pos = 1;
	scheme[0].list[0].end = 0;
	scheme[0].size = 1;

	add_points(0, grammar);
	
	
	int i;
	for (i = 0; i < graph.size; i++) 
	{
		int j;
		for (j = 0; j < all_size; j++)
		{
	  		make_transition(i, &all_tokens[j], grammar);
		}
	}
	
	//make_transition(0, &all_tokens[3], grammar);
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
    
    
    strcpy(all_tokens[all_size].type, "$");
    strcpy(all_tokens[all_size].data, "");
    all_size++;
    
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
    
    
    for (i = 0; i < all_size; i++)
    {
        calc_first(&all_tokens[i], &grammar);
        printf("%s %s\n", all_tokens[i].type, all_tokens[i].data);//first.list[i]);
        int j;
        for (j = 0; j < first.set[i].size; j++)
        {
            printf("%d ", first.set[i].list[j]);
        }
        printf("\n");
    }
    
    build_scheme(&grammar);
    
    
    printf("jjjjjjjjjj\n");
    for (i = 0; i < graph.size; i++)
    {
        int j;
        for (j = 0; j < scheme[i].size; j++)
        {
            printf("%d %d %d\n", scheme[i].list[j].num, scheme[i].list[j].pos, scheme[i].list[j].end);
        }
        printf("---------------------\n");
    }
    
    return 0;
}