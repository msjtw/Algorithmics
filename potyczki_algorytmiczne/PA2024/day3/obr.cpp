#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef long long int ll;

vector<int> arr;

int main(){
    int h, w;
    int n;
    cin >> h >> w;
    if(h > w)
        swap(h, w);
    cin >> n;

    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int small = arr[arr.size()-1];
    if(h%small != 0 or w%small != 0){
        cout << -1;
        return 0;
    }

    ll res = 0;

    for(int i = 0 ; i < n and h > 0; i++){
        int size = arr[i];
        int mul = h/size;
        h -= (mul*size);
        ll add = 0;
        int w2 = w;
        for(int k = i ; k < n and w2 > 0; k++){
            int size2 = arr[k];
            int m = w2/size2;
            w2 -= (m*size2);
            add += (m*(size/size2));
        }
        res += add*mul;
    }

    cout << res;

    return 0;
}