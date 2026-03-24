#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5050;
int a[maxn], ans[maxn];
ll tr[maxn];

int n;

void add(int x, int y){
    for(; x <= n; x += x & -x) tr[x] += y;
}

int find(int x){
    int tmp = 0;
    for(; x; x -= x & -x) tmp += tr[x];
    return tmp;
}

vector<int> lisan;



void solve_one(){
    cin >> n;
    vector<int>().swap(lisan);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        lisan.push_back(a[i]);
        tr[i] = 0;
    }
    
    sort(lisan.begin(), lisan.end());
    lisan.erase(unique(lisan.begin(), lisan.end()), lisan.end());
    
    for(int j = n; j; j--){
        a[j] = lower_bound(lisan.begin(), lisan.end(), a[j]) - lisan.begin() + 1;
        int low = find(a[j] - 1);
        int eq = find(a[j]) - low;
        int up = n - j - low - eq;
        ans[j] = max(low, up);
        add(a[j], 1);
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve_one();
    }




	return 0;
}
