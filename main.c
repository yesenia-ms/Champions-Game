#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"champion.h"

int main(int argc, char* argv[])
{
	Champion* headP1 = NULL;
	Champion* headP2 = NULL;
	int champs = 0;
	int roundNum = 1;
	srand(time(0));
	
	//checking the number of arguments
	if(argc != 2)
	{
		printf("ERROR NO ARGS!\n");
		return 1;
	}
	// converting second argument to an integer
	champs = atoi(argv[1]);
	// checking the 2nd argument
	if(champs <= 0)
	{
		printf("ERROR: NUMBER IS NOT GREATER THAN ZERO!\n");
		return 1;
	}

	//building the Champion List
        headP1 = buildChampionList(champs);
        headP2 = buildChampionList(champs);
	Champion* tP1 = headP1;
	Champion* tP2 = headP2;

	printf("\n============ PLAYER 1 V PLAYER 2 SHOWDOWN ============\n\n");
	do
	{
		//declaring a newChamp for P1 if they win
		Champion* newChampP1;
		Champion* newChampP2;
                printf("----- ROUND %d -----\n", roundNum);
               	printf("Player 1: ");
               	printChampionList(headP1);
               	printf("Player 2: ");
               	printChampionList(headP2);
		switch(tP1->role)
		{
			case(0):
				printf("Player 1 is a MAGE and ");
				break;
			case(1):
				printf("Player 1 is a FIGHTER and ");
				break;
			case(2):
				printf("Player 1 is a SUPPORT and ");
				break;
			case(3):
				printf("Player 1 is a TANK and ");
				break;
			default:
//				printf("THIS IS PLAYER 1 ROLE: %d\n", tP1->role);
//				printf("IS THIS THE ISSUE!!!\n");
				break;
		}
		switch(tP2->role)
		{
			case(0):
		                printf("Player 2 is a MAGE\n");
                                break;
                        case(1):
                                printf("Player 2 is a FIGHTER\n");
                                break;
                        case(2):
                                printf("Player 2 is a SUPPORT\n");
                                break;
                        case(3):
                                printf("Player 2 is a TANK\n");
                                break;
                        default:
//				printf("THIS IS PLAYER 2 ROLE: %d\n", tP2->role);
//				printf("IS THIS THE ISSUE!!!\n");
                                break;
		}
		if(tP1->role == 0 && tP2->role == 0)
		{
			if(tP1->level > tP2->level)
			{
				printf("Player 1 (MAGE) wins and gains a new champion.\n");
				printf("Player 2 (MAGE) loses one champion.\n\n");
				// removing the champion that P2 lost
				headP2 = removeChampion(headP2);
				tP2 = headP2;
				// doing the default removal of champions after each round for reach case
				headP1 = removeChampion(headP1);
	                        headP2 = removeChampion(headP2);
	                        tP1 = headP1;
	                        tP2 = headP2;
				// adding a new champ to P1 (MAGE)
				newChampP1 = createChampion();
				headP1 = addChampion(headP1, newChampP1);
				tP1 = headP1;
			}
			else if(tP2->level > tP1->level)
			{
				printf("Player 1 (MAGE) loses one champion.\n");
				printf("Player 2 (MAGE) wins and gains a new champion.\n\n");
				//removing the champion that P1 lost
				headP1 = removeChampion(headP1);
				tP1 = headP1;
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
				// adding a new champ to P2 
				newChampP2 = createChampion();
				headP2 = addChampion(headP2, newChampP2);
				tP2 = headP2;
			}
                        else if (tP1->level == tP2->level)
                        {
                                printf("Nothing happens - no penalty or reward.\n\n");
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
                        }
		}
		else if((tP1->role == 0 && tP2->role == 1) || (tP1->role == 1 && tP2->role == 0))
		{
                        if((tP1->role == 0 && tP2->role == 1))
                        {
				if(tP1->level > tP2->level)
				{
                                       	printf("Player 1 (MAGE) wins and gains a new champion.\n");
					printf("Player 2 (FIGHTER) loses but with no penalty.\n\n");
        	                        // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
                	                headP2 = removeChampion(headP2);
                	                tP1 = headP1;
                	                tP2 = headP2;
					// adding a new champ to P1
					newChampP1 = createChampion();
					headP1 = addChampion(headP1, newChampP1);
					tP1 = headP1;
				}
				else if(tP2->level > tP1->level)
				{
					printf("Player 1 (MAGE) loses one champion.\n");
					printf("Player 2 (FIGHTER) wins but gains no reward.\n\n");
					// removing the champ from P1
					headP1 = removeChampion(headP1);
					tP1 = headP1;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	 	                        tP2 = headP2;

				}
                                else if (tP1->level == tP2->level)
                                {
                                        printf("Nothing happens - no penalty or reward.\n\n");
                        	        // doing the default removal of champions after each round for reach case
                        	        headP1 = removeChampion(headP1);
                        	        headP2 = removeChampion(headP2);
       			                tP1 = headP1;
	                                tP2 = headP2;

                                }

               		}
                	else if(tP1->role == 1 && tP2->role == 0)
			{
                       		if(tP1->level > tP2->level)
                       		{
                                	printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                                	printf("Player 2 (MAGE) loses one champion.\n\n");
					// removing champ from P2
					headP2 = removeChampion(headP2);
					tP2 = headP2;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;

                 	      	}
                       		else if(tP2->level > tP1->level)
                       		{
                                	printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                                	printf("Player 2 (MAGE) wins and gains a new champion.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
					// adding a new champ to P2
					newChampP2 = createChampion();
					headP2 = addChampion(headP2, newChampP2);
					tP2 = headP2;
                       		}
                       		else if (tP1->level == tP2->level)
                       		{
                                	printf("Nothing happens - no penalty or reward.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
                       		}	
			}
		}
		else if((tP1->role == 0 && tP2->role == 2) || (tP1->role == 2 && tP2->role == 0))
		{
                        if((tP1->role == 0 && tP2->role == 2))
                        {
                                if(tP1->level > tP2->level)
                                {	
                                        printf("Player 1 (MAGE) wins and gains a new champion.\n");
                                        printf("Player 2 (SUPPORT) loses two champions.\n\n");
					// removing 2 champs from P2
					headP2 = removeChampion(headP2);
					headP2 = removeChampion(headP2);
					tP2 = headP2;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
					// adding a champion to P1
					newChampP1 = createChampion();
					headP1 = addChampion(headP1, newChampP1);
					tP1 = headP1;
                                }
                                else if(tP2->level > tP1->level)
                                {
                                        printf("Player 1 (MAGE) loses one champion.\n");
                                        printf("Player 2 (SUPPORT) wins two new champions.\n\n");
					//removing champ from P1
					headP1 = removeChampion(headP1);
					tP1 = headP1;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
					// adding two champions to P2
					newChampP2 = createChampion();
					headP2 = addChampion(headP2, newChampP2);
					tP2 = headP2;
					newChampP2 = createChampion();
					headP2 = addChampion(headP2, newChampP2);
					tP2 = headP2;
                              	}
				else if (tP1->level == tP2->level)
				{
					printf("Nothing happens - no penalty or reward.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
				}
                        }
                        else if(tP1->role == 2 && tP2->role == 0)
                        {
                	        if(tP1->level > tP2->level)
				{
                                        printf("Player 1 (SUPPORT) wins two new champions.\n");
                                        printf("Player 2 (MAGE) loses one champion.\n\n");
					//removing champ from P2
					headP2 = removeChampion(headP2);
					tP2 = headP2;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
					// adding two champions to P1
                                        newChampP1 = createChampion();
                                        headP1 = addChampion(headP1, newChampP1);
					tP1 = headP1;
                                        newChampP1 = createChampion();
                                        headP1 = addChampion(headP1, newChampP1);
                                        tP1 = headP1;

                                }
                                else if(tP2->level > tP1->level)
                                {
                                        printf("Player 1 (SUPPORT) loses two champions.\n");
                                        printf("Player 2 (MAGE) wins and gains a new champion.\n\n");
					// removing the 2 champions from P1
					headP1 = removeChampion(headP1);
					headP1 = removeChampion(headP1);
					tP1 = headP1;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
					// adding a new champion to P2
					newChampP2 = createChampion();
					headP2 = addChampion(headP2, newChampP2);
					tP2 = headP2;
                                }
                                else if (tP1->level == tP2->level)
                                {
                                        printf("Nothing happens - no penalty or reward.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
        	                        tP1 = headP1;
	                                tP2 = headP2;

                                }
                        }
		}
                else if((tP1->role == 0 && tP2->role == 3) || (tP1->role == 3 && tP2->role == 0))
                {
                        if((tP1->role == 0 && tP2->role == 3))
                      	{
				printf("Player 1 (MAGE) wins and gains a new champion.\n");
				printf("Player 2 (TANK) loses one champion.\n\n");
				// removing champ from P2
				headP2 = removeChampion(headP2);
				tP2 = headP2;
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
				// adding a new champ to P1
				newChampP1 = createChampion();
				headP1 = addChampion(headP1, newChampP1);
				tP1 = headP1;
			}
                        else if(tP1->role == 3 && tP2->role == 0)
                        {
                                printf("Player 1 (TANK) loses one champion.\n");
                                printf("Player 2 (MAGE) wins and gains a new champion.\n\n");
				// removing champ from P1
				headP1 = removeChampion(headP1);
				tP1 = headP1;
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
				// adding a new champ to P2
				newChampP2 = createChampion();
				headP2 = addChampion(headP2, newChampP2);
				tP2 = headP2;
                        }
                }
                else if((tP1->role == 1 && tP2->role == 1))
		{
                        printf("Both players win a new champion.\n\n");
			// doing the default removal of champions after each round for each case
                        headP1 = removeChampion(headP1);
                        headP2 = removeChampion(headP2);
			tP1 = headP1;
			tP2 = headP2;
			// adding a champion to each player
			newChampP1 = createChampion();
			newChampP2 = createChampion();
			headP1 = addChampion(headP1, newChampP1);
			headP2 = addChampion(headP2, newChampP2);
			tP1 = headP1;
			tP2 = headP2;
		}
                else if((tP1->role == 1 && tP2->role == 2) || (tP1->role == 2 && tP2->role == 1))
                {
                        if((tP1->role == 1 && tP2->role == 2))
                        {
				if(tP1->level > tP2->level)
                                {
					printf("Player 1 (FIGHTER) wins but with no reward.\n");
                                        printf("Player 2 (SUPPORT) loses one champion.\n\n");
					// remove champ from P2
					headP2 = removeChampion(headP2);
					tP2 = headP2;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;

                                } 
                                else if(tP2->level > tP1->level)
                                {
                                        printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                                        printf("Player 2 (SUPPORT) wins one new champion.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
					// adding a champ to P2
					newChampP2 = createChampion();
					headP2 = addChampion(headP2, newChampP2);
					tP2 = headP2;
                                }
                                else if (tP1->level == tP2->level)
                                {
                                        printf("Nothing happens - no penalty or reward.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
                                }
                        }
                        else if(tP1->role == 2 && tP2->role == 1)
                        {
                                if(tP1->level > tP2->level)
				{
                                        printf("Player 1 (SUPPORT) wins one new champion.\n");
                                        printf("Player 2 (FIGHTER) loses but with no penalty.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
					// adding a new champ to P1
					newChampP1 = createChampion();
					headP1 = addChampion(headP1, newChampP1);
					tP1 = headP1;
                                }
                                else if(tP2->level > tP1->level)
                                {
                                        printf("Player 1 (SUPPORT) loses one champion.\n");
                                        printf("Player 2 (FIGHTER) wins but with no reward.\n\n");
					// remove champ from P1
					headP1 = removeChampion(headP1);
					tP1 = headP1;
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;

                                }
                                else if (tP1->level == tP2->level)
                                {
                                        printf("Nothing happens - no penalty or reward.\n\n");
	                                // doing the default removal of champions after each round for reach case
	                                headP1 = removeChampion(headP1);
	                                headP2 = removeChampion(headP2);
	                                tP1 = headP1;
	                                tP2 = headP2;
                                }
                        }
		}
                else if((tP1->role == 1 && tP2->role == 3) || (tP1->role == 3 && tP2->role == 1))
                {
                        if((tP1->role == 1 && tP2->role == 3))
                        {
                                printf("Player 1 (FIGHTER) wins and gains a new champion.\n");
                                printf("Player 2 (TANK) loses but with no penalty.\n\n");
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
				// adding a new champ to P1
				newChampP1 = createChampion();
				headP1 = addChampion(headP1, newChampP1);
				tP1 = headP1;
                        }
                        else if(tP1->role == 3 && tP2->role == 1)
                        {
                                printf("Player 1 (TANK) loses but with no penalty.\n");
                                printf("Player 2 (FIGHTER) wins and gains a new champion.\n\n");
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
				// adding a new champ to P2
				newChampP2 = createChampion();
				headP2 = addChampion(headP2, newChampP2);
				tP2 = headP2;
                        }
                }
                else if((tP1->role == 2 && tP2->role == 2))
                {
                        printf("Both players lose the next champion.\n\n"); 
			//removing one champ from P1 and P2
            		headP1 = removeChampion(headP1);
			headP2 = removeChampion(headP2);
			tP1 = headP1;
			tP2 = headP2;
			// doing the default removal of champions each round for each case
                        headP1 = removeChampion(headP1);
                        headP2 = removeChampion(headP2);	
			tP1 = headP1;
			tP2 = headP1;
                }
                else if((tP1->role == 2 && tP2->role == 3) || (tP1->role == 3 && tP2->role == 2))
                {
                        if((tP1->role == 2 && tP2->role == 3))
                        {
                                printf("Player 1 (SUPPORT) loses but with no penalty.\n");
                                printf("Player 2 (TANK) wins and gains a new champion.\n\n");
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
				// adding a new champ to P2
				newChampP2 = createChampion();
				headP2 = addChampion(headP2, newChampP2);
				tP2 = headP2;
                        }
                        else if(tP1->role == 3 && tP2->role == 2)
                        {
                                printf("Player 1 (TANK) wins and gains a new champion.\n");
                                printf("Player 2 (SUPPORT) loses but with no penalty.\n\n");
                                // doing the default removal of champions after each round for reach case
                                headP1 = removeChampion(headP1);
                                headP2 = removeChampion(headP2);
                                tP1 = headP1;
                                tP2 = headP2;
				// adding a new champ to P1
				newChampP1 = createChampion();
				headP1 = addChampion(headP1, newChampP1);
				tP1 = headP1;
                        }
                }
                else if((tP1->role == 3 && tP2->role == 3))
                {
			printf("Nothing happens - no penalty or reward.\n\n");	
			// doing the default removal for each case
                        headP1 = removeChampion(headP1);
                        headP2 = removeChampion(headP2);
			tP1 = headP1;
			tP2 = headP2;
                }
		roundNum++;
	}while(tP1 != NULL && tP2 != NULL);

	printf("============ GAME OVER ============\n\n");
	printf("Player 1 ending champion list: ");
	printChampionList(headP1);
	printf("Player 2 ending champion list: ");
	printChampionList(headP2);

	if(headP1 == NULL && headP2 != NULL)
	{
		printf("\nPlayer 1 ran out of champions. Player 2 wins.\n\n");
	}
	else if(headP2 == NULL && headP1 != NULL)
	{
		printf("\nPlayer 2 ran out of champions. Player 1 wins.\n\n");
	}
	else if (headP1 == NULL && headP2 == NULL)
	{
		printf("\nTIE -- both players ran out of champions.\n\n");		
	}

	destroyChampionList(headP1);
	destroyChampionList(headP2);
	return 0;
}	
