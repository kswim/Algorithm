#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct fname{
    string head;
    int num;
    int idx;
}fname;

bool comp(fname a, fname b){
    std::transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
    std::transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);
    
    if(a.head == b.head){
        return a.num < b. num;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fname> names;
    fname tmp;
    int result;
    
    for(int i=0; i<files.size(); i++){
        for(int j=0; j<files[i].size(); j++){
            if( files[i][j] >= '0' && files[i][j] <= '9' ){ //number가 시작한다면!
                tmp.head = files[i].substr(0, j);
        
                vector<int> nums;
                for(int k=j; k<files[i].size(); k++){
                    if( files[i][k] >= '0' && files[i][k] <= '9')
                        nums.push_back(files[i][k]-'0');
                    else
                        break;
                }
                
                result = 0;
             
                for(int k=nums.size()-1; k >= 0; k--){
                    result += nums[k] * pow(10, nums.size()-1-k);
                }
    
                tmp.num = result;
                tmp.idx = i;
                names.push_back(tmp);
                break;
           }
        }
    }
    
    stable_sort(names.begin(), names.end(), comp);
    
    for(int i=0; i<names.size(); i++){
        answer.push_back(files[names[i].idx]);
    }
      
    return answer;
}