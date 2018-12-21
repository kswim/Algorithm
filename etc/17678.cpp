#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> times;
    int hour, minute;
    
    for(int i=0; i<timetable.size(); i++){
        hour = (timetable[i][0] - '0')*10 + timetable[i][1]-'0';
        minute = (timetable[i][3]-'0')*10 + timetable[i][4]-'0';
        times.push(hour*60 + minute);
    }
    
    int start, cnt = 0, result, last;
    start = 9*60; //09:00 부터 처음 출발
    
    for(int i=0; i < n-1; i++){
        start = 9*60 + i*t;
        cnt = 0;
        
        while(!times.empty() && cnt < m ){
            if(times.top() <= start){ //지금 셔틀을 탈 수 있다면
                times.pop();
                cnt++;
            }
            else
                break;
        }
    }
  
    cnt = 0;
    start = 9*60 + t*(n-1); 
    while(!times.empty() && cnt < m-1 ){
        if(times.top() <= start){
            times.pop();
            cnt++;
        }
        else
            break;
    }
         
    if(times.empty() || times.top() > start ){
        result = start;
    }
    else{
        result = times.top()-1;
    }

    hour = result/60;
    minute = result%60;
             
    answer += hour/10 + '0';     
    answer += hour%10 + '0';
    answer += ':';
    answer += minute/10 + '0';      
    answer += minute%10 + '0';
    
    return answer;
}