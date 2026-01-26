#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        unsigned int n;
        cin >> n;
        if(n == 0u){
            cout << "YES\n";
            continue;
        }

        unsigned int tmp = n;
        int tz = 0;
        while((tmp & 1u) == 0u){
            tz++;
            tmp >>= 1u;
        }

        bool ok = false;
        for(int L = 0; L <= tz; ++L){
            unsigned int s = n >> L;
            // compute bit-length of s
            int len = 0;
            unsigned int t = s;
            while(t){ ++len; t >>= 1u; }
            // check palindrome
            bool pal = true;
            for(int i = 0; i < len/2; ++i){
                unsigned int bi = (s >> i) & 1u;
                unsigned int bj = (s >> (len - 1 - i)) & 1u;
                if(bi != bj){ pal = false; break; }
            }
            if(!pal) continue;
            // if odd length, middle bit must be 0
            if(len % 2 == 1){
                unsigned int mid = (s >> (len/2)) & 1u;
                if(mid == 1u) continue;
            }
            ok = true;
            break;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
