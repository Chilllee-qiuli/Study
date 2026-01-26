#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 7;

struct Node{
    int lf, rt;
    int val;
};

struct Lst{
    Node node[maxn];
    int siz = 0;
    int head = 0;
    int tail = maxn - 10;
    int idx = 1; 

    Lst() {
        head = 0;
        tail = maxn - 10;
        node[head].rt = tail;
        node[tail].lf = head;
        idx = 1;
    }

    void insert(int val){
        int pos = head;
        // 找到插入位置pos
        while(node[pos].rt != tail && node[node[pos].rt].val < val){
            pos = node[pos].rt;
        }
        
        int newIdx = idx++;
        node[newIdx].val = val;
        node[newIdx].lf = pos;
        node[newIdx].rt = node[pos].rt;

        node[pos].rt = newIdx;
        node[node[newIdx].rt].lf = newIdx;
        
        siz++;
    }

    void print(){
        if(siz == 0){
            cout << "(nul)" << endl;
            return;
        }
        
        int pos = node[head].rt;
        while(pos != tail){
            cout << node[pos].val;
            if(node[pos].rt != tail) cout << ",";
            pos = node[pos].rt;
        }
        cout << endl;
    }

    void merge(const Lst& y){
        int posx = node[head].rt;
        int posy = y.node[y.head].rt;
        
        Lst newList;
        
        while(posx != tail && posy != y.tail){
            if(node[posx].val <= y.node[posy].val){
                newList.insert(node[posx].val);
                posx = node[posx].rt;
            } else {
                newList.insert(y.node[posy].val);
                posy = y.node[posy].rt;
            }
        }
        
        while(posx != tail){
            newList.insert(node[posx].val);
            posx = node[posx].rt;
        }
        
        while(posy != y.tail){
            newList.insert(y.node[posy].val);
            posy = y.node[posy].rt;
        }
        
        *this = newList;
    }

    void remove(int val){
        int pos = node[head].rt;
        while(pos != tail){
            if(node[pos].val == val){
                node[node[pos].lf].rt = node[pos].rt;
                node[node[pos].rt].lf = node[pos].lf;
                siz--;
                return ;
            }
            pos = node[pos].rt;
        }
    }

    int find(int val){
        int pos = node[head].rt;
        int position = 1;
        while(pos != tail){
            if(node[pos].val == val){
                return position;
            }
            pos = node[pos].rt;
            position++;
        }
        return 0;
    }
};

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int x;
    Lst lsta, lstb;
    cout << "input1" << endl;

    while(cin >> x){
        if(x == 0) break;
        lsta.insert(x);
    }
    cout << "output1" << endl;
    lsta.print();

    cout << "input2" << endl;
    
    while(cin >> x){
        if(x == 0) break;
        lstb.insert(x);
    }
    cout << "output2" << endl;
    lstb.print();

    cout << "mergence" << endl;
    
    Lst merged = lsta;
    merged.merge(lstb);
    merged.print();
    
    cout << "insert" << endl;

    cin >> x;
    merged.insert(x);

    cout << "insertion" << endl;

    merged.print();

    cout << "delete" << endl;
    
    cin >> x;
    merged.remove(x);
    cout << "deletion" << endl;

    merged.print();

    cout << "find" << endl;
    cin >> x;
    int pos = merged.find(x);

    cout << "position" << endl;
    if(pos > 0)  cout << pos << endl;
    else cout << 0 << endl;

    cout << "end" << endl;
    

    return 0;
}
