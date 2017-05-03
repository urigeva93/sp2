/*
 * main_aux.c
 *
 *  Created on: 1 במאי 2017
 *      Author: uri and maya
 */

#include <stdio.h>

int checkNumHeaps(int numHeaps) {
	if (numHeaps < 1 || numHeaps > 32)
		return 0;
	return 1;
}

void printStatus(int heapsArr[], int turns, int N) {
	printf("In turn %d heap sizes are: ", turns + 1);
	for (int i = 0; i < N - 1; i++) {
		printf("h%d=%d ", i + 1, heapsArr[i]);
	}
	// the last print don't need space after
	printf("h%d=%d.\n", N, heapsArr[N - 1]);
}

void printRep(int heapsArr[], int N) {
	int max = 0;
	//find the max
	for (int i = 0; i < N; i++) {
		if (heapsArr[i] > max)
			max = heapsArr[i];
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (i >= max - heapsArr[j])
				printf("*\t");
			else
				printf(" \t");
		}
		//the last object in line doesn't need space after
		if(i >= max - heapsArr[N -1])
			printf("*");
		else
			printf(" ");

		printf("\n");
	}
}

int checkValid(int userHeap, int userOut, int heapsArr[], int N) {
	if (userHeap >= 1 && userHeap <= N && heapsArr[userHeap - 1] >= userOut
			&& userOut > 0) {
		return 1;
	}
	return 0;
}
