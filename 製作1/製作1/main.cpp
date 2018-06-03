#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(800, 640, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	int i, j, masu[20][10], gazou[8],count;

	gazou[0] = LoadGraph("�摜/�w�i.png");
	gazou[1] = LoadGraph("�摜/����.png");

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
				for (i = 0; i < 20; i++) {//�`��
					for (j = 0; j < 10; j++) {
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
				for (i = 0; i < 20; i++) {//�`��
					for (j = 0; j < 10; j++) {
						if (masu[i][j] == 1 && masu[i - 1][j] == 0) {
							masu[i - 1][j] = 1;
							masu[i][j] = 0;
						}
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			count++;
			if (count % 5 == 0) {
				for (i = 0; i < 20; i++) {//�`��
					for (j = 0; j < 10; j++) {
						if (masu[i][j] == 1 && masu[i][j+1] == 0) {
							masu[i][j+1] = 1;
							masu[i][j] = 0;
						}
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			count++;
			if (count % 5 == 0) {
				for (i = 0; i < 20; i++) {//�`��
					for (j = 0; j < 10; j++) {
						if (masu[i][j] == 1 && masu[i][j-1] == 0) {
							masu[i][j-1] = 1;
							masu[i][j] = 0;
						}
					}
				}
			}
		}








		for (i = 0; i < 20; i++) {//�`��
			for (j = 0; j < 10; j++) {
				if (masu[i][j] == 0) {
					DrawGraph(32 * j + 200, 32 * i, gazou[0], TRUE);
				}
				if (masu[i][j] == 1) {
					DrawGraph(32 * j + 200, 32 * i, gazou[1], TRUE);
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
			break;
		}
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}