#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	
	int N, M, input;
	long long low, high, mid, sum;
	vector<int> times;

	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++){
		scanf("%d", &input);
		times.push_back(input);
	}

	sort(times.begin(), times.end());

	low = 1;
	high = (long long)times[times.size()-1]*(long long)M;

	while(low+1 < high){
		mid = (low+high)/2;

		sum = 0;
		for(int i=0; i<times.size(); i++){
			sum += mid/times[i];
		}

		if(sum >= M)
			high = mid;
		else
			low = mid;
	}
	
	printf("%lld", high);

	return 0;
}