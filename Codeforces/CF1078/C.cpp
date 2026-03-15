#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
bitset<30> a[maxn];
int t;
int n, k;
string ans;

bool check(int d){
    // 对每个长为 d 的周期，做按位与，得到一个 vector<bitset<30>>
    // vc[i] 表示每个周期内第 i 个位置上有哪些字符在每个周期都出现过
    vector<bitset<30>> vc(d + 1); 
    // 用第一个周期初始化
    for(int len = 1; len <= d; len++) vc[len] = a[len];

    // 对 i, (d + i), (2d + i), ... 做按位与
    for(int j = d + 1; j <= n; j++)
        vc[(j - 1) % d + 1] &= a[j];

    // 如果存在一个周期内的某个位置上没有字符在每个周期都出现过，那么就不合法
    for(int j = 1; j <= d; j++)
        if(vc[j].none()) return false;

    // 取周期内都出现的字符还原出可以循环构造整个原串的子串 ans
    ans.clear();
    for(int j = 1; j <= d; j++){
        for(int ch = 0; ch < 26; ch++){
            if(vc[j].test(ch)){
                ans += char('a' + ch);
                break;
            }
        }
    }
    return true;
}

void solve(){
    vector<int> divs;
    // 枚举 n 的所有约数 d，检查是否存在一个长度为 d 的周期满足条件
    // ！！特别值得注意的是，枚举 n 的约数只需要枚举到 sqrt(n)，每找到一个约数 i 就可以得到两个约数 i 和 n / i
    // 于是枚举一个数的所有可能约数的时间复杂度 d(n) 是 O(sqrt(n)) 的，而不是 O(n) 的
    for(int i = 1; i * i <= n; i++){ 
        // ！！一定要写成i * i <= n，而不是i <= sqrt(n)，因为精度问题可能导致漏掉一个约数
        if(n % i == 0){
            divs.push_back(i);
            if(i * i != n) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    for(int d : divs) if(check(d)) return; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            a[i].reset();
        ans = "";
        for (int i = 1; i <= k; i++)
        {
            string s;

            cin >> s;
            for (int j = 0; j < s.length(); j++)
            {
                int x = s[j] - 'a';
                a[j + 1].set(x, 1);
            }
        }
        solve();
        string aans = "";
        while (aans.length() < n)
            aans += ans;
        cout << aans << endl;
    }

    return 0;
}
