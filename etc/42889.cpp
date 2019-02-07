#include <string>
#include <queue>
#include <vector>

using namespace std;

int cnt[502];

struct cmp{
    bool operator()(pair<float, int> a, pair<float, int> b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;   
    }
};
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
    float total;
    
    for(int i=0; i<stages.size(); i++){
        cnt[stages[i]]++; //해당 스테이지에 도달해있는 카운트를 증가시킴
    }
    
    total = cnt[N+1]; //모든 스테이지를 다 통과한 사용자의 수
    
    for(int i=N; i>=1; i--){
        total += cnt[i];
        if(total == 0)
            pq.push(make_pair(0,i));
        else
            pq.push(make_pair((float)cnt[i]/total,i));
    }    
    
    while(!pq.empty()){
        answer.push_back(pq.top().second);
        pq.pop();
    }
    
    return answer;
}
