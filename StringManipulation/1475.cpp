#include <iostream>

using namespace std;

int check[10];
char input[1000001];

int main() {

	scanf("%s", input);

	for(int i=0; i<1000001; i++){
		check[input[i]-'0']++;
	}

	check[6] += check[9];
	check[9] = 0;

	if(check[6]%2 == 0)
		check[6] /= 2;
	else{
		check[6] /= 2;
		check[6]++;
	}

	int result=0;

	for(int i=0; i<9; i++){
		if(result < check[i])
			result = check[i];
	}

	printf("%d\n", result);

    return 0;
}