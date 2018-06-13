#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include "DxLib.h"
#include "BattleProcess.h"

void EnemyDataSet(int *EnemyAllNumber, int *EnemyNumber, Enemy *monster, Enemy *MonsterCopyData) {

	int i = 0;

	*EnemyAllNumber = GetRand(2) + 1;//0-2+1 = 1~3‚Ü‚Å“G‚Ì”İ’è

	for (i = 0; i <= *EnemyAllNumber - 1; i++) {
		EnemyNumber[i] = GetRand(6);
	}

	for (i = 0; i <= *EnemyAllNumber - 1; i++) {
		strcpy(MonsterCopyData[i].NAME, monster[EnemyNumber[i]].NAME);
		MonsterCopyData[i].NUMBER = monster[EnemyNumber[i]].NUMBER;
		MonsterCopyData[i].HP = monster[EnemyNumber[i]].HP;
		MonsterCopyData[i].ATTACK = monster[EnemyNumber[i]].ATTACK;
		MonsterCopyData[i].DEFENSE = monster[EnemyNumber[i]].DEFENSE;
		MonsterCopyData[i].INT = monster[EnemyNumber[i]].INT;
		MonsterCopyData[i].SPEED = monster[EnemyNumber[i]].SPEED;
		MonsterCopyData[i].GOLD = monster[EnemyNumber[i]].GOLD;
		MonsterCopyData[i].EXP = monster[EnemyNumber[i]].EXP;

	}
}
