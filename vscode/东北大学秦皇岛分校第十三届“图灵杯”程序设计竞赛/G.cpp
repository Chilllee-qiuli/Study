#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mk make_pair
#define pr pair<int, int> 
const int maxn = 3030;
int n;
pr ans;
pr node[maxn];
int stx;
long double minn = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> node[i].first >> node[i].second;
    } 
    node[n + 1] = node[1];

    cin >> stx;


    for(int i = 1; i <= n; i++){
        int x_x = node[i].first, x_y = node[i].second, y_x = node[i + 1].first, y_y = node[i + 1].second;
        // 记得特判平行
        if(y_x == x_x) continue;
        long double tmp = 1.0 * (stx - x_x) * (y_y - x_y) / (y_x - x_x) + x_y;
        if((tmp - minn) < 1e-9 && (tmp > 0 || abs(tmp) <= 1e-9) && min(x_x, y_x) < stx && max(x_x, y_x) > stx){
            minn = tmp;
            ans = mk(i, (i + 1 - 1)% n + 1);
        }
    }

    cout << ans.first << " " << ans.second << endl;
	return 0;
}