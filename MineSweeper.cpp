#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
char board[101][101];
int ans[101][101];
int dx[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int dy[] = { 0, 0, -1, 1, 1, -1, 1, -1 };
int main(){
	int n, m;
	int cnt = 1;
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0){
			break;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> board[i][j];
			}
		}
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (board[i][j] == '*'){
					for (int d = 0; d < 8; d++){
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
							if (board[nx][ny] != '*'){
								ans[nx][ny]++;
							}
						}
					}
				}
			}
		}
		if (cnt > 1) printf("\n");
		printf("Field #%d:\n", cnt);
		cnt++;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (board[i][j] == '*'){
					printf("*");
				}
				else{
					printf("%d", ans[i][j]);
				}
			}
			printf("\n");
		}
	}
	_getch();
}
