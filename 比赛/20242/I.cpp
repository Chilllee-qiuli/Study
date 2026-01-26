#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;

int main(){
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
 

    while(T--){
        
        cin >> n;
        ll gouzao = pow(2, 31);
        gouzao -= n;
        if(n == 0){
            cout << "NO" << endl;   
            continue;
        }
        int a[33], top = 0;
        while(gouzao){
            if(gouzao & 1) a[++top] = -1;
            else a[++top] = 0;
            gouzao /= 2;
        }
        int flag = 1;
        for(int i = 1; i <= 31; i++){
            if(a[i] == -1 && !a[i+1]){
                a[i] = 1; a[i+1] = -1;
            }
        }
        for(int i = 2; i <= 31; i++)
            if(!a[i] && !a[i-1]) flag = 0;
        

        if(flag){
            cout << "YES" << endl;
            for(int i = 1; i <= 31; i++){
                cout << a[i] << " ";
                if(i % 8 == 0) cout << endl;
            }
            cout << 1 << endl;
        }
        else {
            gouzao = pow(2, 30);
            gouzao -= n;
            top = 0;
            while(gouzao){
                if(gouzao & 1) a[++top] = -1;
                else a[++top] = 0;
                gouzao /= 2;
            }
            int flag = 1;
            for(int i = 1; i <= 31; i++){
                if(a[i] == -1 && !a[i+1]){
                    a[i] = 1; a[i+1] = -1;
                }
            }
            for(int i = 2; i <= 30; i++)
                if(!a[i] && !a[i-1]) flag = 0;
            if(flag){
                cout << "YES" << endl;
                for(int i = 1; i <= 30; i++){
                    cout << a[i] << " ";
                    if(i % 8 == 0) cout << endl;
                }
                cout << 1 << " " << 0 << endl;
            }
            else cout << "NO" << endl;
        }

    }


	return 0;
}
