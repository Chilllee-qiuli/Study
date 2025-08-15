
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e4+10;
bitset<maxn> s[maxn];
bitset<maxn> tmp;
int n, m, q;

inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

int main(){
    cin >> n >> m >> q;
    for(int i=1, c; i<=n; i++){
        c = read();
        while(c--){
            int si = read();
            s[i].set(si-1);
        }
    }
    for(int i=0; i < m; i++) s[0].set(i);
    for(int o, x, y; q; q--){
        cin >> o >> x >> y;
        if(o == 1){
            s[x] <<= y;
            s[x] &= s[0];
        }
        else if(o == 2){
            s[x] >>= y;

        }
        else if(o == 3) printf("%d\n", (s[x] & s[y]).count());          
        else if(o == 4) printf("%d\n", (s[x] | s[y]).count());
        else printf("%d\n", (s[x] ^ s[y]).count());
    }


	return 0;
}