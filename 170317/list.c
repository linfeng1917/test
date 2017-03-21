/*
 *practice linked list
 *
 */
#include<stdio.h>
#include<malloc.h>

int n = 0;
typedef int data_t;
typedef struct code
{
	data_t data;
	struct code *next;
}List;

List *Createlink()
{
	List *head;
	List *p1;
	List *p2;

	head = NULL;
	p1 = (List*)malloc(sizeof(List));
	p2 = (List*)malloc(sizeof(List));

	printf("please input the data you want:(end is 0)\n");
	scanf("%d", &p1->data);

	while(p1->data != 0)
	{
		n++;
		if(n == 1)
			head = p1;
		else
			p2->next = p1;

		p2 = p1;
		p1 = (List*)malloc(sizeof(List));
		scanf("%d", &p1->data);
		printf("\n%d\n", p1->data);
	}
	free(p1);
	p2->next = NULL;
	return(head);
}

void Print(List *head)
{
	List *p;
	p = head;
	if(head != NULL)
	{
		do
		{
			printf("%d->",p->data);
			p = p->next;
		}while(p != NULL);
		printf("\nover\n");
	}
}

int main(int argc, const char *argv[])
{
	List *head;
	head = Createlink();
	Print(head);
	return 0;
}
