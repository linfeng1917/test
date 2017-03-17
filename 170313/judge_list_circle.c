#include<stdio.h>

typedef int data_t;
typedef struct code{
	data_t data;
	struct code *next;
}List;
int judge_list_circle(List *head)
{
	List *first = head;
	List *back = head;
	while((first->next!=NULL)&&(back->next!=NULL))
	{
		first = first->next;
		back = back->next->next;
		if(first == back)
			return true;
	}
	return false;
}
