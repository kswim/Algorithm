#include<iostream>
#include<vector>
#include<stack>
#define max(x, y)  x > y ? x : y

using namespace std;

int D[1001];
int dp[1001];
int visited[1001];
stack<int> result;

void DP(vector<vector<int>> adj, int W){
	
	int curr;
	result.pop();
	curr = result.top();
	dp[curr] = D[curr]; //처음 시작하는 노드는 해당 건물 건설시간만 필요 

	while(!result.empty() && curr != W){
		curr = result.top();
		result.pop();

		if(curr == W)
			return ;
		for(int i=0; i<adj[curr].size(); i++){
			dp[adj[curr][i]] = max(dp[curr]+D[adj[curr][i]], dp[adj[curr][i]]);
		}
	}
}

void DFS(int curr, vector<vector<int>> adj, int W){
   visited[curr] = 1;

   for(int j=0; j<adj[curr].size(); j++){
      if(visited[adj[curr][j]] == 0){
         visited[adj[curr][j]] = 1;
         DFS(adj[curr][j], adj, W);
      }

   }
   result.push(curr);
}

int main(){

	int t;
	int u, v;
	int N, K, W;

	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf("%d %d", &N, &K);
		for(int j=0; j<=N; j++){
			visited[j] = 0;
			dp[j] = 0;
		}

		vector<vector<int>> adj;
		int input;
		adj.resize(N+1);

		for(int j=1; j<=N; j++){
			scanf("%d", &D[j]);
			adj[0].push_back(j); //모든 컴포넌트를 순회할 수 있도록 연결해주는 0번째 노드
		}

		for(int j=0; j<K; j++){
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}   
	  
		scanf("%d", &W);
     
		DFS(0, adj, W);
		DP(adj, W);
		
		printf("%d\n", dp[W]);
   }

   return 0;
}