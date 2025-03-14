#include <iostream>
#include <climits>
#include <string>
#include <queue>

using namespace std;

struct ruch{
    int gora;
    int dol;
};

struct pol{
    int row;
    int col;
    ruch ruchy;
};

ruch wyniki[2010][2010];


bool plansza[2010][2010];
int h, w;
int ngora = INT_MIN, ndol = INT_MAX;
int dol, gora;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int p;
    cin >> h >> w >> p;
    string rz;
    for(int i = 1; i <= h; i++){
        cin >> rz;
        for(int j = 0; j < rz.size(); j++){
            if(rz[j] == 'X')
                plansza[i][j+1] = false;
            else
                plansza[i][j+1] = true;
        }
    }
    long long naj = INT_MAX;
    int ilosc = 0;
    int a, b;

    while(p--){
        cin >> a >> b;
        if(a > ngora && b > ndol)
            continue;
        for(int row = 0; row < h+2; row++){
            for(int col = 0; col < w+2; col++){
                if(row == 0 || row == h+1 || col == 0 || col == w+1)
                    wyniki[row][col] = {.gora = 0, .dol = 0};
                else
                    wyniki[row][col] = {.gora = 3000, .dol = 3000};
            }
        }
        queue <pol> bfs;
        pol pocz;
        pocz.col = 1;
        pocz.row = 1;
        pocz.ruchy.dol = 0;
        pocz.ruchy.gora = 0;
        bfs.push(pocz);
        while(bfs.size() > 0){
            if((bfs.front().ruchy.dol+1)*b + bfs.front().ruchy.gora*a < wyniki[bfs.front().row-1][bfs.front().col].dol*b + wyniki[bfs.front().row-1][bfs.front().col].gora*a && plansza[bfs.front().row-1][bfs.front().col]){
                pol as = bfs.front();
                as.row--;
                as.ruchy.dol++;
                wyniki[bfs.front().row-1][bfs.front().col] = as.ruchy;
                bfs.push(as);
            }
            if((bfs.front().ruchy.dol+1)*b + bfs.front().ruchy.gora*a < wyniki[bfs.front().row][bfs.front().col-1].dol*b + wyniki[bfs.front().row][bfs.front().col-1].gora*a && plansza[bfs.front().row][bfs.front().col-1]){
                pol as = bfs.front();
                as.col--;
                as.ruchy.dol++;
                wyniki[bfs.front().row][bfs.front().col-1] = as.ruchy;
                bfs.push(as);
            }
            if(bfs.front().ruchy.dol*b + (bfs.front().ruchy.gora+1)*a < wyniki[bfs.front().row+1][bfs.front().col].dol*b + wyniki[bfs.front().row+1][bfs.front().col].gora*a && plansza[bfs.front().row+1][bfs.front().col]){
                pol as = bfs.front();
                as.row++;
                as.ruchy.gora++;
                wyniki[bfs.front().row+1][bfs.front().col] = as.ruchy;
                bfs.push(as);
            }
            if(bfs.front().ruchy.dol*b + (bfs.front().ruchy.gora+1)*a < wyniki[bfs.front().row][bfs.front().col+1].dol*b + wyniki[bfs.front().row][bfs.front().col+1].gora*a && plansza[bfs.front().row][bfs.front().col+1]){
                pol as = bfs.front();
                as.col++;
                as.ruchy.gora++;
                wyniki[bfs.front().row][bfs.front().col+1] = as.ruchy;
                bfs.push(as);
            }
            bfs.pop();
        }
        if(wyniki[h][w].dol*b+wyniki[h][w].gora*a < naj){
            ilosc = 0;
            naj = wyniki[h][w].dol*b+wyniki[h][w].gora*a;
            ngora = a;
            ndol = b;
        }
        if(wyniki[h][w].dol*b+wyniki[h][w].gora*a == naj){
            ilosc++;
        }
    }

    cout << naj << " " << ilosc << endl;
    
}