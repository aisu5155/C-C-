int KeyUP(int y,int *monstercount){
	y -= 3;
	*monstercount = *monstercount + 10;
	return y;
}