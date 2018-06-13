#include "BattleProcess.h"

void NormalAttack(int *EnemySelect,Enemy *MonsterCopyData, MainCharacter *Hero1) {
	MonsterCopyData[*EnemySelect].HP = MonsterCopyData[*EnemySelect].HP - Hero1[0].ATTACK;
}