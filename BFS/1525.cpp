#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main(){
	int idx[4] = {1, 3, -1, -3};
	int size, step=0, found = 0;
	int curr, tmp[9], start=0, sum, node[9];
	map<int, int> visited;
	queue<int> q;

	for(int i=0; i<9; i++){
		scanf("%1d", &tmp[i]);
		start = start*10 + tmp[i];
	}

	if(start == 123456780){
		printf("0");
		return 0;
	}

	q.push(start);

	while(!q.empty() && !found){

		size = q.size();
		
		for(int t =0; t<size && !found; t++){
			curr = q.front();
			q.pop();
			
			for(int i=8; i>=0; i--){
				tmp[i] = curr%10;
				curr /= 10;
				if(tmp[i] == 0){
					start = i;		
				}
			}

			for(int i=0; i<4; i++){
				if(start+idx[i] < 0 || start+idx[i] > 8 ||
					(start == 2 && i == 0) || (start == 3 && i == 2) || (start == 5 && i == 0) || (start == 6 && i == 2))
					continue; //범위를 넘어가거나 0부터 8번까지 자리를 둔다면 2번과 3번, 5번과 6번자리는 바꿀 수 없음
				
				for(int j=0; j<9; j++)
					node[j] = tmp[j];

				node[start] = node[start+idx[i]];
				node[start+idx[i]] = 0;
				sum =0;
				
				for(int j=0; j<9; j++){	
					sum = sum*10 + node[j];
				}

				if(sum == 123456780){
					found = 1; 
					break;
				}

				if(visited.find(sum) == visited.end()){
					visited[sum] = 1;
					q.push(sum);
				}
			}
		}

		step++;
	}
	
	if(!found)
		printf("-1\n");
	else 
		printf("%d\n", step);

	return 0;
}
