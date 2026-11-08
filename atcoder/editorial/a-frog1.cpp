#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 7;

vector<int> heights;
vector<int> dist;


int main() {
    int n;
    cin >> n;

    heights.reserve(n);
    dist.resize(n, INF);

    int h;
    for (int i = 0; i < n; i++) {
        cin >> h;
        heights.push_back(h);
    }

    dist[0] = 0;
    for(int i = 0; i < n-1; i++){
        dist[i+1] = min(dist[i+1], dist[i] + abs(heights[i]-heights[i+1]));
        if (i < n-2) {
            dist[i+2] = min(dist[i+2], dist[i] + abs(heights[i]-heights[i+2]));
        }
    }

    cout << dist[n-1];
}
