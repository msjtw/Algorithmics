#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --> 0){
        vector<int> arr;
        vector<int> in;
        vector<int> out;
        bool zero = false;
        bool popsuted = false;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a == 0){
                zero = true;
                continue;
            }
            else if(zero){
                popsuted = true;
            }
            arr.push_back(a);
        }
        in.resize(arr.size());
        out.resize(arr.size());
        
    }
}
