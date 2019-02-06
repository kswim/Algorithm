#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int nums[100001];
int results[200001];

int main(){

	int N;
	int input;
	int i;
	stack<int> stacks;

	scanf("%d", &N);

	for(i=0; i<N; i++){
		scanf("%d", &nums[i]);
	}

	int curr, target, idx=0;
	curr = 1;
	target = 0; 
	stacks.push(curr);
	results[idx++] = 0;

	while(target < N){

		if(nums[target] > curr){ //원하는 수열보다 push할 값이 작을 경우 계속 push
			curr++;
			stacks.push(curr);
			results[idx++] = 0;
		}else if(nums[target] == stacks.top()){ //원하는 수열이 이미 push된 값인 경우 pop
			target++;
			stacks.pop();
			results[idx++] = 1;
		}else{
			printf("NO\n");
			return 0;
		}
		
	}

	for(i=0; i<idx; i++){
		if(results[i] == 0)
			printf("+\n");
		else
			printf("-\n");
	}

	return 0;
}