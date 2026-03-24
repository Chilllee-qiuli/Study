#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t;
string s1, s2;
int u = 0;

char find(char x, char y){ // 找一个都不一样的char
    for(char ch = 'a'; ch <= 'z'; ch++)
    if(ch != x && ch != y){
        return ch;
    }
    return x;
}

void work(){
    string ans;
    int need = 2 * t - u;   // 在 s1!=s2 的位置中，需要放多少个“第三字符”
    int a = u - t;          // 需要放多少个 s1
    int b = u - t;          // 需要放多少个 s2

    for(int i = 0; i < n; i++){
        if(s1[i] == s2[i]){
            ans += s1[i];
        }
        else{
            if(a){
                ans += s1[i];
                a--;
            }
            else if(b){
                ans += s2[i];
                b--;
            }
            else{
                ans += find(s1[i], s2[i]);
                need--;
            }
        }
    }
    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> t;
    cin >> s1 >> s2 ;
    for(int i = 0; i < n; i++)
        if(s1[i] != s2[i])u++;
    
    if(u > 2 * t) {
        cout << "-1\n";
        return 0;
    }
    if(u > t){
        work();
        return 0;
    }

    string ans ;
    t -= u;
    for(int i = 0; i < n; i++)
        if(s1[i] == s2[i]) {
            if(!t) ans += s1[i];
            else {
                t--;
                ans += find(s1[i], s2[i]);                
            }
        }
        else ans += find(s1[i], s2[i]); 
        

    cout << ans << "\n";
    



    return 0;
}