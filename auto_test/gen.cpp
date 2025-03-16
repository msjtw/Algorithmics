#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm> 
#include <set> 

using namespace std;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,int> Point;

int n = 20;
ld x00 = 2*n;
ld y00 = 2*n;

vector<ld> angle;
vector<pair<int,int>> ver;
vector<pair<int,int>> ver2;

bool point_on(pii point, pii lineA, pii lineB){
    if(point.first == lineA.first){
        if(point.second >= min(lineA.second, lineB.second) and point.second <= max(lineA.second, lineB.second))
            return true;
    }
    else if(point.second == lineA.second){
        if(point.first >= min(lineA.first, lineB.first) and point.first <= max(lineA.first, lineB.first))
            return true;
    }
    return false;
}
  
// Given three collinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) && 
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are collinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.second - p.second) * (r.first - q.first) - 
              (q.first - p.first) * (r.second - q.second); 
  
    if (val == 0) return 0;  // collinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are collinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

int main(){
    ios_base::sync_with_stdio(false);
    srand (time(NULL));
    for(int i = 0 ; i < n; i++){
        angle.push_back(fmodl((ld)rand(),2*M_PI));
    }

    sort(angle.begin(), angle.end());
    // cout << n << endl;
    for(int i = 0 ; i < n; i++){
        int x, y;

        ld r = fmodl((ld)rand(), 50)+(n);
        x = x00 + r*cos(angle[i]);
        y = y00 + r*sin(angle[i]);
        if(ver.empty() or (x != ver[ver.size()-1].first and y != ver[ver.size()-1].second));
            ver.push_back({x,y});
    }

    ver.push_back(ver[0]);


    for(int i = 0 ; i < ver.size()-1; i++){
        
        ver2.push_back(ver[i]);

        pii next = {ver2[ver2.size()-1].first, ver[i+1].second};
        bool pop = false;
        for(int k = max((int)ver2.size()-2000, 0) ; k < (int)ver2.size()-2; k++){
            if( ver2.size() > 2 and (doIntersect(ver2[k], ver2[k+1], ver2[ver2.size()-1], next))){
                pop = true;
                break;
            }
            if(k < (int)ver2.size()-3 and doIntersect(ver2[k], ver2[k+1], ver2[ver2.size()-2], ver[i])){
                ver2.erase(ver2.end()-1);
                pop = true;
                break;
            }
        }
        while(pop){
            ver2.erase(ver2.end()-1);
            ver2.erase(ver2.end()-1);
            next = {ver2[ver2.size()-1].first, ver[i+1].second};
            pop = false;
            for(int k = max((int)ver2.size()-2000, 0) ; k < (int)ver2.size()-2; k++){
                if( ver2.size() > 2 and (doIntersect(ver2[k], ver2[k+1], ver2[ver2.size()-1], next))){
                    pop = true;
                    break;
                }
                if(k < (int)ver2.size()-3 and doIntersect(ver2[k], ver2[k+1], ver2[ver2.size()-2], ver[i])){
                    ver2.erase(ver2.end()-1);
                    pop = true;
                    break;
                }
            }
        }

        ver2.push_back(next);
    }

    cout << ver2.size() << endl; 
    for(auto &[k, v] : ver2)
        cout << k << " " << v << endl;

    return 0;
}