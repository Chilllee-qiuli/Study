#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 44;
#define eps 1e-7
int t;

map<string, int> mp;
double a[maxn][maxn];

int gaosi(int n, int m);

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
    memset(a, 0, sizeof(a));
    int m;
    cin >> m; // 物质化学式个数，作为列数
    int tot = 0;
    mp.clear();
    for(int i = 1; i <= m; i++){
        string str;
        cin >> str;
        int dig = 0;
        string s;
        str += "#";
        for(int k = 0; k < str.size(); k++){
            char ch = str[k];
            if(ch == '#') break;
            if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) s += ch;
            else {
                int j = k;
                int dig = 0;
                while('0' <= str[j] && str[j] <= '9') dig = dig * 10 + str[j++] - '0';
                k = j - 1;
                if(!dig) dig = 1;
                if(mp[s]) a[mp[s]][i] = dig;
                else {
                    mp[s] = ++tot;
                    a[mp[s]][i] = dig;
                }
                s = "";
            }
        }
    }

    // for(int i = 1; i <= mp.size(); i++)
    // for(int j = 1; j <= m; j++)
    // cout << a[i][j] << " \n"[j == m];
    if(gaosi(mp.size(), m) == 2) return 1;
    else return 0;


}

int gaosi(int n, int m){
    int curi = 1; // 表示枚举哪一行，也是下一个主元要放的行号，等于主元个数+1
    for(int j = 1; j <= m && curi <= n; j++){ // 按列枚举
        // 1. 选主元：找到当前列j中，从行curi到n绝对值最大的行t
        int t = curi;
        for(int i = curi + 1; i <= n; i++)
            if(fabs(a[i][j]) > fabs(a[t][j])) // 找到这一列的最大非0元素，减少浮点误差
            t = i;

        // 2. 如果当前列全为0，跳过这一列
        if(fabs(a[t][j]) < eps) continue;  // 这一列没找到非零主元

        // 3. 交换行t和行curi（从列j开始交换，前面的列已处理）
        for (int k = j; k <= m; k++)  // 把非0元素所在行交换到当前行
        swap(a[t][k], a[curi][k]);

        // 4. 主元归一：将行curi的主元位置变为1（倒序避免主元被提前修改）
        for(int k = m; k >= j; k--) // 主元归一，其他的也要相对应除以主元位 
            a[curi][k] /= a[curi][j]; // 注意要倒着写，比较巧

        // 5. 消去其他所有行的第j列（包括上面的行，直接得到行最简形）
        for(int i = 1; i <= n; i++) // 用当前主元行 curi，把其他所有行 i 的第 j 列消成 0。
            if(i != curi && fabs(a[i][j]) > eps ) // 只消去非零行
            for(int k = m; k >= j; k--) // 注意要倒着写，比较巧
                a[i][k] -= a[curi][k] * a[i][j];

        curi++; // 主元个数+1，下一个主元放在下一行

    }
    
    // 7. 根据主元个数判断解的情况
    curi--; // ccuri 等于主元个数加1，因为它维护的是当前在哪行找新的主元
    if (curi == m) {
        return 1;  // 主元个数=未知数个数，唯一解0
    } else {
        return 2;  // 主元个数<未知数个数，无穷多解
    }
}