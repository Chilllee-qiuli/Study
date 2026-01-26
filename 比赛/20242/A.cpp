#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, k;
int c = inf;
int w[maxn];
string str[maxn];

map<string, vector<int> > team;
vector<int> fd;

bool cmpa(int x, int y){return x > y;}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        c = min(c, x);
    }

    for(int i = 1; i <= n; i++){
        cin >> w[i];
        cin >> str[i];
        team[str[i]].push_back(w[i]);
    }

    for(auto it : team){
        sort(team[it.first].begin(), team[it.first].end());
        for(int i = team[it.first].size() - 1; i >= max(0, (int)team[it.first].size() - c + 1); i--)
        fd.push_back(team[it.first][i]);
    }
    sort(fd.begin(), fd.end(), std::greater<int>());

    for(int i = 0; i < fd.size(); i++){
        cout << fd[i] << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i++){
        int rank = lower_bound(fd.begin(), fd.end(), w[i]) - fd.begin();
        int id = lower_bound(team[str[i]].begin(), team[str[i]].end(), w[i]) - team[str[i]].begin();
        //cout << "nowrank: " << rank << " id= " << id << " ";
        if(id < c) cout << rank << endl;
        else cout << rank - 1 << endl;
    }

    

	return 0;
}
