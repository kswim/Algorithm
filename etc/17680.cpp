#include <string>
#include <vector>
#include<algorithm>

using namespace std;
using std::transform;

vector<string> cache;
int use[31];

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cSize = 0, found = 0, mincnt;
    string target;
    
    if(cacheSize == 0)
        answer = cities.size()*5;
    else{
        for(int i=0; i<cities.size(); i++){
           
            transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
            target = cities[i];
            mincnt = found = 0;
         
            for(int j=0; j<cache.size(); j++){
                if(cache[j] == target){
                    found = 1;
                    use[j] = i+1;
                    break;
                }
                if(use[j] < use[mincnt])
                    mincnt=j;
            }    

            if(found == 1){ //찾았을 경우
                answer++;
            }
            else{ //cache에 없는 경우
                if(cache.size() < cacheSize){
                    cache.push_back(target);
                    use[cache.size()-1] = i+1;
                }
                else{
                    cache[mincnt] = target;
                    use[mincnt] = i+1; //사용했을 때
                }
                answer += 5;
            }
        }
    }
    
    return answer;
}