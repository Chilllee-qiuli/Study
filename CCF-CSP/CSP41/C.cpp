#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
#define pr pair<ll, ll>
#define mk make_pair
#define fi first 
#define se second
int n, q;
struct node{
    ll len;
    ll l, r;
    ll flag;
    int use;
};
vector<node> queues[maxn];
int R;
multiset<pr> mult;
int tot;

void merge(multiset<pr>::iterator){

    for(auto it = mult.begin(); it != mult.end() && next(it) != mult.end(); it++){
        auto it2 = next(it);
        if((*it).second == (*it2).first - 1){
            int l = (*it).fi, r = (*it2).se;
            mult.erase(it);
            mult.erase(it2);
            it = mult.insert(mk(l, r));
            it = prev(it);
        }
    }

    while(mult.size() && (*prev(mult.end())).second == R - 1){
        auto it = prev(mult.end());
        R = (*it).first;
        mult.erase(it);
    }
}


void ins(int p, ll len, int l, int r){
    // printf("p = %d, len = %d, l = %d, r = %d\n", p, len, l, r);
    queues[p].push_back({len, l, r, l, 0});
}

int nw(int p, ll len){
    ll nowlen = 0x3f3f3f3f;
    auto now = mult.end();
    for(auto it = mult.begin(); it != mult.end(); it++){
        int l = (*it).first, r = (*it).second;
        if(r - l + 1 == len){
            ins(p, len, l, l + len - 1);
            mult.erase(it);
            return l;
        }
        if(r - l + 1 > len && r - l + 1 < nowlen){
            nowlen = r - l + 1;
            now = it;
        }
    }
    if(now != mult.end()){
        int l = (*now).first, r = (*now).second;
        auto tmp = mult.insert(mk(l + len, r));
        mult.erase(now);
        merge(tmp);
        // addFree(l + len, r);
        ins(p, len, l, l + len - 1);
        return l;
    }
    
    ins(p, len, R, R + len - 1);
    R += len;    
    return R - len;
}
ll sd(int p){
    ll tmp = 0;
    for(int i = 0; i < queues[p].size(); i++){
        if(queues[p][i].use == -1) continue;
        tmp += queues[p][i].flag;
        queues[p][i].flag++;
        if(queues[p][i].flag > queues[p][i].r) queues[p][i].flag = queues[p][i].l;
    }
    return tmp;
}
void del(int p, int x){
    int cnt = 0;
    for(int i = 0; i < queues[p].size(); i++){
        if(queues[p][i].use == 0) cnt++;
        if(cnt == x){
            x = i;
            break;
        }
    }
    queues[p][x].use = -1;
    //  cout << "del: " << queues[p][x].l << " " << queues[p][x].r << "  "; 
    auto tmp = mult.insert(mk(queues[p][x].l, queues[p][x].r));
    merge(tmp);
    // addFree(queues[p][x].l, queues[p][x].r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("3.in", "r", stdin);
    // freopen("3.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= q; i++){
        string s;
        cin >> s;
        if(s == "new"){
            int l, p; cin >> p >> l; 
            // cout << "len=" << l <<  " new: " <<  nw(p, l) << endl;
            // cout << R << "=R " << nw(p, l) << " R=" << R << endl;
            cout << nw(p, l) << endl;
        }
        else if(s == "send"){
            int p;
            cin >> p;
            // cout << "sd: " << sd(p) << endl;
            cout << sd(p) << endl;
        }
        else {
            int p, x;
            cin >> p >> x;
            del(p, x);
            // cout << "delcom, R = " << R << endl;
        }
    }

	return 0;
}     