#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

struct comp{
	bool operator()(string a, string b){
		if(a.length() == b.length())
			return a < b;
		return a.length() < b.length();
	}
};

int main(){

	int N;
	string temp;
	set<string, comp> check;

	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		cin>>temp; //scanf로 string을 입력받을 수 없음!
		check.insert(temp);
	}
	
	set<string, comp>::iterator iter;

	for(iter=check.begin(); iter != check.end(); iter++){
		printf("%s\n", (*iter).c_str()); //printf로 string을 출력할 수 없음!
	}

	return 0;
}