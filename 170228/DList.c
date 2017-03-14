#include"DList.h"
#include<malloc.h>
#include<stdlib.h>

Position MakeNode(Item i)
{
	PNode p =NULL;
	p = (PNode)malloc(sizeof(Node));
	if(p!=NULL)
	{
		p->data = i;
		p->previous = NULL;
		p->next = NULL;
	}
	return p;
}

void FreeNode(PNode p)
{
	free(p);
}

DList *InitList()
{
	DList *plist = (DList*)malloc(sizeof(DList));
	PNode head = MakeNode(0);
	if(plist != NULL)
	{
		if(head != NULL)
		{
			plist->head = head;
			plist->tail = head;
			plist->size = 0;
		}
		else
			return NULL;
	}
	return plist;
}

void DestoryList(DList *plist)
{
	ClearList(plist);
	free(GetHead(plist);
	free(plist);
}

int IsEmpty(DList *plist)
{
	if(GetSize(plist) == 0 && GetTail(plist) == GetHead(plist))
		return 1;
	else
		return 0;
}

void ClearList(DList *plist)
{
	PNode temp,p;
	p = GetTail(plist);
	while(!IsEmpty(plist))
	{
		temp = GetPrevious(p);
		FreeNode(p);
		p = temp;
		plist->tail = temp;
		plist->size--;
	}
}

Position GetHead(DList *plist)
{
	return plist->head;
}

Position GetTail(DList *plist)
{
	return plist->tail;
}

int GetSize(DList *plist)
{
	return plist->size;
}

Position GetNext(Position p)
{
	return p->next;
}

Position GetPrevious(Position p)
{
	return p->previous;
}

PNode InsFirst(DList *plist, PNode pnode)
{
	Position head = GetHead(plist);
	if(IsEmpty(plist))
		plist->tail = pnode;
	plist->size++;

	pnode->next = head->next;
	pnode->previous = head;

	if(head->next!=NULL)
		head->next->previous = pnode;
	head-next = pnode;

	return pnode;
}

PNode DelFirst(DList *plist)
{
	Position head = GetHead(plist);
	Position p = head->next;
	if(p!=NULL)
	{
		if(p==GetTail(plist))
			plist->tail = p->previous;
		head->next = p->next;
		head->next->previous = head;
		plist->size--;
	}
	return p;
}

Item GetItem(Position p)
{
	return p->data;
}

void SetItem(Position p, Item i)
{
	p->data = i;
}

PNode Remove(Dlist *plist)
{
	Position p = NULL;
	if(IsEmpty(plist))
		return NULL;
	else
	{
		p = GetTail(plist);
		p->previous->next = p->next;
		plist->tail = p->previous;
		plist->size--;
		return p;
	}
}

PNode InsBefore(DList *plist, Position p, PNode s)
{
	s->previous = p->previous;
	s->next = p;
	p->previous->next = s;
	p->previous = s;
	plist->size++;
	return s;
}

PNode InsAfter(DList *plist, Position p, PNode s)
{
	s->next = p->next;
	s->previous = p;
	if(p->next != NULL)
		p->next-previous = s;
	p-next = s;

	if(p = GetTail(plist))
		plist->tail = s;
	plist->size++;
	return s;
}

PNode LocatePos(Dlist *plist, int i)
{
	int cnt = 0;
	Position p = GetHead(plist);
	if(i>GetSize(plist) || i<1)
		return NULL;
	while(++cnt<=i)
		p = p->next;
	return p;
}

void ListTraverse(DList *plist, void(*visit)())
{
	Position p = GetHead(plist);
	if(IsEmpty(plist))
		exit(0);
	else
	{
		while(p->next != NULL)
		{
			p = p->next;
			visit(p->data);
		}
	}
} 
