#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> adj;

int visited[101]; 
int N;
int BFS(int start);
void init();

int main(){

	int M, result, min, ans;
	int u, v;

	scanf("%d %d", &N, &M);
	
	adj.resize(N+1);

	for(int i=0; i<M; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	min = 100, ans = 0;

	for(int i=1; i<=N; i++){
		init();	
		result = BFS(i);
		if(result < min){
			min = result;
			ans = i;
		}
	}

	printf("%d\n", ans); 

	return 0;
}
void init(){
	for(int i=0; i<=N; i++)
		visited[i] = 0;
}
int BFS(int start){
	queue<int> q;
	int step=0, curr, size;

	q.push(start); 

	while(!q.empty()){
		size = q.size();

		for(int j=0; j<size; j++){
			curr = q.front();
			q.pop();

			for(int i=0; i<adj[curr].size(); i++){
				if(visited[adj[curr][i]] == 0){
					visited[adj[curr][i]] = step+1; 
					q.push(adj[curr][i]);
				}
			}
		}
		step++;
	}

	step = 0;

	for(int i=1; i<=N; i++){
		if(i == start)
			continue;
		step += visited[i];
	}
	
	return step;
}