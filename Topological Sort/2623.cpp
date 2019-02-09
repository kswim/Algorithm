#include<iostream>
#include<vector>

using namespace std;

int visited[1001];
int finish[1001];
int success;

vector<int> result;

void DFS(int curr, vector<vector<int>> adj){
	if(!success) return;

	visited[curr] = 1;
	
	for(int j=0; j<adj[curr].size(); j++){
		if(visited[adj[curr][j]] == 0){
			visited[adj[curr][j]] = 1;
			DFS(adj[curr][j], adj);
		}else if(!finish[adj[curr][j]]){
			success = 0;
			return ;
		}
	}
	finish[curr] = 1;
	result.push_back(curr);
}

int main(){

	int t;
	int u, v;
	int N, M;

	scanf("%d %d", &N, &M);
	
	vector<vector<int>> adj;
	int input;

	adj.resize(N+1);
	
	for(int i=1; i<=N; i++){
		adj[0].push_back(i);
	}

	for(int i=0; i<M; i++){
		scanf("%d", &input);

		scanf("%d", &u);
		for(int j=1; j<input; j++){
			scanf("%d", &v);
			adj[u].push_back(v);
			u = v;
		}
	}	

	success = 1;
	DFS(0, adj);
	
	if(success){
		for(int i=result.size()-2; i>=0; i--)
			printf("%d\n", result[i]);
	}else{
		printf("0\n");
	}
	return 0;
}