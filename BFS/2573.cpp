#include<iostream>
#include<queue>

using namespace std;

int map[301][301];
int visited[301][301];
int N, M;

typedef struct node{
	int x;
	int y;
	int val;
};

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

queue<node> bingsan;

void ice();
void init();
int BFS(int x, int y);

int main(){

	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] != 0){
				node tmp={i, j, map[i][j]};
				bingsan.push(tmp);
			}
		}
	}

	int success=0, result=0; 

	while(!success){
		ice();
		result++;
		init();

		if(bingsan.size() != BFS(bingsan.front().x, bingsan.front().y)){
			success = 1;
		}
		if(success == 1 && bingsan.size() == 0)
			result = 0;
	}

	printf("%d\n", result);

	return 0;
}
void ice(){
	int cnt;
	node front;
	queue<node> removeNode;

	int size = bingsan.size();

	for(int i=0; i<size; i++){
		front = bingsan.front();
		bingsan.pop();
		cnt =0;
		
		for(int j=0; j<4; j++){
			if(front.x+dx[j] < 0 ||front.x+dx[j] >= N 
				|| front.y+dy[j] < 0 ||front.y+dy[j] >= M )
				continue;
			if(map[front.x+dx[j]][front.y+dy[j]] == 0)
				cnt++;
		}
		
		if(front.val-cnt > 0){
			node tmp={front.x, front.y, front.val-cnt};
			bingsan.push(tmp);
			removeNode.push(tmp);
		}
		else{
			node tmp={front.x, front.y, 0};
			removeNode.push(tmp);
		}
	}

	node tmp;
	while(!removeNode.empty()){
		tmp = removeNode.front();
		removeNode.pop();
		map[tmp.x][tmp.y] = tmp.val;
	}

}
int BFS(int x, int y){
	queue<pair<int, int>> q;
	pair<int, int> curr;
	int cnt=0;

	visited[x][y] = 1;
	q.push(make_pair(x, y));

	while(!q.empty()){
		curr = q.front();
		q.pop();
		x = curr.first;
		y = curr.second;
		
		cnt++; //탐색한 node의 개수

		for(int i=0; i<4; i++){
			if(x+dx[i] < 0 ||x+dx[i] >= N || y+dy[i] < 0 ||y+dy[i] >= M 
				|| visited[x+dx[i]][y+dy[i]] != 0 || map[x+dx[i]][y+dy[i]] == 0)
				continue;
			visited[x+dx[i]][y+dy[i]]=1;
			q.push(make_pair(x+dx[i], y+dy[i]));		
		}
	}

	return cnt;
}
void init(){

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			visited[i][j] = 0;
		}
	}
}