#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int T;
int n;
int l[maxn], r[maxn];
ll tmp;

int dep[maxn];
ll cnt[33];
void pre_dfs(int u, int d){
    dep[u] = d + 1;
    if(dep[u] <= 27) cnt[dep[u]]++;
    else cnt[19]++; // 第19层开始肯定要删掉，这里进行计数
    if(l[u]) pre_dfs(l[u], d + 1);
    if(r[u]) pre_dfs(r[u], d + 1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n*2; i++) {l[i] = r[i] = 0;}
        for(int i = 1; i <= n; i++)
            cin >> l[i] >> r[i];

        pre_dfs(1, -1);
        
        ll ans = n - 1, tmp_cnt = 0;//ans最初答案：删掉所有点；tmp_cnt存储满二叉树深度保持到当前层-1要加多少点
        ll del = n - 1;
        for(int i = 1; i <= 27; i++ ){
            del -= cnt[i];
            ll cmp_ans = tmp_cnt + del;
            tmp_cnt += pow(2, i) - cnt[i];
            cmp_ans = min(cmp_ans, tmp_cnt + del - cnt[i]);
            //printf("cmp_ans= %d tmp_cnt= %d del= %d\n", cmp_ans, tmp_cnt, del);
            if(cmp_ans <= ans) ans = cmp_ans;
            else break;
        }
        cout << ans << endl;
    }

	return 0;
}
