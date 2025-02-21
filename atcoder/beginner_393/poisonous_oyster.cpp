#include <iostream>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == "sick"){
        if(s2 == "sick")
            cout << 1;
        else
            cout << 2;
    }
    else{
        if(s2 == "sick")
            cout << 3;
        else 
            cout << 4;
    }
}
