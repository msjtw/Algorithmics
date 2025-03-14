#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

map<int,int> vals;
vector<int> arr;

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        vals[a]++;
    }

    for(auto a : vals){
        arr.push_back(a.second);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int res = 0;

    int i = 0;
    int k = arr.size()-1;
    while(i <= k){
        res++;
        int free = arr[i]-1;
        i++;
        while(free > 0){
            if(free >= arr[k]){
                free -= arr[k];
                k--;
            }
            else{
                arr[k] -= free;
                free = 0;
            }
        }
    }

    cout << res;

    return 0;
}