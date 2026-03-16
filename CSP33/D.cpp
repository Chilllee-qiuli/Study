#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 3e5 + 10;
int c, n, m;

struct water{
    int x, w;
    int lf, rht;
}wt[maxm];
vector<int> lisan;
int vis[maxm];

int now;

void pre();
void work(int p);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();

    now = m;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;

        p = lower_bound(lisan.begin(), lisan.end(), p) - lisan.begin();
        wt[p].w++;
        if(wt[p].w >= 5) work(p);

        cout << now << endl;

    }
    
    
    
    return 0;
}

void work(int p){
    if(p == 0 || p == m + 1) return ;
    if(wt[p].w < 5) return;
    now--;
    vis[p] = 1;
    wt[p].w = 0;
    int l = wt[p].lf, r = wt[p].rht;
    while(vis[l] && l != 0) l = wt[l].lf;
    while(vis[r] && r != m + 1) r = wt[r].rht;
    wt[l].rht = r; wt[r].lf = l;
    if(!vis[l]) {
        wt[l].w++;
        work(l);
    }
    if(!vis[r]) {
        wt[r].w++;
        work(r);
    }

}

void pre(){
    cin >> c >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> wt[i].x >> wt[i].w;
        lisan.push_back(wt[i].x);
    }
    lisan.push_back(-1);
    sort(lisan.begin(), lisan.end());
    lisan.erase(unique(lisan.begin(), lisan.end()), lisan.end());
    
    for(int i = 1; i <= m; i++) wt[i].x = lower_bound(lisan.begin(), lisan.end(), wt[i].x) - lisan.begin();
    
    sort(wt + 1, wt + 1 + m, [](const water & x, const water& y){
        return x.x < y.x;
    });

    for(int i = 1; i <= m; i++){
        wt[i].lf = i - 1;
        wt[i].rht = i + 1;
    }   
    
}