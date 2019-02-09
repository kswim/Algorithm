#include<iostream>
#include<queue>

using namespace std;

int map[501][501];
long long int dp[501][501];

typedef struct node{
	int num;
	int x;
	int y;
};
struct cmp{
	bool operator()(node a, node b){
		return a.num < b.num;
	}
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){

	int N, M;
	int i, j;
	priority_queue<node, vector<node>, cmp> pq;
	node input, curr;

	scanf("%d %d", &N, &M);

	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			if(i == 0 && j == 0)
				continue;
			input.num = map[i][j];
			input.x = i; input.y = j;
			pq.push(input);
		}
	}

	dp[0][0] = 1;

	while(!pq.empty()){
		curr = pq.top();
		i = curr.x;
		j = curr.y;
		pq.pop();
		
		for(int k=0; k<4; k++){
			if(map[i][j] < map[i+dx[k]][j+dy[k]])
				dp[i][j] += dp[i+dx[k]][j+dy[k]];
		}
		
	}

	printf("%lld\n", dp[N-1][M-1]);
	
	return 0;
}