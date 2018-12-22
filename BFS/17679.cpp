#include <string>
#include <vector>
#include <queue>

using namespace std;
void init(int m, int n);
int BFS(int x, int y, int m, int n);

int visited[31][31];
int map[31][31];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int idx[4] = {0, 0, 1, 1};
int idy[4] = {0, 1, 1, 0}; 

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            map[i][j] = board[i][j] - 'A'+1;
        }
    }
    
    int found;
    
    do{
        found = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && map[i][j] != 0){
                    found += BFS(i, j, m, n);
                }
            }
        }
        init(m, n);
        answer += found;
        
    }while(found != 0);
    
    return answer;
}
void init(int m, int n){
    queue<int> q;
    int i, j;
    int tmp;
    
    for(i=0; i<m; i++){
        for(j=n-1; j>=0; j--){
            visited[j][i] = -1;
            if(map[j][i] != -1) //없어진 곳이 아니라면
                q.push(map[j][i]);
        }
        
        j = n-1;
        
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            map[j][i] = tmp;
            visited[j][i] = 0;
            j--;
        }  
        while(j >= 0){
            map[j][i] = 0;
            visited[j][i] = -1;
            j--;
        }   
    } 
}
int BFS(int x, int y, int m, int n){
    
    queue<pair<int, int>> q;
    queue<pair<int, int>> del;
    pair<int, int> curr, tmp;
        
    visited[curr.first][curr.second] = 1; 
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        curr = q.front();
        q.pop();
        
        if(curr.first+1 < m && curr.second+1 < n ){
            if(map[curr.first][curr.second] == map[curr.first][curr.second+1] 
              && map[curr.first][curr.second] == map[curr.first+1][curr.second]
              && map[curr.first][curr.second] == map[curr.first+1][curr.second+1] ){
                del.push(make_pair(curr.first, curr.second));
            }
        }

        for(int i=0; i<4; i++){
            if(curr.first+dx[i] >= m || curr.first+dx[i] < 0 
               || curr.second+dy[i] >= n || curr.second+dy[i] < 0 
               || visited[curr.first+dx[i]][curr.second+dy[i]] != 0 
               || map[curr.first+dx[i]][curr.second+dy[i]] == 0 )
                continue;
            visited[curr.first+dx[i]][curr.second+dy[i]] = 1;
            q.push(make_pair(curr.first+dx[i], curr.second+dy[i]));
        }
    }
    
    if(del.empty())
        return 0;
    
    int cnt = 0;
    
    while(!del.empty()){
        curr = del.front();
        del.pop();

        for(int i=0; i<4; i++){
            if(map[curr.first+idx[i]][curr.second+idy[i]] == -1){
                continue;
            }
            cnt++;
            map[curr.first+idx[i]][curr.second+idy[i]] = -1;
            visited[curr.first+idx[i]][curr.second+idy[i]] = -1;
        }
    }
    
    return cnt;
}