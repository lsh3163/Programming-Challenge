//
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	while (true) {
		// the number of soldiers, the nubmer of loss reports
		int S, B;
		scanf("%d %d", &S, &B);
		if (S == 0 && B == 0) {
			break;
		}
		// a loss report
		int L, R;
		int leftans, rightans;
		leftans = S;
		rightans = 1;
		for (int i = 1; i <= B; i++) {
			scanf("%d %d", &L, &R);
			leftans = min(leftans, L);
			rightans = max(rightans, R);
			if (leftans == 1 && rightans==S) {
				printf("* *\n");
				break;
			}
			else if (leftans == 1) {
				printf("* %d\n", rightans + 1);
			}
			else if (rightans == S) {
				printf("%d *\n", leftans - 1);
			}
			else printf("%d %d\n", leftans - 1, rightans + 1);
		}
		printf("-\n");
	}
	return 0;
}

