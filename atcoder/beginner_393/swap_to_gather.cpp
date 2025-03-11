#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int last_1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 1)
            last_1 = i;
    }

    

    return 1;
}
