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
        if(bfs.front().ruchy.dol+1 + bfs.front().ruchy.gora < wyniki[bfs.front().row-1][bfs.front().col].dol + wyniki[bfs.front().row-1][bfs.front().col].gora && plansza[bfs.front().row-1][bfs.front().col]){
            pol as = bfs.front();
            as.row--;
            as.ruchy.dol++;
            wyniki[bfs.front().row-1][bfs.front().col] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.dol+1 + bfs.front().ruchy.gora < wyniki[bfs.front().row][bfs.front().col-1].dol + wyniki[bfs.front().row][bfs.front().col-1].gora && plansza[bfs.front().row][bfs.front().col-1]){
            pol as = bfs.front();
            as.col--;
            as.ruchy.dol++;
            wyniki[bfs.front().row][bfs.front().col-1] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.dol + bfs.front().ruchy.gora+1 < wyniki[bfs.front().row+1][bfs.front().col].dol + wyniki[bfs.front().row+1][bfs.front().col].gora && plansza[bfs.front().row+1][bfs.front().col]){
            pol as = bfs.front();
            as.row++;
            as.ruchy.gora++;
            wyniki[bfs.front().row+1][bfs.front().col] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.dol + bfs.front().ruchy.gora+1 < wyniki[bfs.front().row][bfs.front().col+1].dol + wyniki[bfs.front().row][bfs.front().col+1].gora && plansza[bfs.front().row][bfs.front().col+1]){
            pol as = bfs.front();
            as.col++;
            as.ruchy.gora++;
            wyniki[bfs.front().row][bfs.front().col+1] = as.ruchy;
            bfs.push(as);
        }
        bfs.pop();
    }
    ruch min_razem = wyniki[h][w]; 
    cout << min_razem.dol << " " << min_razem.gora << endl;

    for(int row = 0; row < h+2; row++){
        for(int col = 0; col < w+2; col++){
            if(row == 0 || row == h+1 || col == 0 || col == w+1)
                wyniki[row][col] = {.gora = 0, .dol = 0};
            else
                wyniki[row][col] = {.gora = 3000, .dol = 3000};
        }
    }

    pocz.col = 1;
    pocz.row = 1;
    pocz.ruchy.dol = 0;
    pocz.ruchy.gora = 0;
    bfs.push(pocz);
    while(bfs.size() > 0){
        if(bfs.front().ruchy.gora < wyniki[bfs.front().row-1][bfs.front().col].gora && plansza[bfs.front().row-1][bfs.front().col]){
            pol as = bfs.front();
            as.row--;
            as.ruchy.dol++;
            wyniki[bfs.front().row-1][bfs.front().col] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.gora < wyniki[bfs.front().row][bfs.front().col-1].gora && plansza[bfs.front().row][bfs.front().col-1]){
            pol as = bfs.front();
            as.col--;
            as.ruchy.dol++;
            wyniki[bfs.front().row][bfs.front().col-1] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.gora+1 < wyniki[bfs.front().row+1][bfs.front().col].gora && plansza[bfs.front().row+1][bfs.front().col]){
            pol as = bfs.front();
            as.row++;
            as.ruchy.gora++;
            wyniki[bfs.front().row+1][bfs.front().col] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.gora+1 < wyniki[bfs.front().row][bfs.front().col+1].gora && plansza[bfs.front().row][bfs.front().col+1]){
            pol as = bfs.front();
            as.col++;
            as.ruchy.gora++;
            wyniki[bfs.front().row][bfs.front().col+1] = as.ruchy;
            bfs.push(as);
        }
        bfs.pop();
    }
    ruch min_gora = wyniki[h][w]; 
    cout << min_gora.dol << " " << min_gora.gora << endl;

    for(int row = 0; row < h+2; row++){
        for(int col = 0; col < w+2; col++){
            if(row == 0 || row == h+1 || col == 0 || col == w+1)
                wyniki[row][col] = {.gora = 0, .dol = 0};
            else
                wyniki[row][col] = {.gora = 3000, .dol = 3000};
        }
    }

    pocz.col = 1;
    pocz.row = 1;
    pocz.ruchy.dol = 0;
    pocz.ruchy.gora = 0;
    bfs.push(pocz);
    while(bfs.size() > 0){
        if(bfs.front().ruchy.dol+1 < wyniki[bfs.front().row-1][bfs.front().col].dol && plansza[bfs.front().row-1][bfs.front().col]){
            pol as = bfs.front();
            as.row--;
            as.ruchy.dol++;
            wyniki[bfs.front().row-1][bfs.front().col] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.dol+1 < wyniki[bfs.front().row][bfs.front().col-1].dol && plansza[bfs.front().row][bfs.front().col-1]){
            pol as = bfs.front();
            as.col--;
            as.ruchy.dol++;
            wyniki[bfs.front().row][bfs.front().col-1] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.dol < wyniki[bfs.front().row+1][bfs.front().col].dol && plansza[bfs.front().row+1][bfs.front().col]){
            pol as = bfs.front();
            as.row++;
            as.ruchy.gora++;
            wyniki[bfs.front().row+1][bfs.front().col] = as.ruchy;
            bfs.push(as);
        }
        if(bfs.front().ruchy.dol < wyniki[bfs.front().row][bfs.front().col+1].dol && plansza[bfs.front().row][bfs.front().col+1]){
            pol as = bfs.front();
            as.col++;
            as.ruchy.gora++;
            wyniki[bfs.front().row][bfs.front().col+1] = as.ruchy;
            bfs.push(as);
        }
        bfs.pop();
    }
    ruch min_dol = wyniki[h][w]; 
    cout << min_dol.dol << " " << min_dol.gora << endl;

    long long naj = INT_MAX;
    int ilosc = 0;

    for(int i = 0; i < p; i++){
        long long int a, b;
        cin >> a >> b;
        if(min_razem.dol*b+min_razem.gora*a < naj || min_razem.dol*b+min_razem.gora*a < naj || min_razem.dol*b+min_razem.gora*a < naj){
            naj = min(min_razem.dol*b+min_razem.gora*a,min(min_razem.dol*b+min_razem.gora*a,min_razem.dol*b+min_razem.gora*a));
            ilosc = 1;
        }
        else if(min_razem.dol*b+min_razem.gora*a == naj || min_razem.dol*b+min_razem.gora*a == naj || min_razem.dol*b+min_razem.gora*a == naj){
            ilosc++;
        }

    }
    cout << naj << " " << ilosc;
}