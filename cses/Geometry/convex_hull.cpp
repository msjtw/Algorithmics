#include <complex>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

#define INCUDE_COLINEAR true

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;


ll cross2(pii a, pii b) {
    return (ll)a.first * b.second - (ll)a.second * b.first;
}

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

int cross3(pii a, pii b, pii c){
    pii va, vb;
    va.first = b.first-a.first;
    va.second = b.second-a.second;
    vb.first = c.first-b.first;
    vb.second = c.second-b.second;
    return sign((ll)va.first*vb.second - (ll)vb.first*va.second);
}

double norm(pii v){
    return (v.first * v.first) + (v.second * v.second);
}

pii sub(pii a, pii b){
    return {a.first - b.first, a.second - b.second};
}

int n;
pii p0 = {INT_MAX, INT_MAX};
vector <pii> points;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
cin >> a >> b;
        points.push_back({a,b});
        if(b < p0.second or (b == p0.second && a < p0.first)){
            p0 = {a, b};
        }
    }

    sort(points.begin(), points.end(), [](pii l, pii r){
        int o = cross3(l, r, p0);
        if (o == 0) {
            return norm(sub(p0,l)) < norm(sub(p0,r));
        }
        return o < 0;
    });
    
    
    if (INCUDE_COLINEAR) {
        int i = points.size()-1;
        while (i >= 0 && cross3(p0, points[i], points.back())) i--;
        reverse(points.begin()+i+1, points.end());
    }

    vector<pii> hull;
    // hull.push_back(points[0]);
    // hull.push_back(points[1]);

    for (int i = 0; i < n; i++){
        // cerr << points[i].first << " " << points[i].second << " pop: ";
        while(hull.size() > 1 && cross3(hull[hull.size()-2], hull[hull.size()-1], points[i]) >= 0){
            // cerr << hull[hull.size()-1].first << " " << hull[hull.size()-1].second << "; ";
            hull.pop_back();
        }
        // cerr << endl;
        hull.push_back(points[i]);
    }

    // cerr << p0.first << " " << p0.second << endl;

    cout << points.size() << " ";
    cout << hull.size() << endl;

    for(auto a : points){
        cout << a.first<< " " << a.second << endl;
    }   

    for(auto a : hull){
        cout << a.first << " " << a.second << endl;
    }
    
}
