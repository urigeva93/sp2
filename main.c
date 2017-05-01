#include <stdio.h>
#include <main_aux.h>
#include <sp_nim.h>

int main() {
	int numHeaps, val, cnt = 1, digit, turns = -1, userHeap, userOut, compHeap, *compOut;
	char input;
	const int N;
	printf("Enter the number of heaps:\n");
	if (scanf("%d", &numHeaps) < 1 || checkNumHeaps(numHeaps) == 0) {
		printf("Error: the number of heaps must be between 1 and 32.\n");
		return 0;
	}
	N = numHeaps;
	int heapsArr[N];
	printf("Enter the heaps sizes:\n");
	input = getchar();
	while ((input = getchar()) != EOF && input != '\n') {
		if (input != ' ') {
			if (input >= '0' && input <= '9') { //check this
				digit = input - '0';
				val = val * 10 + digit;
			} else { //input is not valid
				printf("Error: the size of heap %d should be positive.\n", cnt);
				return 0;
			}
		} else { //the input is space
			heapsArr[cnt - 1] = val;
			cnt++;
			val = 0;
		}
	}
	heapsArr[cnt - 1] = val; //for the last input
	while (checkEmpty(heapsArr) == 0) {
		turns++;
		printStatus(heapsArr, turns);

		if (turns % 2 == 1) { //user turn
			printRep(heapsArr);
			printf("Your turn: please enter the heap index and the number of removed objects.\n");
			scanf("%d %d", &userHeap, &userOut);
			while (checkValid(userHeap, userOut, heapsArr) == 0) { //not valid
				printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
				scanf("%d %d", &userHeap, &userOut);
			}
			turnGame(heapsArr, userHeap, userOut);
			printf("You take %d objects from heap %d.\n", userHeap, userOut);
		} else { //computer turn
			compHeap = compMove(heapsArr, compOut);
			printf("Computer takes %d objects from heap %d.\n", compHeap,*compOut);
		}
	}
	//winning declaration
	if (turns % 2 == 0)
		printf("Computer wins!\n");
	else
		printf("You win!\n");
}

