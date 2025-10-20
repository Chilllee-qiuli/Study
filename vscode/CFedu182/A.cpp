#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[500];

bool check(int l, int r){
    int s1 = 0, s2 = 0, s3 = 0;
    for(int i = 1; i <= l; i++) s1 += a[i];
    for(int i = l + 1; i <= r; i++) s2 += a[i];
    for(int i = r + 1; i <= n; i++) s3 += a[i];
    s1 %= 3; s2 %= 3; s3 %= 3;
    if(s1 == s2 && s2 == s3) return 1;
    if(s1 != s2 && s2 != s3 && s1 != s3) return 1;
    return 0;
}

void print(int l, int r){
    cout << l << " " << r << endl;
}   

void work(){
    for(int l = 1; l < n; l++)
        for(int r = l + 1; r <= n; r++){
            if(check(l, r)){
                print(l, r);
                return;
            }
        }
    print(0, 0);
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        work();

    }

	return 0;
}