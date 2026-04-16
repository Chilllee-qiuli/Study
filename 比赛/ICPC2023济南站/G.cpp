#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int r, c;
vector<vector<int>> vc;
vector<int> cnt;
vector<int> fa;

void merge(int x, int)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> r >> c;
        vector<vector<int>>(r + 1, vector<int>(c + 1, 0)).swap(vc);
        vector<int>(c + 1, 0).swap(cnt);
        vector<int>(c + 1, 0).swap(fa);
        for(int i = 1; i <= (c + 1) / 2; i++) fa[i] = i;
        for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++){
            char ch;
            cin >> ch;
            vc[i][j] = ch - '0';
            cnt[min(j, c - j + 1)] += vc[i][j];
        }
        int flag = 1;
        for(int i = 0; i <= c / 2; i++)
            if(cnt[i] >= 3) flag = 0;
        if(c & 1 && cnt[(c + 1) / 2] >= 2) flag = 0;
        if(!flag){
            cout << 0 << endl;
            continue;
        }

        vector<int>(c + 1, 0).swap(cnt);
        for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            if(!vc[i][j]) continue;
            else if(cnt[min(j, c - j + 1)]){
                int x = j, y = cnt[min(j, c - j + 1)];
                if(x > y) swap(x, y);
                merge(x, y); 
            }
            else cnt[min(j, c - j + 1)] = j;
    }


	return 0;
}

