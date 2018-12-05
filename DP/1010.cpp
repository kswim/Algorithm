#include<iostream>

int dp[31][31];

int main(){
	int n, m; 
	int t;
	long long result;
	scanf("%d", &t);

	for(int i=1; i<=30; i++)
		dp[i][1] = i;
	
	for(int a=0; a<t; a++){
		scanf("%d %d", &n, &m);
		for(int i=2; i<=m; i++){
			for(int j=2; j<=n; j++){
				dp[i][j] = dp[i][j-1]*(i-j+1)/(j);
			}
	}
		printf("%d\n", dp[m][n]);
	}

	return 0;
}