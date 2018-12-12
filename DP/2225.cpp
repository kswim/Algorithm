#include<iostream>

using namespace std;

long long dp[201][201];

int main(){

	int N, K; 

	scanf("%d %d", &N, &K);

	for(int i=0; i<=N; i++)
		dp[i][1] = 1;

	for(int i=0; i<=N; i++){
		for(int j=2; j<=K; j++){
			for(int k = i; k >= 0 ; k--){
				dp[i][j] += dp[i-k][j-1];
				dp[i][j] %= 1000000000;
			}
		}
	
	}
	printf("%lld\n", dp[N][K]);
	return 0;
}