#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head) {
	int Leng = 0;
	while (head) {
		Leng++;
		head = head->next;
	}
	return Leng;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node *head) {
	int fifty = length (head) + 1;
	int fast = 0;
	char *finished = malloc(fifty, sizeof(char));
	while (head) {
		finished [fast++] = head->letter;
		head = head->next;
	}
	finished [fast] = '\0';
	return finished;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c)
{
	node *thirdnode = calloc(1, sizeof(node));
	
	thirdnode->next = NULL;
	if (*pHead == NULL)
	*pHead = thirdnode;
	else {
		node *sptr = pHead;
		while (sptr->next) sptr = sptr->next;
		sptr->next = thirdnode;
	}

// deletes all nodes in the linkedList.
void deleteList(node **pHead) {
	

	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}