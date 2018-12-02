#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<algorithm>

using namespace std;

int cost[501][501];
int dp[501][501];

int main(){

    int N;
    
    scanf("%d", &N);
  
    for(int i=1; i<=N ;i++){
        for(int j=1; j<=i ;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    
    dp[1][1] = cost[1][1];
    
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
			if(j == 1){
				dp[i][j] = dp[i-1][j] + cost[i][j];
			}
			else if(i == j){
				dp[i][j] = dp[i-1][j-1] + cost[i][j];
			}
			else{
				dp[i][j]= max(dp[i-1][j-1],dp[i-1][j]) + cost[i][j];
			}
		}
    }
   
	int result = -1;

	for(int i=1; i<=N; i++){
		if(result < dp[N][i])
			result = dp[N][i];
	}

	printf("%d\n",result);

    return 0;
}