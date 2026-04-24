#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int Len = 2e6 + 10;


int n;
struct node{
    int son[27]; // 子节点边
    int cnt; // 记录匹配数
    int fail; // fail指针
    int in; // 入度
    void init(){
        memset(son, 0, sizeof(son));
        cnt = fail = 0;
    }
}tr[Len];

int tot;
int ans[Len];
int idx[maxn]; // 记录第 i 个串映射到trie上节点的编号
string s[maxn];

void init(){
    tot = 0;
    tr[0].init();
}

void insert(string s, int id){
    int p = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        int c = s[i] - 'a';
        if(!tr[p].son[c]) tr[p].son[c] = ++tot;
        p = tr[p].son[c];
    }
    // 由于有可能出现相同的模式串，需要将相同的映射到同一个编号
    idx[id] = p;
}

void build(){
    queue<int> q;
    // 注意先预处理边界，即根的周围节点
    // 如果有节点自然加入bfs去算fail，如果没有，那么要自然置0
    // 因为失配fail指针跳到0的时候，如果0也没有这个字符的边，那就干脆指向根，即0
    // 特别注意，根表示空串
    for(int i = 0; i < 26; i++)
        if(tr[0].son[i]) q.push(tr[0].son[i]);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 26; i++){
            if(tr[u].son[i]){  // 存在对应子结点
                int son = tr[u].son[i];
                tr[son].fail = tr[tr[u].fail].son[i]; // 只用跳一次 fail 指针
                tr[tr[tr[u].fail].son[i]].in++; // 入度计数
                q.push(tr[u].son[i]);  // 并加入队列
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];
            // !! 将不存在的字典树的状态链接到了失配指针的对应状态
        }
    }
}

void query(string s){
    int u = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        u = tr[u].son[s[i] - 'a'];
        tr[u].cnt++; 
        // 在文本串路径上标记经过的状态，路径上所有经过的模式串都在文本串上完整出现了
    }
}

void topu(){
    queue<int> q;
    for(int i = 0; i <= tot; i++)
        if(!tr[i].in) q.push(i);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans[u] = tr[u].cnt; // 记录该节点状态的答案
        int v = tr[u].fail;
        tr[v].cnt += tr[u].cnt;
        if (!--tr[v].in) q.push(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        insert(s[i], i);
        ans[i] = 0;
    }

    build(); // 构建失配树
    cin >> s[0];
    query(s[0]);
    topu();
    int cnt = 0;
    // for(int i = 1; i <= n; i++) cout << ans[idx[i]] << endl;
    for(int i = 1; i <= n; i++) cnt += (ans[idx[i]] > 0) ;
    cout << cnt << endl;

	return 0;
}