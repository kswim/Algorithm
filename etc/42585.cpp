#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    
    for(int i=0; i<arrangement.size(); i++)
        if(arrangement[i] == '(' && i+1< arrangement.size() 
           && arrangement[i+1] == ')' ){ //레이저인 경우
            i++;
            answer += s.size();
        }
        else if(arrangement[i] == '(' && i+1< arrangement.size() 
           && arrangement[i+1] != ')' ){ //쇠막대기 시작
            s.push('(');
        }
        else if(arrangement[i] == ')'){ //쇠막대기 끝
            s.pop();
            answer++;
        }
    
    return answer;
}