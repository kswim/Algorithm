#include<iostream>
#include<string>

using namespace std;

int LCS[1001][1001];

int main(){

	string str1, str2;
	int i, j;

	cin>>str1;
	cin>>str2;

	for(i=1; i<=str1.size(); i++){
		for(j=1; j<=str2.size() ; j++){
			if(str1[i-1] == str2[j-1]){
				LCS[i][j] = LCS[i-1][j-1]+1;
			}else{
				if(LCS[i-1][j] < LCS[i][j-1])
					LCS[i][j] = LCS[i][j-1];
				else
					LCS[i][j] = LCS[i-1][j];
			}
		}
	}
	
	printf("%d\n", LCS[i-1][j-1]);

	return 0;
}