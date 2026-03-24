#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> qll;

vector<pll> points;
vector<qll> edges;

int sign(ll a) {
    if (a > 0) {
        return 1;
    } else if (a == 0) {
        return 0;
    } else {
        return -1;
    }
}

ll cross(pll a, pll b, pll c) {
    pll va, vb;
    va.first = b.first - a.first;
    va.second = b.second - a.second;
    vb.first = c.first - b.first;
    vb.second = c.second - b.second;
    return (ll)va.first * vb.second - (ll)vb.first * va.second;
}

bool rect_inter(qll e1, qll e2) {
    pll a = e1.first;
    pll b = e1.second;
    pll c = e2.first;
    pll d = e2.second;

    pll p1 = {min(a.first, b.first), max(a.second, b.second)};
    pll p2 = {max(a.first, b.first), min(a.second, b.second)};
    pll p3 = {min(c.first, d.first), max(c.second, d.second)};
    pll p4 = {max(c.first, d.first), min(c.second, d.second)};

    // cout << p1.first << " " << p1.second << " ";
    // cout << p2.first << " " << p2.second << " | ";
    // cout << p3.first << " " << p3.second << " ";
    // cout << p4.first << " " << p4.second << " \n";

    if (p3.first > p2.first || p4.first < p1.first || p3.second < p2.second ||
        p4.second > p1.second)
        return false;
    return true;
}

int main(int argc, char *argv[]) {
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        ll a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    for (int i = 0; i < p - 1; i++) {
        edges.push_back({points[i], points[i + 1]});
    }
    edges.push_back({points[p - 1], points[0]});

    pll a_r, b_r, c_r, d_r;
    ll maxi = 0;
    for (int i = 0; i < p; i++) {
        for (int k = i + 1; k < p; k++) {
            pll a = points[i];
            pll b = points[k];
            pll c = {points[i].first, points[k].second};
            pll d = {points[k].first, points[i].second};

            qll e1 = {a, b};
            qll e2 = {b, c};
            qll e3 = {c, d};
            qll e4 = {d, a};
            bool ok = true;
            for (auto edge : edges) {
                pll a, b, c, d;
                tie(a, b) = edge;
                tie(c, d) = e1;
                if (rect_inter(e1, edge)) {
                    if (sign(cross(a, b, c)) * sign(cross(a, b, d)) < 0 &&
                        sign(cross(c, d, a)) * sign(cross(c, d, b)) < 0) {
                        ok = false;
                        break;
                    }
                }
                tie(c, d) = e2;
                if (rect_inter(e2, edge)) {
                    if (sign(cross(a, b, c)) * sign(cross(a, b, d)) < 0 &&
                        sign(cross(c, d, a)) * sign(cross(c, d, b)) < 0) {
                        ok = false;
                        break;
                    }
                }
                tie(c, d) = e3;
                if (rect_inter(e3, edge)) {
                    if (sign(cross(a, b, c)) * sign(cross(a, b, d)) < 0 &&
                        sign(cross(c, d, a)) * sign(cross(c, d, b)) < 0) {
                        ok = false;
                        break;
                    }
                }
                tie(c, d) = e4;
                if (rect_inter(e4, edge)) {
                    if (sign(cross(a, b, c)) * sign(cross(a, b, d)) < 0 &&
                        sign(cross(c, d, a)) * sign(cross(c, d, b)) < 0) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) {
                ll area = abs(a.first - b.first) * abs(a.second - b.second);
                if (area > maxi) {
                    maxi = area;
                    a_r = a;
                    b_r = b;
                    c_r = c;
                    d_r = d;
                }
            }
        }
    }

    cout << a_r.first << " " << a_r.second << " | " << b_r.first << " "
         << b_r.second << endl;
    cout << c_r.first << " " << c_r.second << " | " << d_r.first << " "
         << d_r.second << endl;
    cout << maxi;

    return 0;
}
