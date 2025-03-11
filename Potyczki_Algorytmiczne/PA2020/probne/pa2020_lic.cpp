//Stanislaw Fiedler 

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int p, q;
    cin >> p >> q;
    long long int ilosc = 0;
    int i_cyfr[10] {};
    for(long long int temp = p; temp > 0; temp /= 10)
        i_cyfr[temp%10]++;

    for(long long i = p; i <= q; i++){
        if(i_cyfr[0] == 0){
            bool nie = false;
            for(int dz = 0; dz < 10; dz++){
                if(i_cyfr[dz] > 0 && i%dz != 0){
                    nie = true; 
                }   
            }
            if(!nie){
                ilosc++;
            }    
        }
        long long int temp = i;
        long long int pot = 1;
        while(temp%10==9){
            i_cyfr[9]--;
            i_cyfr[1]++;
            i+= pot;
            temp/=10;
            pot *= 10;
        }
        if(temp > 0)
            i_cyfr[temp%10]--;
        i_cyfr[(temp%10)+1]++;
        

    }
    cout << ilosc;

    return 0;
}