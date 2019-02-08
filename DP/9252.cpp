#include<iostream>
#include<string>
#include<vector>

using namespace std;

int LCS[1001][1001];

int main(){
	vector<char> result;
	string str1, str2;
	int i, j;

	cin>>str1;
	cin>>str2;

	for(i=1; i<=str1.size(); i++){
		for(j=1; j<=str2.size() ; j++){
			if(str1[i-1] == str2[j-1]){
				LCS[i][j] = LCS[i-1][j-1]+1;
			}else{
				if(LCS[i-1][j] < LCS[i][j-1]){
					LCS[i][j] = LCS[i][j-1];
				}else{
					LCS[i][j] = LCS[i-1][j];
				}
			}
		}
	}
	
	printf("%d\n", LCS[i-1][j-1]);

	i = str1.size();
	j = str2.size();
	
	while(i>=1 && j>=1){
		if(LCS[i][j] == LCS[i-1][j]){
			i--;
		}else if(LCS[i][j] == LCS[i][j-1]){
			j--;
		}else{
			result.push_back(str1[i-1]);	
			i--; j--;
		}
	}

	for(i=result.size()-1; i>=0; i--)
		printf("%c", result[i]);

	return 0;
}