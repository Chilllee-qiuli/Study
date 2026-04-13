#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn  = 1e5 + 10;
const ull base = 1e9 + 7; // 对ull作自然溢出
// base 是以1e9+7进制，对【单个字符】构造哈希
// 比如字符x（由题意，x为不大于1e5的自然数），其哈希为base的x次方。
// 由于具有交换律和可加性，故不需要对某种字符计数，遇到新的字符加上哈希值即可实现。
// 所以只要base大于maxn即可正确表示，但是其实仍有冲突概率。
int n, T, Q;
ull f[maxn], t;
ull farr[maxn]; // 每个小串的哈希值
vector<ull> arr[maxn], pre[maxn];
int id[maxn];
int roundans[maxn]; // 注意是前缀答案和


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    f[0] = 1;
    for(int i = 1; i < maxn; i++) // 预处理每个字符的哈希值
        f[i] = f[i - 1] * base;
    
    cin >> n >> T >> Q;
    for(int i = 1; i <= T; i++){// 得到主串的哈希值
        int x;
        cin >> x;
        t += f[x];
    }

    for(int i = 1; i <= n; i++){
        int len; cin >> len;
        arr[i].push_back(0);
        for(int j = 1; j <= len; j++){
            int x; cin >> x;
            arr[i].push_back(x);
            farr[i] += f[x];
        }
        ull u = 0 ;
        pre[i].push_back(0);
        for(int j = 1; j <= len; j++){
            u += f[arr[i][j]];
            pre[i].push_back(u);
        }
    }

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> id[i];
 
    int len = 0, l = 1;
    ull tp = 0;
    int ans = 0;

    bool full = 0;

    for(int i = 1; Q; --Q, ++i){
        int p = (i - 1) % m + 1;
        len += arr[id[p]].size() - 1;
        tp += farr[id[p]];
        while(len - arr[id[l]].size() + 1 >= T){
            len -= arr[id[l]].size() - 1;
            tp -= farr[id[l]];
            l++;
            if(l > m) l = 1;
        }
        if(len >= T){
            if(full) roundans[p] += roundans[p - 1];
            if(tp - pre[id[l]][len - T ] == t) {
				++ans;
				if(full) ++roundans[p];
			}
        }
        if(full && p == m){
            Q--;
            break;
        }
        if(len >= T && p == m) full = 1; // 先填充完长度大于T的一轮，并且m也得早已轮过一轮。
    }

    

    ans += (Q / m) * roundans[m];
    ans += roundans[Q % m];

    cout << ans << endl;



	return 0;
}
