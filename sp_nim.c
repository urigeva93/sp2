/*
 * sp_nim.c
 *
 *  Created on: 1 may 2017
 *      Author: uri and maya
 */

#include <stdio.h>

int checkEmpty(int heapsArr[], int N) {
	for (int i = 0; i < N; i++) {
		if (heapsArr[i] != 0)
			return 0;
	}
	return 1;
}

void turnGame(int heapsArr[], int heapIndex, int outAmount) {
	heapsArr[heapIndex - 1] -= outAmount;
}

int compMove(int heapsArr[], int compOut[], int N) {
	int sNim, nimSumHeap, compHeap = 0, compParam;
	sNim = 0;
	//compute sNim
	for (int i = 0; i < N; i++) {
		sNim ^= heapsArr[i];
	}
	if (sNim != 0) {
		for (int i = 0; i < N; i++) {
			nimSumHeap = heapsArr[i] ^ sNim;
			if (nimSumHeap < heapsArr[i]) {
				compHeap = i;
				break;
			}
		}
		compParam = heapsArr[compHeap] - nimSumHeap;
		heapsArr[compHeap] -= compParam;
	} else { //sNim = 0
		for (int i = 0; i < N; i++) {
			if (heapsArr[i] > 0) {
				compHeap = i;
				break;
			}
		}
		compParam = 1;
		heapsArr[compHeap] -= compParam;
	}
	//in order to return 2 values
	compOut[0] = compParam;
	return compHeap;
}
