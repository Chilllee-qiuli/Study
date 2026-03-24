#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;


int solve(){
    for(int i = 5; i <= 2 * n; i += 2){
        printf("? %d %d\n", i, i + 1);fflush(stdout);
        int x;
        scanf("%d", &x);
        if(x == 1) return i;
    }
    int x;

    printf("? 1 2\n");fflush(stdout);
    scanf("%d", &x);
    if(x == 1) return 1;

    printf("? 1 3\n");fflush(stdout);
    scanf("%d", &x);
    if(x == 1) return 1;

    printf("? 2 3\n");fflush(stdout);
    scanf("%d", &x);
    if(x == 1) return 2;
    return 4;
}


int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        printf("! %d\n", solve());fflush(stdout);
    }

	return 0;
}
