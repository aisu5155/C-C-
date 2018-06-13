#pragma warning(disable:4996)

#include "DxLib.h"
#include "�L�����f�[�^�ϐ��錾.h"
#include "�V�X�e���ϐ��錾.h"
#include "BattleProcess.h" //enemy,mainch,tatakaimenu�̍\���̘̂g���`���Ă��܂�

#include "�L�����f�[�^�A���j���[���X�g�\���̐錾.h" //enemy,mainch�����邽��BattleProcess.h��艺�ɕK���u���B

#include "KeyUP.h"
#include "KeyDOWN.h"
#include "KeyRIGHT.h"
#include "KeyLEFT.h"
#include "KeyFlame.h"

#include <stdio.h>
#include <string.h>

#define  UpMainCharacter 0
#define  DownMainCharacter 1
#define  LightMainCharacter 2
#define  LeftMainCharacter 3

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	SetGraphMode(960, 640, 32);

	for (i = 0; i <= 2; i++) {
		EnemyNumber[i] = 0;
	}
	WorldMapImage = LoadGraph("Map�摜/World.png");
	MainCharacterWalkImage[UpMainCharacter] = LoadGraph("MainCharacter�摜/���@.png");
	MainCharacterWalkImage[DownMainCharacter] = LoadGraph("MainCharacter�摜/���@.png");
	MainCharacterWalkImage[LightMainCharacter] = LoadGraph("MainCharacter�摜/���@.png");
	MainCharacterWalkImage[LeftMainCharacter] = LoadGraph("MainCharacter�摜/���@.png");

	monster[0].Image = LoadGraph("Enemy�摜/�X���C��.png");
	monster[1].Image = LoadGraph("Enemy�摜/�X���C���x�X.png");
	monster[2].Image = LoadGraph("Enemy�摜/�S�[����.png");
	monster[3].Image = LoadGraph("Enemy�摜/�����񂶂�.png");
	monster[4].Image = LoadGraph("Enemy�摜/�ЂƂ����΂�.png");
	monster[5].Image = LoadGraph("Enemy�摜/�M�K���e�X.png");
	monster[6].Image = LoadGraph("Enemy�摜/���^���X���C��.png");

	for (i = 0; i <= 6;i++) {
		MonsterCopyData[i].Image = monster[i].Image;
	}
	
	RandomEncounter = GetRand(50) + 50;//�G�Ƃ̑�������U�ꕝ�ݒ�

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
		GetHitKeyStateAll(AllKey);//�L�[�擾
		KeyFlame(Keyflame, AllKey);//�L�[��������Ă���t���[���擾

		if (AllKey[KEY_INPUT_UP] == 1) {
			y = KeyUP(y, &monstercount);//��������ꂽ���ɁAy�̃f�[�^�ƃ����X�^�[�ɉ�܂ł̎��Ԃ��i�[���Ă���A�h���X��n���B
		}
		else if (AllKey[KEY_INPUT_DOWN] == 1) {
			y = KeyDOWN(y, &monstercount);//���������ꂽ���ɁAy�̃f�[�^�ƃ����X�^�[�ɉ�܂ł̎��Ԃ��i�[���Ă���A�h���X��n���B
		}
		else if (AllKey[KEY_INPUT_RIGHT] == 1) {
			x = KeyRIGHT(x, &monstercount);//�E�������ꂽ���ɁAx�̃f�[�^�ƃ����X�^�[�ɉ�܂ł̎��Ԃ��i�[���Ă���A�h���X��n���B
		}
		else if (AllKey[KEY_INPUT_LEFT] == 1) {
			x = KeyLEFT(x, &monstercount);//���������ꂽ���ɁAx�̃f�[�^�ƃ����X�^�[�ɉ�܂ł̎��Ԃ��i�[���Ă���A�h���X��n���B
		}

		if (tekiflg == 1) {//�퓬
			while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
				for (i = 0; i <= 6; i++) {
					MonsterCopyData[i].Image = monster[i].Image;
				}
				GetHitKeyStateAll(AllKey);//�L�[�擾
				KeyFlame(Keyflame, AllKey);//�L�[��������Ă���t���[���擾

				if (AllKey[KEY_INPUT_DOWN] == 1 && Keyflame[KEY_INPUT_DOWN] == 1 && EnemyMenuFlg == 0) { // ���L�[�������ꂽ�u�Ԃ�������
					SelectNum = (SelectNum + 1) % 6; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)
				}
				else if(AllKey[KEY_INPUT_DOWN] == 1 && Keyflame[KEY_INPUT_DOWN] == 1 && EnemyMenuFlg == 1){
					do {
						EnemySelect = (EnemySelect + 1) % EnemyAllNumber;
					}while (MonsterCopyData[EnemySelect].HP <= 0);
				}

				if (AllKey[KEY_INPUT_UP] == 1 && Keyflame[KEY_INPUT_UP] == 1 && EnemyMenuFlg == 0) { // ��L�[�������ꂽ�u�Ԃ�������
					SelectNum = (SelectNum + 5) % 6; // ���݂̑I�����ڂ����ɂ��炷(�t���[�v����)
				}
				else if (AllKey[KEY_INPUT_UP] == 1 && Keyflame[KEY_INPUT_UP] == 1 && EnemyMenuFlg == 1) {
					do {
						EnemySelect = (EnemySelect + (EnemyAllNumber-1)) % EnemyAllNumber;
					} while (MonsterCopyData[EnemySelect].HP <= 0);
				}
				

				if (AllKey[KEY_INPUT_DOWN] == 1 && Keyflame[KEY_INPUT_DOWN] == 1 && EnemyMenuFlg == 0 || AllKey[KEY_INPUT_UP] == 1 && Keyflame[KEY_INPUT_UP] == 1 && EnemyMenuFlg == 0) { // ���L�[���A��L�[�������ꂽ�u��
					MenyProsess(SelectNum, list, 6);
				}
				else if (AllKey[KEY_INPUT_DOWN] == 1 && Keyflame[KEY_INPUT_DOWN] == 1 && EnemyMenuFlg == 1 || AllKey[KEY_INPUT_UP] == 1 && Keyflame[KEY_INPUT_UP] == 1 && EnemyMenuFlg == 1) {
					EnemySelectMenu1(&EnemySelect, EnemySelectMenu, EnemyAllNumber,MonsterCopyData);
				}

				if (AllKey[KEY_INPUT_RETURN] == 1 && Keyflame[KEY_INPUT_RETURN] == 1 && EnemyMenuFlg == 1) {
					NormalAttack(&EnemySelect, MonsterCopyData, Hero);
				}

				if (AllKey[KEY_INPUT_RETURN] == 1 && Keyflame[KEY_INPUT_RETURN] == 1 && EnemyMenuFlg == 0) {
					switch (SelectNum) {
					case 0://�키
						EnemyMenuFlg = 1;
						break;
					case 1:
						break;
					default:
						break;
					}
					
				}

				if (AllKey[KEY_INPUT_ESCAPE] == 1 && Keyflame[KEY_INPUT_ESCAPE] == 1) {
					EnemyMenuFlg = 0;
				}

				if (AllKey[KEY_INPUT_Z] == 1 && Keyflame[KEY_INPUT_Z] == 1) {
					EnemyMenuFlg = 0;
					tekiflg = 0;
					monstercount = 0;
					RandomEncounter = GetRand(100);
					break;
				}
				
				for (i = 0; i <= EnemyAllNumber - 1; i++) {
					if (MonsterCopyData[i].HP <= 0) {
						if (MonsterCopyData[i].Image == 1){
							continue;
						}
						tempEXP +=  MonsterCopyData[i].EXP;
						tempGOLD += MonsterCopyData[i].GOLD;
						MonsterCopyData[i].EXP = 0;
						MonsterCopyData[i].GOLD = 0;
						MonsterCopyData[i].Image = 1;
					}	
				}
				if (MonsterCopyData[0].HP <= 0 &&
					MonsterCopyData[1].HP <= 0 &&
					MonsterCopyData[2].HP <= 0){
					EnemyMenuFlg = 0;
					Hero[0].SUMEXP += tempEXP;
					AllGold += tempGOLD;
					tempEXP = 0;
					tempGOLD = 0;
					tekiflg = 0;
					monstercount = 0;
					RandomEncounter = GetRand(100);
					for (i = 0; i <= EnemyAllNumber - 1; i++) {
						MonsterCopyData[i].Image = 1;
					}
					break;
				}

				if (EnemyMenuFlg == 1) {
					for (i = 0; i <= EnemyAllNumber - 1; i++) {
						if (MonsterCopyData[i].Image == 1) {
							continue;
						}
						DrawFormatString(EnemySelectMenu[i].x, EnemySelectMenu[i].y, GetColor(255, 255, 255), "%d %s", i + 1, MonsterCopyData[i].NAME);
					}
				}
				for (i = 0; i < 6; i++) { // ���j���[���ڂ�`��
					DrawFormatString(list[i].x, list[i].y, GetColor(255, 255, 255), list[i].menuname);
				}
				for (i = 0; i <= EnemyAllNumber - 1; i++) {//�G�@HP�\��
					if (MonsterCopyData[i].Image == 1) {
						continue;
					}
					DrawGraph(200 + (i * 140), 120, monster[EnemyNumber[i]].Image, TRUE);
					DrawFormatString(650, 120 + (i * 20), GetColor(255, 255, 255), "%s��HP %d �ł�", MonsterCopyData[i].NAME, MonsterCopyData[i].HP);
				}
				tekiflg = 0;
			}
		}

		if (monstercount + RandomEncounter % 200 >= 199) {
			tekiflg = 1;
			EnemyDataSet(&EnemyAllNumber, EnemyNumber, monster, MonsterCopyData);
		}

		DrawGraph(0, 0, WorldMapImage, TRUE);
		DrawGraph(x, y, MainCharacterWalkImage[0], TRUE);
		DrawFormatString(650, 210, GetColor(255, 128, 0), "�G�Ƃ�count %d�@200�ő���", monstercount + RandomEncounter);
		DrawFormatString(650, 240, GetColor(255, 128, 255), "%s��EXP %d �ł�", Hero[0].NAME, Hero[0].SUMEXP);
		DrawFormatString(650, 270, GetColor(255, 128, 255), "����܂ł̊l���S�[���h %d �ł�", AllGold);
		if (AllKey[KEY_INPUT_Z] == 1 && Keyflame[KEY_INPUT_Z] == 1) {

		}
	}
	DxLib_End(); // DX���C�u�����I������
	return 0;
}
