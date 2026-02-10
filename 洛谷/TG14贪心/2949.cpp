#include<bits/stdc++.h> // 反悔贪心
using namespace std;
typedef long long ll;
#define pr pair<int, int> 
#define mk make_pair
const int maxn = 1e5 + 10;
int n;
pr work[maxn];

priority_queue< int, vector<int>, greater<int> > qu;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> work[i].first >> work[i].second;

    sort(work + 1, work + 1 + n);

    ll cnt = 0;
    int num = 0;
    // cout << "test" << endl;


    for(int i = 1; i <= n; i++){
        if(1 + num > work[i].first){
            if(qu.top() < work[i].second){
                cnt -= qu.top();
                qu.pop();
                cnt += work[i].second;
                qu.push(work[i].second);
            }
        }
        else {
            qu.push(work[i].second);
            cnt += work[i].second;
            ++num;
        }
    // cout << "i: " << i << " nt " << cnt << endl;
    }

    cout << cnt << endl;




	return 0;
}
