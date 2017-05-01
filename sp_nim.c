/*
 * sp_nim.c
 *
 *  Created on: 1 במאי 2017
 *      Author: uri
 */

int checkEmpty(int heapsArr[]) {
	int i;
	for (i = 0; i < sizeof(heapsArr) / sizeof(int); i++) {
		if (heapsArr[i] != 0)
			return 0;
	}
	return 1;
}

void turnGame(int heapsArr[], int heapIndex, int outAmount) {
	heapsArr[heapIndex - 1] -= outAmount;
}

int compMove(int heapsArr[], int *compOut) {
	int sNim, i, length, nimSumHeap, compHeap, compParam;
	length = sizeof(heapsArr) / sizeof(int);
	sNim = heapsArr[0];
	for (i = 1; i < length; i++) {
		sNim ^= heapsArr[i];
	}
	if (sNim != 0) {
		for (i = 0; i < length; i++) {
			nimSumHeap = heapsArr[i] ^ sNim;
			if (nimSumHeap < heapsArr[i]) {
				compParam = i;
				break;
			}
		}
		compOut = nimSumHeap;
		heapsArr[compParam] -= compOut;
	} else { //sNim =0
		for (i = 0; i < length; i++) {
			if (heapsArr[i] > 0) {
				compParam = i;
				break;
			}
		}
		compOut = 1;
		heapsArr[compHeap] -= compOut;
	}
	*compOut = compParam;
	return compHeap;

}
