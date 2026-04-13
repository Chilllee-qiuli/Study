#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull base = 131;
const ull mod = 1e9 + 7;
const int maxn = 1e6 + 10;

string s, T;
ull pre[maxn], p[maxn];
char stk[maxn]; int tp;

ull gethash(string s){
    int len = s.size();
    ull ans = 0;
    for(int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod;
    return ans;
}
void Pre(){
    p[0] = 1;
    for(int i = 1; i < maxn; i++)
    p[i] = p[i - 1] * base % mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Pre();
    cin >> s >> T;
    ull t = gethash(T);

    for(auto ch : s){
        stk[++tp] = ch;
        pre[tp] = (pre[tp - 1] * base + (ull)ch) % mod;
        if(tp >= T.size()){
            ull now = (pre[tp] + mod - pre[tp - T.size()] * p[T.size()] % mod) % mod;
            if(now == t){
                tp = tp - T.size();
            }
        }
    }
    for(int i = 1; i <= tp; i++)
    cout << stk[i];
    cout << "\n";



	return 0;
}
