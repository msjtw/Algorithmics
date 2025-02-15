#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> keys;
vector<vector<int>> locks;

int main(){
    for(int t = 0; t < 500; t++){
        string pattern[8];
        for(int i = 0; i < 7; i++){
            cin >> pattern[i];
        }

        bool is_lock = false;
        if(pattern[0][0] == '#')
            is_lock = true;

        vector<int> len;
        for(int i = 0; i < 5; i++){
            int l = 0;
            for(int k = 1; k < 6; k++){
                if(pattern[k][i] == '#'){
                    l++;
                }
            }
            if(is_lock)
                len.push_back(l);
            else
                len.push_back(l);
        }

        if(is_lock){
            //lock
            locks.push_back(len);
        }
        else{
            //key
            keys.push_back(len);
        }
    }
    
    int res = 0;
    for(auto lock : locks){
        for(auto key : keys){
            // for(int c : lock){
            //     cout << c << ",";
            // }
            // cout << "    ";
            // for(int c : key){
            //     cout << c << ",";
            // }
            // cout << endl;
            bool popsuted = false;
            for(int i = 0; i < 5; i++){
                if(lock[i] + key[i] > 5){
                    popsuted = true;;
                }
            }
            if(!popsuted)
                res++;
        }
    }

    cout << res;

}
