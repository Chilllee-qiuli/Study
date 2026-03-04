#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

struct Large
{
    vector<int> num; // low -> high
    int len;
    Large(ll x = 0)
    {
        num.clear();
        if (!x)
            num.push_back(0);
        while (x)
            num.push_back(x % 10), x /= 10;
        len = num.size();
    }
    inline void trim()
    {
        while (len > 1 && num[len - 1] == 0)
            len--;
        if (num.size() != len)
            num.resize(len);
    }
    Large operator=(const Large &b)
    {
        num = b.num;
        len = b.len;
        return *this;
    }
    Large operator+(ll x) const
    {
        return *this + Large(x);
    }
    Large operator+(const Large &b) const
    {
        Large res;
        res.num.assign(max(len, b.len) + 1, 0);
        res.len = res.num.size();
        int c = 0;
        for (int i = 0; i < res.len; i++)
        {
            int s = c + (i < len ? num[i] : 0) + (i < b.len ? b.num[i] : 0);
            res.num[i] = s % 10;
            c = s / 10;
        }
        res.trim();
        return res;
    }
    Large operator*(int x) const
    {
        // 只能写big = big * x
        // 不能写big *= x，因为big *= x用的是operator*=
        // 不能写big = x * big，因为没有重载operator*（int, Large）
        Large res;
        res.num.assign(len + 10, 0);
        res.len = len;
        ll c = 0;
        for (int i = 0; i < len; i++)
        {
            ll v = 1LL * num[i] * x + c;
            res.num[i] = v % 10;
            c = v / 10;
        }
        while (c)
            res.num[res.len++] = c % 10, c /= 10;
        res.num.resize(res.len);
        res.trim();
        return res;
    }

    Large operator*(const Large &b) const
    {
        Large res;
        res.num.assign(len + b.len + 1, 0);
        res.len = (int)res.num.size();
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                res.num[i + j] += num[i] * b.num[j];
        for (int i = 0; i + 1 < res.len; i++)
            res.num[i + 1] += res.num[i] / 10, res.num[i] %= 10;
        res.trim();
        return res;
    }

    Large operator/(int x) const
    {
        Large res;
        res.num.assign(len, 0);
        res.len = len;
        int rem = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            rem = rem * 10 + num[i];
            res.num[i] = rem / x;
            rem %= x;
        }
        res.trim();
        return res;
    }

    bool operator<(const Large &b) const
    {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (num[i] != b.num[i])
                return num[i] < b.num[i];
        return false;
    }

    void print() const
    {
        for (int i = len - 1; i >= 0; i--)
            cout << num[i];
        cout << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    ll m = sqrt(n) - 1;
    Large L(m);
    L = L * (L * 2 + 1) * (L + 1) / 3 + (L + 1) * L / 2;
    // L.print();
    m++;

    L = L + (n - m * m + 1) * m;

    L.print();

    return 0;
}
