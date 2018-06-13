#include "BattleProcess.h"

void MenyProsess(int SelectNum, tatakaimenu *list,int MaxArray) {//現在選択されているNUM
	//List構造体、配列の最大数

	int i;

	for (i = 0; i < MaxArray; i++) {              // メニュー項目数である5個ループ処理
		if (i == SelectNum) {          // 今処理しているのが、選択番号と同じ要素
			list[i].x = 80; // 座標を80にする
		}		else {                       // 今処理しているのが、選択番号以外なら
			list[i].x = 100; // 座標を100にする
		}
	}
}