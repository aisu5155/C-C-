void KeyFlame(int *Keyflame, char *AllKey) {
	int i;
	for (i = 0; i<256; i++) {
		if (AllKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Keyflame[i]++;     // ���Z
		}		else {             // ������Ă��Ȃ����
			Keyflame[i] = 0;   // 0�ɂ���
		}
	}
}