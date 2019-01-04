#include<iostream>

using namespace std;

int visited[26];
int map[21][21];

int R, C;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
int maxCnt;

void backtracking(int x, int y, int cnt){

	visited[map[x][y]] = 1;
	
	if(cnt > maxCnt)
		maxCnt = cnt;

	for(int i=0; i<4; i++){
		if(x+dx[i]<0 || x+dx[i]>=R || y+dy[i]<0 || y+dy[i]>=C)
			continue;
		if(visited[map[x+dx[i]][y+dy[i]]] == 0)
			backtracking(x+dx[i], y+dy[i], cnt+1);
	}

	visited[map[x][y]] = 0; //백트래킹이므로 돌아갈 때는 다시 방문하지 않은 것으로 바꿔주기!
}
int main(){

	char input;
	scanf("%d %d\n", &R, &C);

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%c", &input);
			map[i][j] = input-'A';
		}
		scanf("%c", &input);
	}

	backtracking(0, 0, 1);

	printf("%d\n", maxCnt);
	return 0;
	
}