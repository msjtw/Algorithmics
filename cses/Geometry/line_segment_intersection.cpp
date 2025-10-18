#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;

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

ll cross(pii a, pii b, pii c){
    pii va, vb;
    va.first = b.first-a.first;
    va.second = b.second-a.second;
    vb.first = c.first-b.first;
    vb.second = c.second-b.second;
    return (ll)va.first*vb.second - (ll)vb.first*va.second;
}

bool rect_inter(pii a, pii b, pii c, pii d){
    pii p1 = {min(a.first, b.first), max(a.second, b.second)};
    pii p2 = {max(a.first, b.first), min(a.second, b.second)};
    pii p3 = {min(c.first, d.first), max(c.second, d.second)};
    pii p4 = {max(c.first, d.first), min(c.second, d.second)};

    // cout << p1.first << " " << p1.second << " ";
    // cout << p2.first << " " << p2.second << " | ";
    // cout << p3.first << " " << p3.second << " ";
    // cout << p4.first << " " << p4.second << " \n";

    if (p3.first > p2.first || p4.first < p1.first || p3.second < p2.second || p4.second > p1.second)
        return false;
    return true;
}


int main(){
    int q;
    cin >> q;
    while(q --> 0){
        pii a, b, c, d;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;
        cin >> d.first >> d.second;
        
        if (rect_inter(a, b, c, d)) {
            // cout << "inter" << endl;
            if (sign(cross(a,b,c)) * sign(cross(a,b,d)) <= 0 && sign(cross(c,d,a)) * sign(cross(c,d,b)) <= 0) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }

    return 0;
}
