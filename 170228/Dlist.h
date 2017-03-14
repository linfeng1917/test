#ifndef _DLIST_H_
#define _DLIST_H_

typedef int Item;
typedef struct Node * PNode;
typedef PNode Position;

typedef struct Node
{
	Item data;
	PNode previous;
	PNode next;
}Node;

typedef struct
{
	PNode head;
	PNode tail;
	int size;
}DList;

Position MakeNode(Item i);

void FreeNode(PNode p);

DList *InitList();

void DestroyList(DList *plist);

void ClearList(DList *plist);

Position GetHead(DList *plist);

Position GetTail(DList *plist);

int GetSize(DList *plist);

Position GetNext(Position p);

Position GetPrevious(Position p);

PNode InsFirst(DList *plist, PNode pnode);

PNode DelFirst(DList *plist);

Item GetItem(Position p);

void SetItem(Position p,Item i);

PNode Remove(DList *plist);

PNode InsBefore(DList *plist, Position p, PNode s);

PNode LocatePos(DList *plist, int i);

void ListTraverse(DList *plist, void (*visit)());
