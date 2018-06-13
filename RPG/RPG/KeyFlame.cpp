void KeyFlame(int *Keyflame, char *AllKey) {
	int i;
	for (i = 0; i<256; i++) {
		if (AllKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Keyflame[i]++;     // 加算
		}		else {             // 押されていなければ
			Keyflame[i] = 0;   // 0にする
		}
	}
}