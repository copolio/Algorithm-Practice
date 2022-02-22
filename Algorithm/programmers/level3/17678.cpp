#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string minuteToString(int minute) {
    int hour = minute / 60;
    int min = minute % 60;
    char result[5];
    sprintf(result, "%02d:%02d", hour, min);
    return string(result);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < timetable.size(); i++) {
        string time = timetable[i];
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3,2));
        pq.push(hour*60 + min);
    }
    
    int curTime = 9 * 60;
    int nBus = 1;
    
    while (nBus <= n) {
        int nPassenger = 1;
        bool isFull = false;
        while (!pq.empty()) {
            int last = pq.top();
            if (last >  curTime) break;
            if (nPassenger == m) {
                answer = minuteToString(last - 1);
                pq.pop();
                isFull = true;
                break;
            }
            pq.pop();
            nPassenger++;
        }
        nBus++;
        if (!isFull) answer = minuteToString(curTime);
        curTime += t;
    }
    return answer;
}