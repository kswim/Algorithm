#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

void check(pair<int, int> start, pair<int, int> end);
void DFS(int x, int y);

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int map[101][101];
int t;

int main(){
	int K;
	pair<int, int> start, end;
	vector<int> ans;

	scanf("%d %d %d", &N, &M, &K);
	
	for(int i=0; i<K; i++){
		scanf("%d %d %d %d",&start.second, &start.first, &end.second, &end.first);
		start.first = N - start.first;
		end.first = N - end.first;
		check(start, end);
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 0){
				t = 1;
				map[i][j] = 2;
				DFS(i, j);
				ans.push_back(t);
			}
		}
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());

	for(int i=0; i<ans.size(); i++){
		printf("%d ", ans[i]);
	}

	return 0;
}
void check(pair<int, int> start, pair<int, int> end){
	for(int i=end.first; i<start.first; i++){
		for(int j=start.second; j<end.second; j++){
			map[i][j] = 1;
		}
	}
}
void DFS(int x, int y){
	int nextx, nexty;

	for(int i=0; i<4; i++){
		nextx = x+dx[i];
		nexty = y+dy[i]; 

		if(nextx < 0 || nextx >= N || nexty < 0 || nexty >= M || map[nextx][nexty] != 0)
			continue;
		t++;
		map[nextx][nexty] = 2;
		DFS(nextx, nexty);		
	}
}