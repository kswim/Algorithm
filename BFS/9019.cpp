#include<iostream>
#include<queue>

using namespace std; 

int check[10000];
int dir[10000];
int D(int num);
int S(int num);
int L(int num);
int R(int num);
void BFS(int A, int B);

int main(){
	int T, a, b;

	scanf("%d", &T);

	for(int i=0; i<T; i++){
		scanf("%d %d", &a, &b);
		BFS(a, b);
	}
}
void BFS(int A, int B){
	queue<int> nums;
	queue<int> stack;
	vector<int> ans;
	int curr, size, result = A;

	nums.push(A);
	check[A] = 5;
	stack.push(A);

	while(!nums.empty() && result != B){
		size = nums.size(); 

		for(int i=0; i<size; i++){
			curr = nums.front(); 
			nums.pop();
			stack.push(curr);

			for(int j=1; j<=4; j++){
				if(j== 1){
					result = D(curr);
				}
				else if(j==2){
					result = S(curr);
				}
				else if(j==3){
					result = L(curr);
				}
				else
					result = R(curr);

				if(check[result] == 0 ){
					if(curr == 0)
						check[result] = 10000;
					else
						check[result] = curr;
					dir[result] = j;
					nums.push(result);
				}
				if(result == B)
					break;

			}

			if(result == B){
				break;
			}
		}
	}
	
	while(result != A){
		ans.push_back(dir[result]);

		result = check[result];
		if(result == 10000)
			result = 0;
	}
	
	for(int i=ans.size()-1; i >= 0 ; i--){
		if(ans[i] == 1)
			printf("D");
		else if(ans[i] == 2)
			printf("S");
		else if(ans[i] == 3)
			printf("L");
		else
			printf("R");
	
	}

	printf("\n");

	while(!nums.empty()){
		curr = nums.front(); 
		nums.pop();
		check[curr] =0; 
		dir[curr]=0; 
 	}
	
	while(!stack.empty()){
		curr = stack.front(); 
		stack.pop();
		check[curr] =0; 
		dir[curr]=0; 
 	}
	
}
int D(int num){
	return (2*num)%10000;
}
int S(int num){
	if(num == 0)
		return 9999;
	return num-1;
}

int L(int num){
	int result=0;
	int mul[4] = {1,1000, 100, 10};
	int j=0;

	for(int i=1000; i > 0 ; i /= 10){
		result += num/i * mul[j++];
		num = num%i;
	}
	return result;
}
int R(int num){
	int result=0;
	int mul[4] = {100, 10, 1, 1000};
	int j=0;

	for(int i=1000; i > 0 ; i /= 10){
		result += num/i * mul[j++];
		num = num%i;
	}
	return result;
}