#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tiii;

struct e_t {
    int a;
    int b;
    ll w;
};

const int MX = 1007;

vector<tiii> points;
vector<e_t> edges;

int link[MX]{};
int ssize[MX]{};

int find(int x) {
    while (link[x] != x) {
        x = link[x];
    }
    return x;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (ssize[a] < ssize[b])
        swap(a, b);
    ssize[a] += ssize[b];
    link[b] = a;
}

ll dist(tiii a, tiii b) {
    ll ax, ay, az;
    tie(ax, ay, az) = a;
    ll bx, by, bz;
    tie(bx, by, bz) = b;
    ll dx = ax - bx;
    ll dy = ay - by;
    ll dz = az - bz;

    ll diag1 = (dx * dx) + (dy * dy);
    ll diag2 = diag1 + (dz * dz);

    return diag2;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        points.push_back({a, b, c});
    }

    for (int i = 0; i < points.size(); i++) {
        for (int k = i + 1; k < points.size(); k++) {
            edges.push_back({i, k, dist(points[i], points[k])});
        }
    }

    sort(edges.begin(), edges.end(), [](e_t l, e_t r) { return l.w < r.w; });

    for (int i = 0; i < MX; i++) {
        ssize[i] = 1;
        link[i] = i;
    }

    ll last_ax, last_bx;
    for (int i = 0; i < edges.size(); i++) {
        e_t edge = edges[i];
        tiii pa = points[edge.a];
        tiii pb = points[edge.b];
        // cout << get<0>(pa) << " " << get<1>(pa) << " " << get<2>(pa) << "\t";
        // cout << get<0>(pb) << " " << get<2>(pb) << " " << get<2>(pb) << "\t"
        //      << edge.w << endl;
        if (!same(edge.a, edge.b)) {
            unite(edge.a, edge.b);
            last_ax = get<0>(points[edge.a]);
            last_bx = get<0>(points[edge.b]);
        }
    }

    cout << last_ax * last_bx;

    return 0;
}
