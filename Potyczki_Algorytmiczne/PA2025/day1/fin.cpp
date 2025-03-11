#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int num = 0;
    for(int i = 0; i < n; i++){
        string s;
        int b;
        cin >> s >> b;
        if(num < 10){
            if(s == "TAK"){
                cout << i+1 << " ";
                num ++;
            }
        }
        else if(num < 20){
            if(s == "TAK" and b < 2){
                cout << i+1 << " ";
                num ++;
            }
        }
        else{
            break;
        }  
    }
    return 0;
}
