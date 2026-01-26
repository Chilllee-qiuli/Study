#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int t;
int n, l, r;
vector<int> al, ar, a;

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n >> l >> r;
        al.clear();
        ar.clear();
        a.clear();
        for(int i = 1, x; i <= n; i++){
            cin >> x;
            if(x <= l) al.push_back(x);
            else if(x >= r) ar.push_back(x);
            else a.push_back(x);
        }
        if(al.size() > ar.size()){
            sort(a.begin(), a.end(), greater<int>());
            int cnt = al.size() - ar.size();
            int flag = ar.size();
            for(int i = 0; i < a.size() && i < cnt; i++, flag++)
                ans += a[i] - al[flag];
            for(int i = 0; i < ar.size(); i++)
                ans += ar[i] - al[i];
            vector<int> tmp;
            for(int i = cnt; i  < a.size(); i++) tmp.push_back(a[i]);
            sort(tmp.begin(), tmp.end());
            for(int i = 0; i < tmp.size() && (tmp.size() - 1 - i) > i; i++)
            ans += tmp[tmp.size() - i - 1] - tmp[i];
            // cout << "tmp ans : " << ans << endl;
            for(int i = ar.size() + a.size(); i < al.size(); i++)
            ans += l - al[i];
        }
        else if(al.size() < ar.size()){
            sort(a.begin(), a.end());
            int cnt = ar.size() - al.size();
            int flag = al.size();
            for(int i = 0; i < a.size() && i < cnt; i++, flag++)
                ans += ar[flag] - a[i];
            for(int i = 0; i < al.size(); i++)
                ans += ar[i] - al[i];
            vector<int> tmp;
            for(int i = cnt; i < a.size(); i++) tmp.push_back(a[i]);
            sort(tmp.begin(), tmp.end());
            for(int i = 0; i < tmp.size() && (tmp.size() - 1 - i) > i; i++)
                ans += tmp[tmp.size() - i - 1] - tmp[i];
            for(int i = al.size() + a.size(); i < ar.size(); i++)
                ans += ar[i] - r;
        }   
        else {
            for(int i = 0; i < al.size(); i++)
                ans += ar[i] - al[i];
            vector<int> tmp;
            int cnt = 0;
            for(int i = cnt; i < a.size(); i++) tmp.push_back(a[i]);
            sort(tmp.begin(), tmp.end());
            for(int i = 0; i < tmp.size() && (tmp.size() - 1 - i) > i; i++)
                ans += tmp[tmp.size() - i - 1] - tmp[i];
        }

        cout << ans << endl;
    }

	return 0;
}
