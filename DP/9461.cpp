#include<iostream>

using namespace std; 

long long dp[101];

int main(){

	int T, N;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	scanf("%d", &T);

	for(int k=0; k<T; k++){
		scanf("%d", &N);
		for(int i=6, j=1; i<=N; i++, j++){
			dp[i] = dp[i-1]+dp[j];
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}