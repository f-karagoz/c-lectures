#define _CRT_SECURE_NO_WARNINGS		// to disable warnings for strcpy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define APP_3

#ifdef APP_1

struct Date
{
	int day, month, year;
};

struct Person
{
	char name[32];
	int no;
	struct Date bDate;
}per1, per2, per3;

void disp(struct Person* pper)
{
	printf("Person: %s, %d, %d/%d/%d\n", pper->name, pper->no, pper->bDate.day, pper->bDate.month, pper->bDate.year);
}

int main(void)
{
	strcpy(per1.name, "Furkan Karagoz");
	per1.no = 55;
	per1.bDate.day = 20;
	per1.bDate.month = 12;
	per1.bDate.year = 2022;

	printf("Person1: %s, %d, %d/%d/%d\n", per1.name, per1.no, per1.bDate.day, per1.bDate.month, per1.bDate.year);

	struct Person per4 = { "Lorem Ipsum", 10, {1,1,1970} };
	struct Person per5 = { "xxx zzz", 99, 31,12,2000 };
	struct Person per6 = { "Sacit Mutlu", .bDate.day = 12, .bDate.month = 7, .bDate.year = 1978, .no = 123 };

	disp(&per4);
	disp(&per5);
	disp(&per6);
	
	return 0;
}

#elif defined APP_2

// here both Person and Date stucture declared
struct Person
{
	char name[32];
	int no;
	struct Date
	{
		int day, month, year;
	}bDate;
};

struct Sample
{
	int a;
	int b;
	//struct Sample s;		// invalid
	struct Sample* ps;		// valid
};

// no matter what the type of pointer the size is known
// in 32-bit systems pointers are 4 bytes; in 64-bit systems 8 bytes

int main(void)
{

	struct Person per;		// valid
	struct Date date;		// valid

	return 0;
}

#elif defined APP_3

// singly linked list
struct Node
{
	int val;
	struct Node* next;
};

/*
// doubly linked list
struct Node
{
	int val;
	struct Node* next;
	struct Node* prev;
};
*/
struct LList
{
	struct Node* head;
	struct Node* tail;
	size_t count;
};

struct LList* create_llist(void);
struct LList* add_item_tail(struct LList* llist, int val);
struct LList* add_item_head(struct LList* llist, int val);
void walk_llist(struct LList* llist);
void clear_llist(struct LList* llist);
void destroy_list(struct LList* llist);
size_t count_list(struct LList* llist);

int main(void)
{
	struct LList* llist;

	if ((llist = create_llist()) == NULL)
	{
		fprintf(stderr, "Cannot create linked list!...\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 100; ++i)
		if (add_item_tail(llist, i) == NULL)
		{
			fprintf(stderr, "Cannot create node!...\n");
			exit(EXIT_FAILURE);
		}

	for (int i = 0; i < 100; ++i)
		if (add_item_head(llist, i) == NULL)
		{
			fprintf(stderr, "Cannot create node!...\n");
			exit(EXIT_FAILURE);
		}

	walk_llist(llist);

	destroy_list(llist);

	return 0;
}

struct LList* create_llist(void)
{
	struct LList* llist;

	if ((llist = (struct LList*)malloc(sizeof(struct LList))) == NULL)
		return 0;

	llist->head = NULL;
	llist->tail = NULL;
	llist->count = 0;
}

struct LList* add_item_tail(struct LList* llist, int val)
{
	struct Node* newNode;

	if ((newNode = (struct Node*)malloc(sizeof(struct Node))) == NULL)
		return NULL;
	newNode->val = val;
	newNode->next = NULL;

	// if llist empty, first item in the list
	if (llist->head == NULL)
		llist->head = newNode;
	else
		llist->tail->next = newNode;		// add the node at the end of ll
	llist->tail = newNode;					// redefine the end of ll

	++llist->count;

	return newNode;
}

struct LList* add_item_head(struct LList* llist, int val)
{
	struct Node* newNode;

	if ((newNode = (struct Node*)malloc(sizeof(struct Node))) == NULL)
		return NULL;
	newNode->val = val;

	// add the node
	if (llist->head == NULL)
	{
		llist->head = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = llist->head;
		llist->head = newNode;
	}

	++llist->count;

	return newNode;
}

void walk_llist(struct LList* llist)
{
	struct Node* node;

	node = llist->head;

	while (node != NULL)
	{
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}

void clear_llist(struct LList* llist)
{
	struct Node* node, * temp;

	node = llist->head;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}

	llist->head = NULL;
	llist->tail = NULL;
	llist->count = 0;
}

void destroy_list(struct LList* llist)
{
	clear_llist(llist);
	free(llist);
}

size_t count_list(struct LList* llist)
{
	return llist->count;
}

#endif