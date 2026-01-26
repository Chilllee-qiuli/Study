#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, Ax, Ay, Bx, By;
ll dpl[maxn], dpr[maxn];

struct node{
    int x, y;
}nodetmp[maxn];

vector< vector<node> > vc;
vector<int> xx;
map<int, int> mp;

bool cmp(node x, node y){
    return x.x == y.x ? x.y < y.y : x.x < y.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> t;
    while(t--){
        vector< vector<node> > ().swap(vc);
        vector<int> ().swap(xx);
        mp.clear();
        cin >> n >> Ax >> Ay >> Bx >> By;
        // for(int i = 0; i <= n + 2; i++)
        // dpl[i] = dpr[i] = 0x3f3f3f3f;

        for(int i = 1; i <= n; i++){
            int x, y;
            cin >> x >> y;
            node tmp = {x, y};
            nodetmp[i] = tmp;
            xx.push_back(x);
        }
        xx.push_back(Ax);
        xx.push_back(Bx);

        sort(xx.begin(), xx.end());
        xx.erase(unique(xx.begin(), xx.end()), xx.end());
        for(int i = 0; i < xx.size(); i++){
            mp[xx[i]] = i + 1;
        }
        for(int i = 1; i <= n; i++){
            int idx = mp[nodetmp[i].x];
            nodetmp[i].x = idx;
            vc[idx].push_back(nodetmp[i]);
        }
        Ax = mp[Ax];
        Bx = mp[Bx];    
        dpl[Ax] = dpr[Ax] = 0;

        for(int i = 1; i <= Bx; i++){
            //if(vc[i].empty()) continue;
            sort(vc[i].begin(), vc[i].end(), cmp);
            int l = vc[i - 1][0].y, r = vc[i - 1][vc[i-1].size() - 1].y;
            dpl[i] = min(dpl[i - 1] + abs(l - vc[i][0].y), dpr[i - 1] + abs(r - vc[i][0].y));
            dpr[i] = min(dpl[i - 1] + abs(l - vc[i][vc[i].size() - 1].y), dpr[i - 1] + abs(r - vc[i][vc[i].size() - 1].y));
        }



    }


	return 0;
}