#include<iostream>

using namespace std;

int N;
double percent[4]; //순서 : 동, 서, 남, 북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int visited[29][29];
double total;

void backtracking(pair<int, int> now, int curr, double result){

	int nextx, nexty;

	if(curr == N+1){
		total += result;
		return ;
	}

	visited[now.first][now.second] = 1; //방문

	for(int i=0; i<4; i++){
		nextx = now.first+dx[i];
		nexty = now.second+dy[i];
		
		if(visited[nextx][nexty] == 0){ //방문한 적 없다면
			backtracking(make_pair(nextx, nexty), curr+1, result*percent[i]);
		}
	}

	visited[now.first][now.second] = 0; //방문하지 않은 것처럼 초기화

}
int main(){

	scanf("%d", &N);

	for(int i=0; i<4; i++){
		scanf("%lf", &percent[i]);
		percent[i] /= 100.0;
	}

	backtracking(make_pair(14, 14), 1, 1.0);

	printf("%.10lf\n", total);
	
	return 0;
}