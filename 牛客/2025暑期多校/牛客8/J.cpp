#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// ====================== 高精度工具函数 ======================
// 移除前导零
string removeLeadingZeros(string a) {
    int start = 0;
    while (start < a.size() - 1 && a[start] == '0') start++;
    return a.substr(start);
}

// 高精度加法 (处理非负数)
string add(string a, string b) {
    if (a.empty()) a = "0";
    if (b.empty()) b = "0";
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    int n = a.size(), m = b.size();
    int len = max(n, m) + 1;
    string res(len, '0');
    int carry = 0;
    
    for (int i = 0; i < len; i++) {
        int digitA = (i < n) ? a[n-1-i] - '0' : 0;
        int digitB = (i < m) ? b[m-1-i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        res[len-1-i] = '0' + (sum % 10);
    }
    
    return removeLeadingZeros(res);
}

// 高精度减法 (a >= b, 非负数)
string sub(string a, string b) {
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    int n = a.size(), m = b.size();
    string res(n, '0');
    int borrow = 0;
    
    for (int i = 0; i < n; i++) {
        int digitA = a[n-1-i] - '0' - borrow;
        int digitB = (i < m) ? b[m-1-i] - '0' : 0;
        borrow = 0;
        
        if (digitA < digitB) {
            digitA += 10;
            borrow = 1;
        }
        res[n-1-i] = '0' + (digitA - digitB);
    }
    
    return removeLeadingZeros(res);
}

// 高精度乘法 (朴素实现)
string mul(string a, string b) {
    if (a == "0" || b == "0") return "0";
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i+j+1] += (a[i]-'0') * (b[j]-'0');
        }
    }
    
    for (int i = n+m-1; i > 0; i--) {
        if (res[i] >= 10) {
            res[i-1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    
    string result;
    for (int i = 0; i < n+m; i++) {
        if (i == 0 && res[i] == 0) continue;
        result += '0' + res[i];
    }
    
    return removeLeadingZeros(result);
}

// 高精度乘单精度
string mul(string a, int b) {
    if (b == 0) return "0";
    string res;
    int carry = 0;
    
    for (int i = a.size()-1; i >= 0; i--) {
        int product = (a[i]-'0') * b + carry;
        carry = product / 10;
        res = char('0' + (product % 10)) + res;
    }
    
    if (carry) res = char('0' + carry) + res;
    return res;
}

// 高精度除以单精度
string div(string a, int b) {
    string res;
    int remainder = 0;
    
    for (char c : a) {
        int num = remainder * 10 + (c - '0');
        res += '0' + (num / b);
        remainder = num % b;
    }
    
    res = removeLeadingZeros(res);
    return res.empty() ? "0" : res;
}

// 高精度取模单精度
int mod(string a, int b) {
    int res = 0;
    for (char c : a) {
        res = (res * 10 + (c - '0')) % b;
    }
    return res;
}

// ====================== 负数除法核心 ======================
pair<string, int> div_minus2(string num) {
    if (num == "0") return {"0", 0};
    
    bool negative = (num[0] == '-');
    if (negative) num = num.substr(1);
    
    int last_digit = num.back() - '0';
    int remainder = last_digit & 1;  // 取模结果
    
    string adjusted = num;
    if (remainder) {
        if (!negative) {
            adjusted = sub(num, "1");
        } else {
            adjusted = add(num, "1");
        }
    }
    
    string quotient = div(adjusted, 2);
    if (negative) {
        if (remainder) {
            quotient = add(quotient, "1");
        }
    } else {
        quotient = "-" + quotient;
    }
    
    return {quotient, remainder};
}

// ====================== 核心数据结构 ======================
struct Node {
    string a, b;
    Node(string a_ = "0", string b_ = "0") : a(a_), b(b_) {}
};

// ====================== 转换函数 ======================
Node trans(string x) {
    Node now;
    if (x[0] == '1') now.a = "1";
    
    string tmp = "1";
    for (int i = 1; i < x.size(); i++) {
        if (i % 2 == 0) {
            tmp = mul(tmp, -2);
        }
        
        if (x[i] == '1') {
            if (i % 2 == 1) {
                now.b = add(now.b, tmp);
            } else {
                now.a = add(now.a, tmp);
            }
        }
    }
    return now;
}

// ====================== 主函数 ======================
int main() {
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        string A, B;
        cin >> A >> B;
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        
        Node a_node = trans(A);
        Node b_node = trans(B);
        Node c_node;

        // 复数乘法: (a + bi) * (c + di) = (ac - 2bd) + (ad + bc)i
        string term1 = mul(a_node.a, b_node.a);
        string term2 = mul("2", mul(a_node.b, b_node.b));
        string term3 = mul(a_node.a, b_node.b);
        string term4 = mul(a_node.b, b_node.a);
        
        c_node.a = sub(term1, term2);  // 实部
        c_node.b = add(term3, term4);  // 虚部

        string ans = "";
        int cnt = 0;
        
        while (c_node.a != "0" || c_node.b != "0") {
            int remainder;
            if (cnt % 2 == 0) {  // 处理实部
                auto res = div_minus2(c_node.a);
                c_node.a = res.first;
                remainder = res.second;
            } else {  // 处理虚部
                auto res = div_minus2(c_node.b);
                c_node.b = res.first;
                remainder = res.second;
            }
            
            ans += (remainder == 0) ? '0' : '1';
            cnt++;
            
            // 防止过深递归
            if (ans.size() > 200000) {
                ans = "";
                break;
            }
        }
        
        reverse(ans.begin(), ans.end());
        if (ans.empty()) ans = "0";
        if (ans.size() > 200000) ans = "ERROR";  // 安全处理
        
        cout << ans << endl;
    }
    
    return 0;
}
