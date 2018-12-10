#include<cstdio>

using namespace std;

int candy[1001][1001];
int dp[1001][1001];

int max(int a, int b, int c);

int main(){

	int N, M;
	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++){
		for(int j=0;j<M; j++)
			scanf("%d", &candy[i][j]);
	}

	dp[0][0] = candy[0][0];

	for(int i=1; i<N; i++){
		dp[i][0] = dp[i-1][0] + candy[i][0];
	}
	for(int i=1; i<M; i++){
		dp[0][i] = dp[0][i-1] + candy[0][i];
	}

	for(int i=1; i<N; i++){
		for(int j=1; j<M; j++)
			dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+candy[i][j];
	}

	printf("%d\n", dp[N-1][M-1]);
	
	return 0;
}
int max(int a, int b, int c){

	if(a >= b && a >= c){
			return a;
	}
	else if(b >= a && b >= c){
		return b;
	}
	else{
		return c;
	}
}