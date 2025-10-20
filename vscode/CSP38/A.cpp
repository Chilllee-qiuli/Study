#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> k;
    while(k--)
{
    int a, b, c;
    cin >> a >> b >> c;
    int m = 100 * (c - a) / b;
    int ansx = m / 10;
    int ansy = m ;
    ansy %= 10;
    ansy++;
    ansx++;
    cout << ansx << " " << ansy << endl;
    //cout << m << endl;
}
    return 0;
}
