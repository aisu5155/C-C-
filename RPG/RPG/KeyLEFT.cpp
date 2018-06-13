int KeyLEFT(int x,int *monstercount) {
	x -= 3;
	*monstercount = *monstercount + 1;
	return x;
}