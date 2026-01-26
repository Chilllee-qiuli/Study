#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;

ll tme[maxn];
int hour[maxn];
bool run(int y){
    return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
}

ll trans(int y, int m){
    ll day = 0;
    int i = 2000;
    for(; i <= y; i+=4)
        if(run(i)) day += 1461;
        else day += 1460;
    day += (y - i) * 365;
    return day;
}

void work_max(){
    
    int ddl = tme[1];
    int lft = 0, rht = 0;
    if(hour[1] < 20) lft = 1;
    else if(hour[1] >= 16) rht = 1;
    int max_ans = 0, now_ans = 0;
    for(int i = 2; i <= n; i++){
        if(tme[i] - ddl == 1) now_ans++;
        else if(tme[i] - ddl == 2 && rht){rht = 0; now_ans++;}
        else if(tme[i] == ddl){
            if(rht){

            }
        }
    }
}



int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        int year, month, day;
        scanf(" %d-%d-%d", &year, &month, &day);
        int x;
        scanf(" %d:%d:%d", &hour[i], &x, &x);
        
        tme[i] = 1ll * day + trans(year, month);

    }


	return 0;
}