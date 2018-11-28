#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	long long n, k; 
	long long input, low, high, mid, ans;
	int cnt;
	vector<long long> lan;

	scanf("%lld %lld", &k, &n);
	
	for(int i=0; i<k; i++){
		scanf("%lld", &input);
		lan.push_back(input);
	}

	sort(lan.begin(), lan.end());

	low = 1;
	high = lan[lan.size()-1];
	ans = high;

	while(low <= high){
		mid = (low + high)/2;

		cnt=0;
		for(int i=0; i<lan.size(); i++){
			cnt += (lan[i]/mid); 
		}

		if(cnt >= n){
			low = mid+1; 
			ans = mid;
		}
		else 
			high = mid-1;
	}

	printf("%lld", ans);

	return 0;
}