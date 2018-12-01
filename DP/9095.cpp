#include<iostream>

using namespace std; 
int dp[12];

int main(){

	int t, N;
	dp[1] = 1; 
	dp[2] = 2; 
	dp[3] = 4;
	 
	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf("%d", &N);
		for(int j=4; j<=N; j++){
			dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
		}
		printf("%d\n", dp[N]);
	}

	return 0;
}