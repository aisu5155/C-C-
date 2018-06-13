#include "BattleProcess.h"
#include "DxLib.h"
#include "KeyFlame.h"

void BattleProcess(int *SelectNum,Enemy *MonsterCopyData,MainCharacter *Hero1,char *AllKey,int *EnemyAllNumber,tatakaimenu *list,int *EnemyNumber,int *Keyflame,int tatakauMenuflg,int *EnemySelect){
	int i;

	switch (*SelectNum) {
	case 0://‚½‚½‚©‚¤‚Ì‚Æ‚«
		if (AllKey[KEY_INPUT_RETURN] == 1) {
			MonsterCopyData[*EnemySelect].HP = MonsterCopyData[*EnemySelect].HP - Hero1[0].ATTACK;
		}
		break;
	case 1://‚¶‚ã‚à‚ñ‚Ì‚Æ‚«
		break;
	case 2://‚Æ‚­‚¬‚Ì‚Æ‚«
		break;
	case 3://‚Ç‚¤‚®‚Ì‚Æ‚«
		break;
	case 4://‚É‚°‚é‚Ì‚Æ‚«
		break;
	case 5://‚³‚­‚¹‚ñ‚Ì‚Æ‚«
		break;
	default:
		break;
	}
}