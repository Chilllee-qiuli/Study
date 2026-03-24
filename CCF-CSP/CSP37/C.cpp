#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int maxn = 2020;
map<string, ll> mp;
int tot;
vector<int> g[maxn];
ll leng[maxn];
ll f[maxn];
int flag[maxn];

ll fd(string s);
ll dfs(int u);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 吸取缓冲区换行
    for(int i = 1; i <= n; i++){
        string rd;
        getline(cin, rd);
        istringstream iss(rd);

        int op;
        string tg; // 目标字符串 target
        iss >> op >> tg;
        if(op == 3) {
            cout << fd(tg) % mod << endl;
            continue;
        }
        string str;
        ll cnt = 0; // 统计长度
        if(!mp[tg]) mp[tg] = ++tot;
        vector<int> ().swap(g[mp[tg]]);
        flag[mp[tg]] = 0;
        if(op == 1){
            while(iss >> str){
                if(str[0] != '$') cnt = (cnt + str.size()) % mod;
                else cnt = (cnt + fd(str.substr(1))) % mod;
            }
        }
        else { // 间接赋值
            while(iss >> str){
                if(str[0] != '$') cnt = (cnt + str.size()) % mod;
                else {
                    str = str.substr(1);
                    if(!mp[str]) mp[str] = ++tot;
                    g[mp[tg]].push_back(mp[str]);
                }
            }
        }
        leng[mp[tg]] = cnt % mod;
    }


    return 0;
}
ll dfs(int u){
    if(flag[u]) return f[u] % mod;
    ll tmp = leng[u] % mod;
    for(auto v : g[u]) tmp = (tmp +  dfs(v)) % mod;
    // flag[u] = 1;
    return f[u] = tmp % mod;
}

ll fd(string s){
    return dfs(mp[s]) % mod;
}
