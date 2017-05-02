#include <stdio.h>
#include "main_aux.h"
#include "sp_nim.h"
#include "SPBufferset.h"
#define SIZE 32

int main() {
	SP_BUFF_SET();
	int numHeaps, val = 0, cnt = 1, digit, turns = -1, userHeap, userOut, compHeap = 0;
	char input;
	int heapsArr[SIZE] = {0}, compOut[1] = {0};
	printf("Enter the number of heaps:\n");
	if (scanf("%d", &numHeaps) < 1 || checkNumHeaps(numHeaps) == 0) {
		printf("Error: the number of heaps must be between 1 and 32.\n");
		return 0;
	}
	printf("Enter the heaps sizes:\n");
	input = getchar();
	while ((input = getchar()) != EOF && input != '\n') {
		if (input != ' ') {
			if ((val == 0 && input > '0' && input <= '9') ||
					(val > 0 && input >= '0' && input <= '9')) {
				digit = input - '0';
				val = val * 10 + digit;
			} else { //input is not valid
				printf("Error: the size of heap %d should be positive.\n", cnt);
				return 0;
			}
		} else { // the curr heap size is ready
			heapsArr[cnt - 1] = val;
			cnt++;
			val = 0;
		}
	}
	heapsArr[cnt - 1] = val; //for the last input
	while (checkEmpty(heapsArr, numHeaps) == 0) {
		turns++;
		printStatus(heapsArr, turns, numHeaps);
		if (turns % 2 == 1) { //user turn
			printRep(heapsArr, numHeaps);
			printf("Your turn: please enter the heap index and the number of removed objects.\n");
			scanf("%d %d", &userHeap, &userOut);
			while (checkValid(userHeap, userOut, heapsArr, numHeaps) == 0) { //not valid
				printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
				scanf("%d %d", &userHeap, &userOut);
			}
			turnGame(heapsArr, userHeap, userOut);
			printf("You take %d objects from heap %d.\n", userOut, userHeap + 1);
		} else { //computer turn
			compHeap = compMove(heapsArr, compOut, numHeaps);
			printf("Computer takes %d objects from heap %d.\n", compOut[0], compHeap + 1);
		}
	}
	//winning declaration
	if (turns % 2 == 0)
		printf("Computer wins!\n");
	else
		printf("You win!\n");
}

