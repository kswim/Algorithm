#include <string>

using namespace std;

int num[3];
int bonus[3];

int solution(string dartResult) {
    int answer = 0;
    int numidx=0;
    
    for(int i=0; i<3; i++)
        bonus[i] = 1;
    
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i]-'0' >=0 && dartResult[i]-'0' <= 9){
           if(num[numidx] == 0)
                num[numidx] = dartResult[i]-'0';
            else
                 num[numidx] = 10;
        }
        else if(dartResult[i] == 'S'){
            numidx++;
        }
        else if(dartResult[i] == 'D'){
            num[numidx] *= num[numidx];
            numidx++;
        }
        else if(dartResult[i] == 'T'){
            num[numidx] = num[numidx]*num[numidx]*num[numidx];
            numidx++;
        }
        else if(dartResult[i] == '#'){
             bonus[numidx-1] *= -1;
        }
        else if(dartResult[i] == '*'){
             bonus[numidx-1] *= 2;
             bonus[numidx-2] *= 2;
        }
    }
    
    for(int i=0; i<3; i++){
        answer += num[i]*bonus[i];
    }
    
    return answer;
}