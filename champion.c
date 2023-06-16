#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"champion.h"

/*
	Function: createChampion
	------------------------
	This function creates a new linked list node
	
	Returns: a new linked list node
*/

Champion* createChampion()
{
	Champion* n = (Champion*)malloc(sizeof(Champion));
	int randNum = 0; // random number to define the champion role
	int randLev = 0; // random number to define the level of the champion
	randNum = (rand() % 100); //random number from 0 to 99 inclusive
	
	//25% prob. MAGE, 25% prob. FIGHTER, 25% prob. SUPPORT, 25% prob. TANK
	if((randNum >= 0) && (randNum <= 24))
		n->role = 0;
        else if((randNum > 24) && (randNum <= 49))
                n->role = 1;
        else if((randNum > 49) && (randNum <= 74))
                n->role = 2;
        else if((randNum > 74) && (randNum <= 99))
                n->role = 3;

	//if statements to generate a random number for level of champion
	if(n->role == 0)
	{
		randLev = (rand() % 4) + 5;
		n->level = randLev;
	}
        else if(n->role == 1)
        {
                randLev = (rand() % 4) + 1;
                n->level = randLev;
        }
        else if(n->role == 2)
        {
                randLev = (rand() % 4) + 3;
                n->level = randLev;
        }
        else if(n->role == 3)
        {
                randLev = (rand() % 8) + 1;
                n->level = randLev;
        }
	n->next = NULL;
	return n;
	
}
/*
	Function: addChampion
	----------------------
	This function adds nodes to the linked list in descending order

	head: pointer to the head of the linked list
	c: pointer to the new node to insert
	Returns: the pointer to the head
*/
Champion* addChampion(Champion* head, Champion* c)
{
	//same code as in the notes, just the while loop statement has changed
	Champion* cur = head;
	Champion* prev = NULL;
	while(cur != NULL && cur->level >= c->level)
	{
		prev = cur;
		cur = cur->next;
	}	
	if(prev == NULL)
	{
		c->next = cur;
		return c;
	}
	else
	{
		prev->next = c;
		c->next = cur;
	}
	return head;
}
/*
	Function: buildChampionList()
	-----------------------------
	This function builds the linked list
	calling the create node function and the add node function
	
	n: the number of champions that will be created
	Returns: a pointer to the head of the built linked list
*/
Champion* buildChampionList(int n)
{
	Champion* head = NULL;
	Champion* newChamp;
	int counter = 0;
	while(counter < n)
        {
                //call createChampion()
                newChamp = createChampion();
		// call addChampion()
                head = addChampion(head, newChamp);
                counter++;
        }
	return head;
}
/*
	Function: printChampionList()
	-----------------------------
	This function prints out the linked list
	
	head: pointer to the head of the linked list
	Returns: void
*/
void printChampionList(Champion* head)
{
	Champion* t = head;
	while(t != NULL)
	{
		if(t->role == 0)
			printf("M%d ", t->level);
		else if (t->role == 1)
			printf("F%d ", t->level);
		else if(t->role == 2)
			printf("S%d ", t->level);
		else if (t->role == 3)
			printf("T%d ", t->level);
		t = t->next;
	}
	printf("\n");
}
/*
	Function: removeChampion()
	--------------------------
	This removes and deallocates the first node in the linked list
	that the head is pointing at

	head: pointer to the first node in a linked list
	Returns: a pointer to the new head of the linked list	
*/
Champion* removeChampion(Champion* head)
{
	Champion* cur = head;
	int counter = 0;
	while(cur != NULL && counter == 0)
	{
		head = head->next;
		free(cur);
		cur = head;
		counter++;
	}
	return head;
}
/*
	Function: destroyChamptionList()
	--------------------------------
	This function destroys the Champion linked list
	
	head: a pointer to the first node in the linked list
	Returns: a pointer to the new head which will be NULL at the end
*/
Champion* destroyChampionList(Champion* head)
{
	while(head != NULL)
	{
		Champion* t = head;
		head = head->next;
		free(t);
	}
}







