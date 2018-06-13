#pragma once

typedef struct Enemy//敵データ構造体
{
	char NAME[20];
	int Image;
	int NUMBER;
	int HP;
	int ATTACK;
	int DEFENSE;
	int INT;
	int SPEED;
	int GOLD;
	int EXP;
}Enemy;

typedef struct MainCharacter//主人公構造体
{
	char NAME[20];
	int MAXLEVEL;
	int NowLEVEL;
	int HP;
	int ATTACK;
	int DEFENSE;
	int INT;
	int SPEED;
	int SUMEXP;
}MainCharacter;

typedef struct tatakaimenu//戦闘構造体
{
	int x, y;
	char menuname[20];
}tatakaimenu;

void MenyProsess(int SelectNum, tatakaimenu *list, int MaxArray);
void EnemySelectMenu1(int *SelectNum, tatakaimenu *EnemySelectMenu1, int MaxArray,Enemy *MonsterCopyData);

void BattleProcess(int *SelectNum,Enemy *monster,MainCharacter *Hero, char *AllKey, int *EnemyAllNumber, tatakaimenu *list, int *EnemyNumber,int *Keyflame, int tatakauMenuflg, int *EnemySelect);
void EnemyDataSet(int *EnemyAllNumber, int *EnemyNumber, Enemy *monster, Enemy *MonsterCopyData);

void NormalAttack(int *EnemySelect, Enemy *MonsterCopyData, MainCharacter *Hero1);