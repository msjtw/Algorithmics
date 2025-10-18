#include<iostream>

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;

// a, b line; c point
ll cross(pii a, pii b, pii c){
    pii va, vb;
    va.first = b.first-a.first;
    va.second = b.second-a.second;
    vb.first = c.first-b.first;
    vb.second = c.second-b.second;
    return (ll)va.first*vb.second - (ll)vb.first*va.second;
}

int main(){
    int n;
    cin >> n;
    while(n --> 0){
        pii a, b, p;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> p.first >> p.second;
        ll cros = cross(a, b, p);
        if(cros > 0)
            cout << "LEFT\n";
        else if(cros == 0)
            cout << "TOUCH\n";
        else
            cout << "RIGHT\n";
    }
    return 0;
}
