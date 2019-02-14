#include<iostream>

using namespace std;

int num[1001];
int up[1001];
int down[1001];

int main(){

	int N;
	int result=0;

	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
	}

	for(int i=0; i<N; i++){
		up[i] = 1; 
		for(int j=i-1; j>=0; j--){
			if( num[i] > num[j] && up[i] < up[j]+1){
				up[i] = up[j]+1;
			}
		}
	}


	for(int i=N-1; i>=0; i--){
		down[i] = 1; 
		for(int j=i+1; j<N; j++){
			if( num[i] > num[j] && down[i] < down[j]+1){
				down[i] = down[j]+1;
			}
		}
	}
	
	for(int i=0; i<N; i++){
		if(result < up[i]+down[i]-1)
			result = up[i]+down[i]-1;
	}

	printf("%d\n", result);

	return 0; 
}