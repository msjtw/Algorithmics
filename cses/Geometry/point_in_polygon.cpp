#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long int ll ;

vector<pii> polygon;

int sign(ll a){
    if (a > 0){
        return 1;
    }
    else if (a == 0){
        return 0;
    }
    else {
        return -1;
    }
}

int cross(pii a, pii b, pii c){
    pii va, vb;
    va.first = b.first-a.first;
    va.second = b.second-a.second;
    vb.first = c.first-b.first;
    vb.second = c.second-b.second;
    return sign((ll)va.first*vb.second - (ll)vb.first*va.second);
}

int inter(pii a, pii b, pii c, pii d){
    pii p1 = {min(a.first, b.first), max(a.second, b.second)};
    pii p2 = {max(a.first, b.first), min(a.second, b.second)};
    pii p3 = {min(c.first, d.first), max(c.second, d.second)};
    pii p4 = {max(c.first, d.first), min(c.second, d.second)};

    if (p3.first > p2.first || p4.first < p1.first || p3.second < p2.second || p4.second > p1.second)
        return 0;

    if (sign(cross(a,b,c)) * sign(cross(a,b,d)) <= 0 && sign(cross(c,d,a)) * sign(cross(c,d,b)) <= 0) {
        return 1;
    }

    return 0;
}

bool point_on_line(pii a, pii b, pii p){
    int c = cross(a, b ,p);
    pii ld = {min(a.first, b.first), min(a.second, b.second)};
    pii pg = {max(a.first, b.first), max(a.second, b.second)};
    if(c == 0){
        if(!(p.first < ld.first || p.second < ld.second || p.first > pg.first || p.second > pg.second))
            return true;
    }
    return false;
}

int main (int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;

    pii out = {0,0};

    for(int i = 0; i <n; i++){
        int a, b;
        cin >> a >> b;
        polygon.push_back({a, b});
        out.first = min(out.first, a-1);
        out.second = min(out.second, b-1);
    }

    for(int i = 0; i < m; i++){
        pii p;
        cin >> p.first >> p.second;

        int count = 0;
        bool boundary = false;
        for(int i = 0; i < n; i++){
            if (point_on_line(polygon[i], polygon[(i == n-1 ? 0 : i+1)], p)){
                boundary = true;
            }
            if (point_on_line(p, out, polygon[i])){
                if(cross(p, out, polygon[(i == 0 ? n-1 : i-1)]) * cross(p, out,polygon[(i == n-1 ? 0 : i+1)]) < 0){
                    count --;
                }
            }
            count += inter(p, out, polygon[i], polygon[(i == n-1 ? 0 : i+1)]);
        }

        // cout << count << endl;

        string res;
        if (boundary){
            cout << "BOUNDARY" << endl;
        }
        else if (count & 1){
            cout << "INSIDE" << endl;
        }
        else {
            cout << "OUTSIDE" << endl;
        }
    }

    return 0;
}
