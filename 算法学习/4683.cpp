#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair <int, int>
#define mk make_pair
#define fi first 
#define se second
const int maxn = 25010;
const int maxc = 500500;

int nex[maxc][27];
int exist[maxc];
int cnt;

int n;
string s[maxn];

void insert(string s){
    int l = s.length();
    int p = 0;
    for(int i = 0; i < l; i++){
        int c = s[i] - 'a';
        if(!nex[p][c]) nex[p][c] = ++cnt;
        p = nex[p][c];
    }
    exist[p] = 1;
}

int maxx = 0;

void dfs(int p, int len, int op){
    if(exist[p]) cout << "P" << endl;
    if(len >= s[maxx].length()) return ;
    int c = s[maxx][len] - 'a';

    for(int i = 0; i < 26; i++){
        if(op && i == c) continue;
        if(!nex[p][i]) continue;

        cout << (char)('a' + i) << endl;
        dfs(nex[p][i], len + 1, 0);
        cout << "-" << endl;
    }
    if(!op) return ;
    cout << s[maxx][len] << endl;
    dfs(nex[p][c], len + 1, 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        insert(s[i]);
        if(s[i].length() > s[maxx].length()) maxx = i;
    }

    cout << cnt * 2 - s[maxx].length() + n << endl;

    dfs(0, 0, 1);

	return 0;
}
