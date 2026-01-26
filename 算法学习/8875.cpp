#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
int n, x, frog[maxn], h[maxn];

inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

bool check(int len){
    int l = 0, r = 0;
    memset(frog, 0, sizeof(frog));
    h[n] = x;
    frog[0] = x;
    for(int i = 1; i <= n; i++){
        if(i - l >  len) return 0;
        while(l < i){
            int rm = h[i] - frog[i];
            if(rm >= frog[l]) {frog[i] += frog[l]; l++;}
            else {frog[i] = h[i]; frog[l] -= rm; break;}
        }
        //cout << "now i : " << i << endl;
        //cout << "frog[i]: " << frog[i] << " " << h[i] << endl;
    }
    return 1;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    x *= 2;
    for(int i = 1; i < n; i++) cin >> h[i];

    int l = 0, r = n;
    //cout << check(4) << endl;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
    


	return 0;
}
