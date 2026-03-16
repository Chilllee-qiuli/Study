#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 44;
#define eps 1e-7
int t;

map<string, int> mp;
double a[maxn][maxn];
int n;

void gaosi();

bool work();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        if(work()) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}

bool work(){

    cin >> n;
    int tot = 0;
    mp.clear();
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        int dig = 0;
        string s;
        str += "#";
        for(auto ch : str){
            if('0' <= ch && ch <= '9') dig = dig * 10 + ch - '0';
            else {
                if(!mp[s]) mp[s] = ++tot;
                a[mp[s]][i] = dig;
                dig = 0;
                s = "";
            }
            if(ch == '#') break;
            s += ch;
        }
    }

}

void gaosi(){
    int curi = 1; // 表示枚举哪一行，也是下一个主元要放的行号
    for(int j = 1; j <= n; j++){ // 按列枚举
        int t;
        for(int i = curi + 1; i <= n; i++)
            if(fabs(a[i][j]) > fabs(a[t][j])) // 找到这一列的最大非0元素，减少浮点误差
            t = i;
        if(fabs(a[t][j]) < eps) continue;  // 这一列没找到非零主元
        for (int k = j; k <= n + 1; k++)  // 把非0元素所在行交换到当前行
        swap(a[t][k], a[curi][k]);

        for(int i = n + 1; i >= j; i--) // 主元归一，其他的也要相对应除以主元位
            a[curi][i] /= a[curi][j]; // 注意要倒着写，比较巧

        for(int i = 1; i <= n; i++) // 用当前主元行 curi，把其他所有行 i 的第 j 列消成 0。
            if(i != curi)
            for(int k = n + 1; k >= j; k--) // 注意要倒着写，比较巧
                a[i][k] -= a[curi][k] * a[i][j];

        curi++; // 这个是在干什么
    }
    if(curi <= n){ // 判断0 = !0
        for(int i = curi; i <= n; i++)
        if(fabs(a[i][n + 1]) > eps){ // 发现 0 = !0， 无解 
            return ;
        }
        // 发现无穷多解
    }
}