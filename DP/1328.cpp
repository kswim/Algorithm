#include<iostream>

using namespace std;

long long dp[101][101][101];

int main(){

	int N, L, R;

	scanf("%d %d %d", &N, &L, &R);

	dp[1][1][1] = 1;

	for(int i=2; i<=N; i++){
		for(int j=1; j<=L; j++){
			for(int k=1; k<=R; k++){
				dp[i][j][k] = dp[i-1][j][k]*(i-2) + dp[i-1][j-1][k] + dp[i-1][j][k-1];
				dp[i][j][k] %= 1000000007;
			}
		}
	}

	printf("%lld\n", dp[N][L][R]);
	return 0;
}