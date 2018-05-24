#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int N;
	while(cin >> N){
		bool check = true;
		if(N<1) check = false;
		vector<bool> Jolly(N+1,false);
		vector<int> arr(N+1);
		for(int i=1;i<=N;i++){
			cin >> arr[i];
		}
		for(int i=1;i<N;i++){
			int x = abs(arr[i]-arr[i+1]);
			if(x>=1 && x<N){
				Jolly[x] = true;
			}
		}
		for(int i=1;i<N;i++){
			if(!Jolly[i]) check=false;
		}
		if(check) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}
