#include<iostream>

using namespace std;

long long dp[1001][1001];

int main(){

	int n, k;
	int i, j;

	scanf("%d %d", &n, &k);
	
	for(int i=0; i<=n; i++){
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for(i=2; i<=n; i++){
		for(int j=1; j<=k; j++)
			dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%10007;
	}

	printf("%d\n", dp[n][k]);

	return 0;

}