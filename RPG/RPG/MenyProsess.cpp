#include "BattleProcess.h"

void MenyProsess(int SelectNum, tatakaimenu *list,int MaxArray) {//���ݑI������Ă���NUM
	//List�\���́A�z��̍ő吔

	int i;

	for (i = 0; i < MaxArray; i++) {              // ���j���[���ڐ��ł���5���[�v����
		if (i == SelectNum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f
			list[i].x = 80; // ���W��80�ɂ���
		}		else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
			list[i].x = 100; // ���W��100�ɂ���
		}
	}
}