#pragma warning(disable:4996)

#include "DxLib.h"
#include "キャラデータ変数宣言.h"
#include "システム変数宣言.h"
#include "BattleProcess.h" //enemy,mainch,tatakaimenuの構造体の枠を定義しています

#include "キャラデータ、メニューリスト構造体宣言.h" //enemy,mainchがあるためBattleProcess.hより下に必ず置く。

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

	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定
	SetGraphMode(960, 640, 32);

	for (i = 0; i <= 2; i++) {
		EnemyNumber[i] = 0;
	}
	WorldMapImage = LoadGraph("Map画像/World.png");
	MainCharacterWalkImage[UpMainCharacter] = LoadGraph("MainCharacter画像/自機.png");
	MainCharacterWalkImage[DownMainCharacter] = LoadGraph("MainCharacter画像/自機.png");
	MainCharacterWalkImage[LightMainCharacter] = LoadGraph("MainCharacter画像/自機.png");
	MainCharacterWalkImage[LeftMainCharacter] = LoadGraph("MainCharacter画像/自機.png");

	monster[0].Image = LoadGraph("Enemy画像/スライム.png");
	monster[1].Image = LoadGraph("Enemy画像/スライムベス.png");
	monster[2].Image = LoadGraph("Enemy画像/ゴーレム.png");
	monster[3].Image = LoadGraph("Enemy画像/ももんじゃ.png");
	monster[4].Image = LoadGraph("Enemy画像/ひとくいばこ.png");
	monster[5].Image = LoadGraph("Enemy画像/ギガンテス.png");
	monster[6].Image = LoadGraph("Enemy画像/メタルスライム.png");

	for (i = 0; i <= 6;i++) {
		MonsterCopyData[i].Image = monster[i].Image;
	}
	
	RandomEncounter = GetRand(50) + 50;//敵との遭遇する振れ幅設定

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
		GetHitKeyStateAll(AllKey);//キー取得
		KeyFlame(Keyflame, AllKey);//キーを押されているフレーム取得

		if (AllKey[KEY_INPUT_UP] == 1) {
			y = KeyUP(y, &monstercount);//上を押された時に、yのデータとモンスターに会うまでの時間を格納しているアドレスを渡す。
		}
		else if (AllKey[KEY_INPUT_DOWN] == 1) {
			y = KeyDOWN(y, &monstercount);//下を押された時に、yのデータとモンスターに会うまでの時間を格納しているアドレスを渡す。
		}
		else if (AllKey[KEY_INPUT_RIGHT] == 1) {
			x = KeyRIGHT(x, &monstercount);//右を押された時に、xのデータとモンスターに会うまでの時間を格納しているアドレスを渡す。
		}
		else if (AllKey[KEY_INPUT_LEFT] == 1) {
			x = KeyLEFT(x, &monstercount);//左を押された時に、xのデータとモンスターに会うまでの時間を格納しているアドレスを渡す。
		}

		if (tekiflg == 1) {//戦闘
			while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
				for (i = 0; i <= 6; i++) {
					MonsterCopyData[i].Image = monster[i].Image;
				}
				GetHitKeyStateAll(AllKey);//キー取得
				KeyFlame(Keyflame, AllKey);//キーを押されているフレーム取得

				if (AllKey[KEY_INPUT_DOWN] == 1 && Keyflame[KEY_INPUT_DOWN] == 1 && EnemyMenuFlg == 0) { // 下キーが押された瞬間だけ処理
					SelectNum = (SelectNum + 1) % 6; // 現在の選択項目を一つ下にずらす(ループする)
				}
				else if(AllKey[KEY_INPUT_DOWN] == 1 && Keyflame[KEY_INPUT_DOWN] == 1 && EnemyMenuFlg == 1){
					do {
						EnemySelect = (EnemySelect + 1) % EnemyAllNumber;
					}while (MonsterCopyData[EnemySelect].HP <= 0);
				}

				if (AllKey[KEY_INPUT_UP] == 1 && Keyflame[KEY_INPUT_UP] == 1 && EnemyMenuFlg == 0) { // 上キーが押された瞬間だけ処理
					SelectNum = (SelectNum + 5) % 6; // 現在の選択項目を一つ上にずらす(逆ループする)
				}
				else if (AllKey[KEY_INPUT_UP] == 1 && Keyflame[KEY_INPUT_UP] == 1 && EnemyMenuFlg == 1) {
					do {
						EnemySelect = (EnemySelect + (EnemyAllNumber-1)) % EnemyAllNumber;
					} while (MonsterCopyData[EnemySelect].HP <= 0);
				}
				

				if (AllKey[KEY_INPUT_DOWN] == 1 && Keyflame[KEY_INPUT_DOWN] == 1 && EnemyMenuFlg == 0 || AllKey[KEY_INPUT_UP] == 1 && Keyflame[KEY_INPUT_UP] == 1 && EnemyMenuFlg == 0) { // 下キーか、上キーが押された瞬間
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
					case 0://戦う
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
				for (i = 0; i < 6; i++) { // メニュー項目を描画
					DrawFormatString(list[i].x, list[i].y, GetColor(255, 255, 255), list[i].menuname);
				}
				for (i = 0; i <= EnemyAllNumber - 1; i++) {//敵　HP表示
					if (MonsterCopyData[i].Image == 1) {
						continue;
					}
					DrawGraph(200 + (i * 140), 120, monster[EnemyNumber[i]].Image, TRUE);
					DrawFormatString(650, 120 + (i * 20), GetColor(255, 255, 255), "%sのHP %d です", MonsterCopyData[i].NAME, MonsterCopyData[i].HP);
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
		DrawFormatString(650, 210, GetColor(255, 128, 0), "敵とのcount %d　200で遭遇", monstercount + RandomEncounter);
		DrawFormatString(650, 240, GetColor(255, 128, 255), "%sのEXP %d です", Hero[0].NAME, Hero[0].SUMEXP);
		DrawFormatString(650, 270, GetColor(255, 128, 255), "これまでの獲得ゴールド %d です", AllGold);
		if (AllKey[KEY_INPUT_Z] == 1 && Keyflame[KEY_INPUT_Z] == 1) {

		}
	}
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
