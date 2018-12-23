#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int i=1, j=0, num;
    
    while(answer.size() < t){
        vector<int> result;
        num = j++;
        
        if(num == 0)
            result.push_back(0);
        
        while(num > 0){
            result.push_back(num%n);
            num /= n;
        }
        
        for(int k=result.size()-1; k >=0 && answer.size() < t; k--){
            if(i == m*answer.size() + p){
                if(result[k] >= 10)
                    answer += (char)(result[k]-10 + 'A');
                else
                    answer += (char)(result[k]+'0');
            }
            i++;
        }
    }

    return answer;
}