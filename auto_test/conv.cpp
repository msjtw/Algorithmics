#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

vector<pii> arr;

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a,b});
    }

    cout << arr[0].first  << " " << arr[0].second << endl;
    cout << arr.size() << endl;
    arr.push_back(arr[0]);
    for(int i = 0 ; i < n; i++){
        pii a = arr[i];
        pii b = arr[i+1];
        if(a.first == b.first){
            if(a.second < b.second)
                cout << 'N' << " " << b.second-a.second << endl;
            if(a.second > b.second)
                cout << 'S' << " " << a.second-b.second << endl;
        }
        else{
            if(a.first < b.first)
                cout << 'E' << " " << b.first-a.first << endl;
            if(a.first > b.first)
                cout << 'W' << " " << a.first-b.first << endl;
        }
    }
}