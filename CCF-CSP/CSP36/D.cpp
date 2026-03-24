#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int a[maxn], k[maxn];
int n;

vector<int> lisan;

queue<int> qu;
int f[maxn];


int bfs(){
    ++(++n);
    qu.push(1);
    f[1] = 1;
    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        //if(f[u]) continue;
        if(f[n]) return f[n];
        int step = f[u];
        for(int i = min(n, u + k[u]); i >= u + 1; i--)
            if(!f[i - a[i]]){
                f[i - a[i]] = step + 1;
                qu.push(i - a[i]);
            }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    lisan.push_back(-1);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    for(int i = 1; i <= n; i++) 
        cin >> k[i];


    cout << bfs() - 1 << "\n";


	return 0;
}
