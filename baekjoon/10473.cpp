#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>
using namespace std;

const double SPEED = 5;
const double C_DIST = 50;
const double C_TIME = 2;
vector<double> times;
vector<pair<double, double>> cannons;
double start_X, start_Y, dest_X, dest_Y;
int n;

double GetTimes(const pair<double, double>& a, const pair<double, double>& b) {
    double dy = a.first - b.first;
    double dx = a.second - b.second;
    return sqrt(dy * dy + dx * dx) / SPEED;
}

double GetCannonTimes(const pair<double, double>& a, const pair<double, double>& b) {
    double dy = a.first - b.first;
    double dx = a.second - b.second;
    double dist = sqrt(dy * dy + dx * dx);
    return min(dist / SPEED, abs(dist - C_DIST) / SPEED + C_TIME);
}

void Dijkstra() {
    times.assign(n + 2, numeric_limits<double>::max());
    priority_queue<pair<double, int>> pq;
    pq.push({0, 0});
    times[0] = 0;

    while(!pq.empty()) {
        double dist = -pq.top().first;
        int cur_idx = pq.top().second;
        pq.pop();

        if(times[cur_idx] < dist) continue;

        if(cur_idx == n + 1) break;

        for(int i=1; i <= n + 1; i++) {
            if(cur_idx == i) continue;

            double time;
            if(cur_idx == 0 || cur_idx == n + 1) {
                time = GetTimes(cannons[cur_idx], cannons[i]);
            } else {
                time = GetCannonTimes(cannons[cur_idx], cannons[i]);
            }

            double next_time = dist + time;
            if(times[i] > next_time) {
                times[i] = next_time;
                pq.push({-next_time, i});
            }
        }
    }
    cout << fixed;
    cout.precision(9);
    cout << times[n + 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> start_X >> start_Y >> dest_X >> dest_Y;
    cin >> n;

    // 0번째 노드는 출발 노드
    // n + 1번째 노드는 목적지 노드
    cannons.assign(n + 2, {0.0, 0.0});

    double X, Y;
    cannons[0] = {start_Y, start_X};
    for(int i=1; i <= n; i++) {
        cin >> X >> Y;
        cannons[i] = {Y, X};
    }
    cannons[n + 1] = {dest_Y, dest_X};

    Dijkstra();
}