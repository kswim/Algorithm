#include <iostream>

using namespace std;

char input[51][51];

int main() {

	int N;
	char curr;

	scanf("%d\n", &N);

	for(int i=0; i<N; i++){
		scanf("%s", input[i]);
	}

	if(N == 1){
		printf("%s", input[0]);
		return 0;
	}

	for(int i=0; i<51; i++){
		curr = input[0][i];

		if(curr == '\0')
			break;

		for(int j=1; j<N; j++){
			if(curr != input[j][i]){
				printf("?");
				break;
			}
			if(j == N-1)
				printf("%c", curr);
		}
	}	

    return 0;
}