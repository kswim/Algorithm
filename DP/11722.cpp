#include<iostream>

using namespace std;

int num[1001];
int dp[1001];

int main(){

	int N;
	int result=0;

	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
	}

	for(int i=0; i<N; i++){
		dp[i] = 1; 
		for(int j=i-1; j>=0; j--){
			if( num[i] < num[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
			}
		}
		if(dp[i] > result)
			result = dp[i];
	}

	printf("%d\n", result);

	return 0; 
}