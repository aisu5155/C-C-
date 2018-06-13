#include "BattleProcess.h"

void EnemySelectMenu1(int *SelectNum, tatakaimenu *EnemySelectMenu1, int MaxArray, Enemy *MonsterCopyData){
	//List構造体、配列の最大
	int i;
	for (i = 0; i < MaxArray; i++) {              // メニュー項目数である5個ループ処理
		if (i == *SelectNum) {          // 今処理しているのが、選択番号と同じ要素

			EnemySelectMenu1[i].x = 240; // 座標を80にする
		}		else {                       // 今処理しているのが、選択番号以外なら
			EnemySelectMenu1[i].x = 220; // 座標を100にする
		}
	}
}