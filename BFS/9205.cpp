#include<iostream>
#include<vector>
#include<math.h>
#include<queue>

using namespace std;

int store[101][2];
int visited[101];

vector<vector<int>> adj;

int bfs(){
	
	int success = 0;
	queue<int> q;
	int curr;
	visited[0] = 1;
	q.push(0); //첫 시작은 상근이의 위치

	while(!q.empty()){
		curr = q.front();
		q.pop();

		if(curr == adj.size()-1){
			success = 1;
			break;
		}
	
		for(int i=0; i<adj[curr].size(); i++){
			if(visited[adj[curr][i]] == 0){
				visited[adj[curr][i]] = 1;
				q.push(adj[curr][i]);
			}
		}
	}

	return success;

}
void init(int N){
	for(int i=0; i<=N; i++){
		visited[i] = 0;
		store[i][0] = store[i][1] = 0;
	}
	adj.clear();
	adj.resize(N);
}

int main(){

	int t, N;
	int x, y;

	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf("%d", &N);
		init(N+2);
		
		for(int j=0; j<=N+1; j++)
			scanf("%d %d", &store[j][0], &store[j][1]);	

		for(int j=0; j<=N; j++){
			for(int k=j+1; k<=N+1; k++){
				float beer = abs(store[j][0]-store[k][0])/50.0 + abs(store[j][1]-store[k][1])/50.0;
				if(beer <= 20){
					adj[j].push_back(k);
					adj[k].push_back(j);
				}
			}
		}

		int result = bfs();
		if(result == 1)
			printf("happy\n");
		else
			printf("sad\n");
	}

	return 0;
}