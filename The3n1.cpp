#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int low, high, j;
	int plow, phigh;
	while (cin >> low >> high){
		plow = low;
		phigh = high;
		if (low > high){
			swap(low, high);
		}
		int l = 0;
		int ml = 0;
		for (int i = low; i <= high; i++){
			j = i;
			l = 1;
			while (j != 1){
				if (j & 1){
					j = j * 3 + 1;
					l++;
				}
				while (!(j & 1)){
					j >>= 1;
					l++;
				}
			}
			if (l > ml){
				ml = l;
			}
		}
		printf("%d %d %d\n", plow, phigh, ml);
	}
	_getch();
}
