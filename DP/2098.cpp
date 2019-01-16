#include<iostream>

using namespace std;

int N;
int W[17][17];
int dp[16][1<<16];

int TSP(int curr, int visited){ //현재 몇번 째 마을에 위치하는지, 어느 마을을 방문하고 왔는지
	int result;
	int ret = dp[curr][visited];

	if(ret != 0) //이미 구한 적 있다면
		return ret;

	if(visited == (1<<N)-1){ //모든 마을 방문했을 때
		if(W[curr][0] != 0){ //0번 마을로 갈 수 있을 때
			return W[curr][0];
		}
		return 1000000000; //불가능 하도록 매우 큰 수를 return
	}

	ret = 1000000000;

	for(int i=0; i<N; i++){
		if((visited & 1<<i) || (W[curr][i] == 0)) //i번째 visited 를 확인하기 위한 bit 연산
			continue;	
		result = TSP(i ,(visited | 1<<i))+W[curr][i];
		if(result < ret)
			ret = result;
	}
	dp[curr][visited] = ret;

	return ret;

}
int main(){

	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &W[i][j]);
		}
	}

	printf("%d\n", TSP(0, 1));

	return 0;
}