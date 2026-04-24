#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

multiset<ll> L, R;// L: 较小一半, R: 较大一半

ll suml = 0, sumr = 0;
void adjust(){ // 保证 L.size() == R.size() 或 L.size() == R.size() + 1
    while(L.size() < R.size()){
        auto it = R.begin(); // R 的最小值
        ll x = *it; 
        R.erase(it);
        sumr -= x;

        L.insert(x);
        suml += x;
    }
    while(L.size() > R.size() + 1){
        auto it = prev(L.end()); // L 的最大值
        // prev: 把迭代器往前挪一个位置，等效于 L.rbegin()
        ll x = *it;
        L.erase(it);
        suml -= x;
        R.insert(x);
        sumr += x;
    }
    /* 由于保证插入正确，所以只要两个集合的大小关系正确即可，下面这段调整可以不需要
    while (!L.empty() && !R.empty() && *L.rbegin() > *R.begin()) {
        ll x = *L.rbegin();
        ll y = *R.begin();

        L.erase(L.find(x));
        R.erase(R.find(y));
        suml -= x; sumr -= y;

        L.insert(y);
        R.insert(x);
        suml += y; sumr += x;
    }*/
}
void insert(ll x){
    if(L.empty() || x <= *L.rbegin()){
        L.insert(x);
        suml += x;
    }
    else{
        R.insert(x);
        sumr += x;
    }
    adjust();
}
void erase(ll x){
    auto it = L.find(x);
    if(it != L.end()){
        L.erase(it);
        suml -= x;
    }
    else {
        it = R.find(x);
        if(it != R.end()){
            R.erase(it);
            sumr -= x;
        }
    }
    adjust();
}

ll median(){
    // adjust(); 由于插入正确，故任意时刻集合都是对的不用再调整
    return *L.rbegin(); // 下中位数
}
ll cost(){
    ll x = median();
    return sumr - x * R.size() + x * L.size() - suml;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t ;
    cin >> t;
    while(t--){
        int n; ll k;
        cin >> n >> k;

        // 多测不清空，亲人两行泪
        L.clear();
        R.clear();
        suml = sumr = 0;

        vector<ll> a(n + 1), b(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i] - i;
        }
        
        int ans = 0;
        int l = 1;
    
        for(int r = 1; r <= n; r++){
            insert(b[r]);
            while(cost() > k){
                erase(b[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << "\n";
    }

	return 0;
}
