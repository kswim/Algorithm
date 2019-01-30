#include<iostream>

using namespace std;

int dp[31][8];

int main(){

	int N;
	scanf("%d", &N);

	if(N%2 != 0)
		printf("0\n");
	else{
		dp[1][6] = dp[1][3] = dp[1][0] = 1;

		for(int i=2; i<=N; i++){
			dp[i][0] = dp[i-1][7];
			dp[i][1] = dp[i-1][6];
			dp[i][3] = dp[i-1][7]+dp[i-1][4];
			dp[i][4] = dp[i-1][3];
			dp[i][6] = dp[i-1][7]+dp[i-1][1];
			dp[i][7] = dp[i-1][6]+dp[i-1][3]+dp[i-1][0];
		}

		printf("%d\n", dp[N][7]);
	}
	return 0;
}