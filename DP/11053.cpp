#include<iostream>

using namespace std;

int nums[1001];
int dp[1001];

int main(){

	int N; 
	
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d",&nums[i]);
	}

	for(int i=0; i<N; i++){
		dp[i] = 1;
		for(int j=i-1; j>=0; j--){
			if(nums[j] < nums[i] && dp[i] < dp[j]+1 ){
				dp[i] = dp[j]+1;
			}
		}
	}

	int result = dp[0];

	for(int i=1; i<N; i++){
		if(result < dp[i])
			result = dp[i];
	}

	printf("%d\n", result);
	return 0;
}