#include "DxLib.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(800, 640, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	int i,j,k, masu[20][10], gazou[8],count;//i,j,k=カウンタ,masu=ブロックを表す配列,gazou=画像格納,count=ボタンを押されたフレーム用のカウント変数
	int LinePoint = 0, Linenumber = 0;;// LinePoint=これまでに消したラインの合計,Linenumber=ラインを現在いくら消したかの数
	int l, m, e;//カウンタ
	int flg = 0,LineX;
	gazou[0] = LoadGraph("画像/背景.png");
	gazou[1] = LoadGraph("画像/自分.png");
	gazou[2] = LoadGraph("画像/自分.png");
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			masu[i][j] = 0;
		}
	}

	masu[0][5]=1;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
		if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
			count++;
			if (count % 5 == 0) {
				for (i = 19; i >= 0 ; i--) {
					for (j = 9; j >= 0; j--) {
						if (masu[i][j] == 1 && masu[i+1][j] == 0) {
							masu[i + 1][j] = 1;
							masu[i][j] = 0;
						}
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_UP) == 1) {
			count++;
			if (count % 5 == 0) {
				for (i = 0; i < 20; i++) {
					for (j = 0; j < 10; j++) {
						if (i!=19) {
							if (masu[i][j] == 1 && masu[i - 1][j] == 0) {
								masu[i - 1][j] = 1;
								masu[i][j] = 0;
							}
						}
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			count++;
			if (count % 5 == 0) {
				for (i = 19; i >= 0; i--) {
					for (j = 9; j >= 0; j--) {
						if (masu[i][j] == 1 && masu[i][j+1] == 0) {
							if (j != 9) {
								masu[i][j + 1] = 1;
								masu[i][j] = 0;
							}
						}
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			count++;
			if (count % 5 == 0) {
				for (i = 0; i < 20; i++) {
					for (j = 0; j < 10; j++) {
						if (masu[i][j] == 1 && masu[i][j-1] == 0) {
							if (j != 0) {
								masu[i][j - 1] = 1;
								masu[i][j] = 0;
							}
						}
					}
				}
			}
		}
		
		for (i = 19; i >= 0; i--) {//自分（ブロック）が一番下まで来た時の処理
			for (j = 9; j >= 0; j--) {
				if (masu[i][j] == 1) {
					if (masu[i + 1][j] != 0) {//背景以外（＝なにかのブロックが入っているとき）
						masu[0][5] = 1;//初期地点に戻る
						masu[i][j] = 2;//現在のブロックを固定
						flg = 1;
					}
				}
			}
			if (masu[i][0] != 0 && masu[i][1] != 0 && masu[i][2] != 0 && masu[i][3] != 0 &&//ブロックが一列揃った場合の処理
				masu[i][4] != 0 && masu[i][5] != 0 && masu[i][6] != 0 && masu[i][7] != 0 &&
				masu[i][8] != 0 && masu[i][9] != 0 && flg == 1) {//一列すべてが背景以外なら
				flg = 1;
				LineX = i;
				for (j = 9; j >= 0; j--) {
					masu[0][5] = 1;
					masu[i][j] = 0;//マス初期化
					LinePoint++;//ラインを消した合計加算
					Linenumber++;
				}
				for (LineX; LineX > 0; LineX--) {
					for (k = 9; k >= 0; k--) {
						masu[LineX][k] = masu[LineX - 1][k];
						masu[LineX - 1][k] = 0;
					}
				}
				flg = 0;
			}
		}

		for (i = 0; i < 20; i++) {//ブロックの種類によって描写
			for (j = 0; j < 10; j++) {
				if (masu[i][j] == 0) {
					DrawGraph(32 * j + 200, 32 * i, gazou[0], TRUE);
				}
				if (masu[i][j] == 1) {
					DrawGraph(32 * j + 200, 32 * i, gazou[1], TRUE);
				}
				if (masu[i][j] == 2) {
					DrawGraph(32 * j + 200, 32 * i, gazou[2], TRUE);
				}
			}
		}

		if (CheckHitKey(KEY_INPUT_Z) == 1) {//終了コマンド
			break;
		}
		
	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}