#include <iostream>

using namespace std;

const int MX = 8008;

int online_meetings[MX];
int all_meetings[MX];

int main(){
    int n, m, t;
    cin >> n >> m >> t;
    string time_line;
    cin >> time_line;
    for(int i = 1; i <= n; i++){
        if(time_line[i-1] == '1'){
            all_meetings[i]++;
        }
        if(time_line[i-1] == '2'){
            online_meetings[i] ++;
            all_meetings[i]++;
        }
        online_meetings[i] += online_meetings[i-1];
        all_meetings[i] += all_meetings[i-1];
    }

    int res = -1;

    for(int i = t+1; i <= n-t; i++){
        for(int k = i; k <= n-t; k++){
            int att_meetings = all_meetings[k] - all_meetings[i-1];
            int meet_to_attend = max(all_meetings[n]-m-att_meetings, 0);
            int meets_in_free_time = (online_meetings[i-t-1]) + (online_meetings[n] - online_meetings[k+t]);
            if(meet_to_attend > meets_in_free_time){
                continue;
            }
            int free_time = n - (k-i+1) - 2*t;
            free_time -= meet_to_attend;
            res = max(res, free_time);
        }
    }

    if(max(all_meetings[n]-m,0) <= online_meetings[n]){
        res = max(res, n - max((all_meetings[n]-m),0));
    }

    cout << res << endl;

    return 0;
}
