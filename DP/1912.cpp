#include<iostream>

using namespace std; 

int num[100001];
int dp[100001];

int main(){

	int n; 
	int result;

	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
	}

	dp[0] = num[0]; 
	result = dp[0];

	for(int i=1; i<n; i++){
		if(num[i] < dp[i-1] + num[i])
			dp[i] = dp[i-1] + num[i];
		else
			dp[i] = num[i];

		if(result < dp[i])
			result = dp[i];
	}

	printf("%d\n", result);

	return 0;
}