#include<iostream>
#include<string>
#include<algorithm>

using namespace std; 
int cost[1001][3];
int dp[1001][3];

int main(){
	int N, result;

	scanf("%d", &N);
	
	for(int i=1; i<=N; i++){
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	//i번째 집을 R(0), G(1), b(2)로 색칠 했을 때의 비용을 dp[i][0~2]에 저장
	for(int i=2; i<=N; i++){
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}

	result = min(dp[N][0], dp[N][1]);
	result = min(result, dp[N][2]);
	
	printf("%d", result);

	return 0;
}