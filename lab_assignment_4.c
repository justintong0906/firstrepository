#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int num=0;

    if(head==NULL)
        return 0;

    node *temp = head;
    while(temp != NULL){
        num++;
        temp=temp->next;
    }
    return num;

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int i, h=length(head);

    node *temp=head;


    if(h==0){
        printf("list empty1");
        return NULL;
    }


    char *stringy = (char*)malloc(sizeof(char)*(h+1));

    for(i=0;i<h;i++){
        stringy[i]=temp->letter;
        temp=temp->next;
    }
    stringy[h]='\0';
    return(stringy);

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{

    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("malloc failed");
        return;
    }
    newnode->letter=c;
    newnode->next=NULL;




    if(*pHead==NULL)
        *pHead=newnode;
    else{
        node *temp = *pHead;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next=newnode;
    }

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node *front = *pHead;

    while(front != NULL){
        front=front->next;
        free(*pHead);
        *pHead=front;
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
