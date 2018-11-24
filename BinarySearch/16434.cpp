#include<cstdio>
#include<vector>

using namespace std;

typedef struct node{
	int type;
	long long a;
	long long h;
};

int main(){
	
	int N, power;
	long long t, a, h;
	node tmp; 
	vector<node> rooms;

	scanf("%d %d", &N, &power);

	for(int i=0; i<N; i++){
		scanf("%lld %lld %lld", &tmp.type, &tmp.a, &tmp.h);
		rooms.push_back(tmp);
	}

	long long low, high, mid, hp, curr_power, minus;
	int fail=0;
	low = 0;
	high = 1000000000000000000;


	while(low+1 < high){
		mid = (low+high)/2;
		curr_power = power;
		hp = mid;
		fail = 0;
	
		for(int i=0; i<rooms.size(); i++){
			
			if(rooms[i].type == 2){
				curr_power += rooms[i].a;
				
				if(hp + rooms[i].h < mid)
					hp += rooms[i].h;
				else
					hp = mid;
			}
			else{
				if(rooms[i].h%curr_power == 0){
					minus = (int)((rooms[i].h/curr_power)-1)*rooms[i].a;
				}
				else
					minus = (int)(rooms[i].h/curr_power)*rooms[i].a;

				if(minus >= hp){
					fail = 1;
					break;
				}
				else{
					hp -= minus;
				}
			}
		}

		if(!fail){
			high = mid;
		}
		else
			low = mid;
	
	}

	printf("%lld", high);
	
	return 0;

}