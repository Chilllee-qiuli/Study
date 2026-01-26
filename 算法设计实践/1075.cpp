#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int t;
int n, m;
ll k, p[maxn];

ll work(vector<ll> vec, ll x){
    vec.push_back(x);
    ll sum = 0;
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= min(m, (int)vec.size()/2); i++){
        ll y = vec[i - 1] - vec[vec.size() - 1 - i + 1];
        sum += y * y;
    }
    //printf("test: new: %lld, sum: %lld\n", x, sum);
    return sum;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) cin >> p[i];

        int cgy = 0; // category
        ll sum = 0;
        vector<ll> tmp;
        for(int i = 1; i <= n; i++/*cout << "i= " << i++ << " cgy= " << cgy << endl*/){
            if(tmp.empty()){
                tmp.push_back(p[i]);
                sum = p[i] * p[i];
                cgy++;
                continue;
            }
            if(sum + p[i] * p[i] <= k){
                //printf("add: %lld\n", p[i]);
                sum += p[i] * p[i];
                tmp.push_back(p[i]);
            }
            else {
                ll newsum = work(tmp, p[i]);
                if(newsum < k){
                    tmp.push_back(p[i]);
                    sum = newsum;
                    continue;
                }
                else if(newsum > k){
                    tmp.clear();
                    sum = p[i] * p[i];
                    tmp.push_back(p[i]);
                    cgy++;
                }
                else {
                    tmp.clear();
                    sum = 0;
                }
            }
        }
        cout << cgy << endl;
    }

	return 0;
}