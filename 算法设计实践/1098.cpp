#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10010;
int a[maxn], b[maxn];
int c[maxn];


int main(){
    freopen("1.in", "r", stdin);
    //freopen("t08.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string x, y;
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());


    for(int i = 0; i < x.size(); i++) 
        a[i] = x[i] - '0';
    for(int i = 0; i < y.size(); i++)
        b[i] = y[i] - '0';
    
    int tmp = 0;
    for(int i = 0; i < max(x.size(), y.size()); i++){
        tmp += a[i] + b[i];
        c[i] = tmp % 10;
        tmp /= 10;
    }
    if(tmp) c[max(x.size(), y.size())] = tmp;
    int flag = 0;
    for(int i = 10000; i >= 0; i--){
        if(c[i] || flag){
            flag = 1;
            cout << c[i];
        }
    }
    if(!flag) cout << 0 << endl;



	return 0;
}