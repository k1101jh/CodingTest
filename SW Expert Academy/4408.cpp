#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int test_case=1; test_case <= T; test_case++) {
        int N;
        cin >> N;

        int from, to;
        vector<pair<int, int>> rooms(N, {0, 0});
        // vector<int> corridor(N, 0);

        for(int i=0; i < N; i++) {
            cin >> from >> to;

            // 0~200 사이 값으로 정규화
            // 짝수방과 홀수방은 서로 마주보고 있음
            // 1번 방 <-> 2번 방
            // ==> 0 <-> 0 으로 표기
            from = (from + 1) >> 1;
            to = (to + 1) >> 1;

            if(to < from) {
                swap(from, to);
            }

            rooms[i].first = from;
            rooms[i].second = to;
        }

        sort(rooms.begin(), rooms.end());

        // 맨 앞 방부터 학생이 나오고
        // 현재 복도에 있는 최대 학생 수 카운트
        priority_queue<int, vector<int>, greater<int>> pq;
        int cur_num = 0;
        int max_num = 0;
        for(auto& [from, to] : rooms) {
            cur_num++;

            // 그동안 들어간 학생이 있나?
            while(!pq.empty() && from > pq.top()) {
                pq.pop();
                cur_num--;
            }
            
            // 최대값 갱신
            max_num = max(max_num, cur_num);

            pq.push(to);
        }


        cout << "#" << test_case << ' ' << max_num << '\n';
    }
}