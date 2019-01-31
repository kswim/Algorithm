#include<iostream>

using namespace std;

int num[1001];
int dp[1001];

int main(){

	int N, maxVal=0;
	int i, j, k;
	
	scanf("%d", &N);

	for(i=0; i<N; i++){
		scanf("%d", &num[i]);

		k= dp[i]; 
		for(j=i-1; j>=0; j--){
			if( (num[i] > num[j]) && (dp[j] > k))
				k = dp[j];
		}
		dp[i] = k+num[i];

		if(dp[i] > maxVal)
			maxVal = dp[i];
	}

	printf("%d\n",maxVal);

	return 0;
}