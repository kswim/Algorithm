#include<iostream>
#include<vector>

using namespace std;

void init();
void DFS(int u, int v);

int map[51][51];
int N, M;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int main(){
	int t, Y;
	int u, v;

	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf("%d %d %d", &N, &M, &Y);
		init();
		vector<pair<int, int>> list;

		for(int j=0; j<Y; j++){
			scanf("%d %d", &u, &v);
			map[u][v]=1;
			list.push_back(make_pair(u, v));
		}
		int cnt=0;
		for(int j=0; j<list.size(); j++){
			u = list[j].first;
			v = list[j].second;
			if(map[u][v] != 0){
				cnt++;
				DFS(u, v);
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
void DFS(int u, int v){
	map[u][v] = 0;

	for(int i=0; i<4; i++){
		if(u+dx[i] < 0 || u+dx[i] >= N 
			|| v+dy[i] < 0 || v+dy[i] >= M || map[u+dx[i]][v+dy[i]] == 0)
			continue;
		DFS(u+dx[i], v+dy[i]);
	}

}
void init(){
	for(int i=0; i<N;i++){
		for(int j=0; j<M; j++)
			map[i][j] = 0;
	}
}