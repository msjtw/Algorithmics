#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

vector<pii> polygon;

int main (int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <n; i++){
        int a, b;
        cin >> a >> b;
        polygon.push_back({a, b});
    }
    for(int i =0; i < m; i++){
        pii p;
        cin >> p.first >> p.second;

        int count = 0;
    }

    return 0;
}
