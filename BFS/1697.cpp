#include<iostream>
#include<queue>

using namespace std;

int visited[100001];
queue<long long> nums;

int main(){
	long long n, k;
	int found=0, step=0;
	long long curr;
	int size; 

	scanf("%lld %lld", &n, &k);

	if(n == k)
		found = 1;

	nums.push(n);
	visited[n]=1;

	while(!nums.empty() && !found){
		size = nums.size();

		for(int i=0; i<size; i++){
			curr = nums.front();
			nums.pop();

			if(curr+1 <= k && visited[curr+1] == 0){
				nums.push(curr+1);
				visited[curr+1]=1;
			}
			
			if(curr-1 >= 0 && visited[curr-1] == 0){
				nums.push(curr-1);
				visited[curr-1]=1;
			}

			if(curr*2 <= 100000 && visited[curr*2] == 0){
				nums.push(curr*2);
				visited[curr*2]=1;
			}

			if(visited[k] == 1){
				found = 1;
				break;
			}

		}
		step++;
	
	}

	printf("%d\n", step);

	return 0;
}