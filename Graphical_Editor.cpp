#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
char board[251][251];
int m, n;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
void fill_color(int x, int y, char oc, char nc){
	board[y][x] = nc;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= m && ny >= 1 && ny <= n){
			if (board[ny][nx] == oc){
				fill_color(nx, ny, oc, nc);
			}
		}
	}
}
int main(){
	while (true){
		char wtd;
		cin >> wtd;
		//OK
		if (wtd == 'X') break;
		//OK
		else if (wtd == 'I'){
			cin >> m >> n;
			for (int i = 1; i <= 250; i++){
				for (int j = 1; j <= 250; j++){
					board[i][j] = 'O';
				}
			}
		}
		//OK
		else if (wtd == 'C'){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					board[i][j] = 'O';
				}
			}
		}
		//OK
		else if (wtd == 'L'){
			int x, y;
			cin >> x >> y;
			char color;
			cin >> color;
			board[y][x] = color;
		}
		//OK
		else if (wtd == 'V'){
			int x, y1, y2;
			cin >> x >> y1 >> y2;
			char color;
			cin >> color;
			if (y1 > y2){
				swap(y1, y2);
			}
			for (int i = y1; i <= y2; i++){
				board[i][x] = color;
			}
		}
		//OK
		else if (wtd == 'H'){
			int x1, x2, y;
			cin >> x1 >> x2 >> y;
			if (x1 > x2) swap(x1, x2);
			char color;
			cin >> color;
			for (int i = x1; i <= x2; i++){
				board[y][i] = color;
			}
		}
		//OK
		else if (wtd == 'K'){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			char color;
			cin >> color;
			for (int y = y1; y <= y2; y++){
				for (int x = x1; x <= x2; x++){
					board[y][x] = color;
				}
			}
		}
		else if (wtd == 'F'){
			int x, y;
			cin >> x >> y;
			char color;
			cin >> color;
			fill_color(x, y, board[y][x], color);
		}
		else if (wtd == 'S'){
			string s;
			getline(cin, s);
			cout << s.erase(0, 1) << endl;
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					printf("%c", board[i][j]);
				}
				printf("\n");
			}
		}
		else{
			continue;
		}
	}
}
