#include<iostream>
#include<vector>

using namespace std;

int N;
int found=0;

char number[11][11];
int sum[11][11];
int result[11];

int promising(int curr){
	int success = 1;
	int sum=0;
	
	if(found)
		return 0;

	for(int i=curr, j=0; i>=0; i--, j++){
		sum += result[i];
		if( (sum == 0 && number[i][j] == '0')
			|| (sum > 0 && number[i][j] == '+')
			|| (sum < 0 && number[i][j] == '-'))
			continue;
		else{
			success=0;
			break;
		}
	}

	return success;
}
void backtracking(int curr){ //수열의 curr번째 구하기
	
	if(curr == N){
		for(int i=0; i<N; i++)
			printf("%d ", result[i]);
		found = 1;
		return ;
	}
	else if(found)
		return ;

	if(number[curr][0] == '-'){ //음수일 경우
		for(int i=-1; i > -11; i--){
			result[curr] = i;
			if(promising(curr)){
				backtracking(curr+1);
			}
			result[curr] = 0; //초기화
		} 
	}	
	else if(number[curr][0] == '0'){ //0일 경우
		result[curr] = 0;
		if(promising(curr)){
			backtracking(curr+1);
		}
	}
	else{ //양수일 경우
		for(int i=1; i<=10; i++){
			result[curr] = i;
			if(promising(curr)){
				backtracking(curr+1);
			}
			result[curr] = 0; //초기화
		}
	}

}
int main(){

	char input;

	scanf("%d\n", &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<(N-i); j++)
			scanf("%1c", &number[i][j]);
	}

	backtracking(0);

	return 0;
}