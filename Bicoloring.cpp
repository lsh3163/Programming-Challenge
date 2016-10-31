#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int T;
vector<vector<int> > graph;
int n, e;
int color[20001];
bool bfs(int src){

	queue<int> q;
	q.push(src);
	color[src] = 1;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		for (int next : graph[now]){
			if (color[next] == 0){
				color[next] = -color[now];
				q.push(next);
			}
			else{
				if (color[next] == color[now]){
					return false;
				}
			}
		}
	}
	return true;
}
int main(){
	while (true){
		graph.clear();
		cin >> n;
		if (n == 0){
			break;
		}
		cin >> e;
		graph.resize(n);
		while (e--){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(color, 0, sizeof(color));
		bool answer = true;
		for (int i = 0; i < n; i++){
			if (color[i] == 0){
				answer &= bfs(i);
			}
		}
		if (answer){
			printf("BICOLORABLE.\n");
		}
		else{
			printf("NOT BICOLORABLE.\n");
		}
	}
}
