#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

char input[1000001];
int include[26];

int main() {

	vector<pair<int, int>> result;

	scanf("%s", input);

	for(int i=0; i<=1000000;i++){
		if(input[i] == '\0')
			break;
		if(input[i]-'A' >= 0 && input[i]-'A' < 26){
			include[input[i]-'A']++;
		}
		else if(input[i]-'a' >= 0 && input[i]-'a' < 26){
			include[input[i]-'a']++;
		}
	}

	for(int i=0; i<26; i++){
		result.push_back(make_pair(include[i], i));
	}

	sort(result.begin(), result.end(), greater<pair<int, int>>());

	if(result[0].first == result[1].first){
		printf("?\n");
	}
	else{
		printf("%c\n", result[0].second+'A');
	}

    return 0;
}