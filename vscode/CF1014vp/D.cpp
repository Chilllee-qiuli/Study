#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tt;
int n;
string str;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> tt;
    while(tt--){
        cin >> n;
        cin >> str;
        int flag = 0;
        int L = 0, I = 0, T = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == 'L') L++;
            else if(str[i] == 'I') I++;
            else if(str[i] == 'T') T++;
            if(i != 0 && str[i] != str[i - 1])flag = 1;
        }

        if(L == I && I == T) {cout << 0 << endl; continue;}
        if(n == 1 || !flag) {cout << -1 << endl; continue;}


        str = "1" + str;
        int lit = 'L'  ^ 'I' ^ 'T';
        vector<int> ans;
        map<int, int> mp;
        mp[(int)'L'] = L;
        mp[(int)'I'] = I;
        mp[(int)'T'] = T;
        for(int i = 2; i <= n; i++){
            int x = str[i - 1], z = str[i];
            if(x != z){
                int y = lit ^ x ^ z;
                int p = i - 1;
                ans.push_back (p);++mp[y];
                // 现在万能串构造为： x  y  z。  p 指向 x
                while(mp[(int)'L'] != mp[(int)'I'] || mp[(int)'I'] != mp[(int)'T'] || mp[(int)'T'] != mp[(int)'L']){
                    if(mp[x] > mp[z]) 
                    {
                        ans.push_back(p);
                        ++mp[z]; // xy之间插入z
                        swap(y, z);
                    }
                    else { // yz之间插入x
                        ans.push_back(++p);//万能串最左侧的位置右移
                        ++mp[x];
                        swap(x, y);
                    }
                }
                break;
            }

        }
        cout << ans.size() << endl;
        for (auto v : ans) cout << v << endl;


    }

	return 0;
}