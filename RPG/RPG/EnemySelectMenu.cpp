#include "BattleProcess.h"

void EnemySelectMenu1(int *SelectNum, tatakaimenu *EnemySelectMenu1, int MaxArray, Enemy *MonsterCopyData){
	//List�\���́A�z��̍ő�
	int i;
	for (i = 0; i < MaxArray; i++) {              // ���j���[���ڐ��ł���5���[�v����
		if (i == *SelectNum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f

			EnemySelectMenu1[i].x = 240; // ���W��80�ɂ���
		}		else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
			EnemySelectMenu1[i].x = 220; // ���W��100�ɂ���
		}
	}
}