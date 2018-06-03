#include "DxLib.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(800, 640, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	int i,j,k, masu[20][10], gazou[8],count;//i,j,k=�J�E���^,masu=�u���b�N��\���z��,gazou=�摜�i�[,count=�{�^���������ꂽ�t���[���p�̃J�E���g�ϐ�
	int LinePoint = 0, Linenumber = 0;;// LinePoint=����܂łɏ��������C���̍��v,Linenumber=���C�������݂�������������̐�
	int l, m, e;//�J�E���^
	int flg = 0,LineX;
	gazou[0] = LoadGraph("�摜/�w�i.png");
	gazou[1] = LoadGraph("�摜/����.png");
	gazou[2] = LoadGraph("�摜/����.png");
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
		
		for (i = 19; i >= 0; i--) {//�����i�u���b�N�j����ԉ��܂ŗ������̏���
			for (j = 9; j >= 0; j--) {
				if (masu[i][j] == 1) {
					if (masu[i + 1][j] != 0) {//�w�i�ȊO�i���Ȃɂ��̃u���b�N�������Ă���Ƃ��j
						masu[0][5] = 1;//�����n�_�ɖ߂�
						masu[i][j] = 2;//���݂̃u���b�N���Œ�
						flg = 1;
					}
				}
			}
			if (masu[i][0] != 0 && masu[i][1] != 0 && masu[i][2] != 0 && masu[i][3] != 0 &&//�u���b�N����񑵂����ꍇ�̏���
				masu[i][4] != 0 && masu[i][5] != 0 && masu[i][6] != 0 && masu[i][7] != 0 &&
				masu[i][8] != 0 && masu[i][9] != 0 && flg == 1) {//��񂷂ׂĂ��w�i�ȊO�Ȃ�
				flg = 1;
				LineX = i;
				for (j = 9; j >= 0; j--) {
					masu[0][5] = 1;
					masu[i][j] = 0;//�}�X������
					LinePoint++;//���C�������������v���Z
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

		for (i = 0; i < 20; i++) {//�u���b�N�̎�ނɂ���ĕ`��
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

		if (CheckHitKey(KEY_INPUT_Z) == 1) {//�I���R�}���h
			break;
		}
		
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}