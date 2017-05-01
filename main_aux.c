/*
 * main_aux.c
 *
 *  Created on: 1 במאי 2017
 *      Author: uri and maya
 */

int checkNumHeaps(int numHeaps) {
	if (numHeaps < 1 || numHeaps > 32)
		return 0;
	return 1;
}

void printStatus(int heapsArr[], int turns) {
	int length, i;
	length = sizeof(heapsArr) / sizeof(int);
	printf("In turn %d heap sizes are: ", turns);
	for (i = 0; i < length - 1; i++) {
		printf("h%d=%d ", i + 1, heapsArr[i]);
	}
	printf("h%d=%d.\n", length, heapsArr[length - 1]);
}

void printRep(int heapsArr[]) {
	int length, i, j, max = 0;
	const int height, weight;
	length = sizeof(heapsArr) / sizeof(int);
	weight = length;

	//find the max
	for (i = 0; i < length; i++) {
		if (heapsArr[i] > max)
			max = heapsArr[i];
	}
	height = max;
	for (i = 0; i < height; i++) {
		for (j = 0; j < weight; j++) {
			if (i >= max - heapsArr[j])
				printf("*\t");
			else
				printf("\t");
		}
		printf("\n");
	}
}

int checkValid(int userHeap, int userOut, int heapsArr[]) {
	int length;
	length = sizeof(heapsArr) / sizeof(int);
	if (userHeap < length - 1 && userHeap > 0
	&& heapsArr[userHeap - 1] >= userOut && userOut > 0) {
		return 1;
	}
	return 0;
}
