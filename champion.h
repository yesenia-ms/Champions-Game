#ifndef CHAMPION_H
#define CHAMPION_H

typedef enum ChampionRole
{
	MAGE,
	FIGHTER,
	SUPPORT,
	TANK
}ChampionRole;

typedef struct Champion
{
	ChampionRole role;
	int level;
	struct Champion* next;
} Champion;

Champion* createChampion();
Champion* addChampion(Champion*, Champion*);
Champion* buildChampionList(int);
void printChampionList(Champion*);
Champion* removeChampion(Champion*);
Champion* destroyChampionList(Champion*);
#endif
