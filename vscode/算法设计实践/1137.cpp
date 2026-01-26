#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string rd; // read;

namespace stk{
    template<class T>
    class stack{
        vector<T> data;
    public :
        void push(const T& val) {data.push_back(val);}
        void pop() {if(!data.empty()) data.pop_back();}
        int size(){return data.size();}
        T& top() { return data.back(); } 
        bool empty() { return data.empty(); }
        void reverse(){std::reverse(data.begin(), data.end());} 
    };
}

int judge(char ch){
    if(ch == '^') return 2;
    else if(ch == '*' || ch == '/') return 1 ;
    else if('0' <= ch && ch <= '9') return -1;
    else return 0;
}
stk::stack<char> hz; // 后缀表达式
void turn(){
    stk::stack<char> op;
    // stk::stack<char> num;
    for(char ch : rd){
        if('0' <= ch && ch <= '9')  hz.push(ch);
        else if(ch == '(') op.push(ch);
        else if(ch == ')'){
            while(op.size() && op.top() != '(') {
                hz.push(op.top());
                op.pop();
            }
            if(!op.empty()) op.pop();
        }
        else {
            while( !op.empty() && op.top() != '(' ){
                int top_judge = judge(op.top());
                int ch_judge = judge(ch);
                if( top_judge > ch_judge || (ch_judge != 2 && top_judge == ch_judge) ){
                    hz.push(op.top());
                    op.pop();
                } else break;
            
            }
            op.push(ch); 
        }
    }
    while(op.size()){
        hz.push(op.top());
        op.pop();
    }
}

string str;

void hz_to_str(){
    hz.reverse();
    while(hz.size()){
        str += hz.top();
        hz.pop();
    }
}

struct node{
    int tag;
    char ch;
    ll x;
};
vector<node> vc;

void print(vector<node> tmp){
    for(int i = 0; i < tmp.size(); i++){
        if(tmp[i].tag == 1) cout << tmp[i].x ;
        else cout << tmp[i].ch;
        cout << " \n"[i == tmp.size() - 1];
    }
}

void work(){
    for(int i = 0; i < str.size(); i++)
    cout << str[i] << " \n"[i == str.size() - 1];
    
    for(int i = 0; i < str.size(); i++){
        if(judge(str[i]) == -1) vc.push_back({1, 1, str[i] - '0'});
        else vc.push_back({2, str[i], 0});
    }

    while(vc.size() > 1){
        vector<node> tmp;
        int flag = 0;
        for(int i = 0; i < vc.size(); i++)
            if(!flag && vc[i].tag == 2){
                ll a = vc[i - 1].x;
                ll b = vc[i - 2].x;
                tmp.pop_back();
                tmp.pop_back();
                swap(a, b);
                char ch = vc[i].ch;
                ll ans = 0;
                if(ch == '+') ans = a + b;
                if(ch == '-') ans = a - b;
                if(ch == '*') ans = a * b;
                if(ch == '/') ans = a / b;
                if(ch == '^') ans = pow(a, b);
                tmp.push_back({1, 1, ans});
                flag = 1;
            }
            else tmp.push_back(vc[i]);
        print(tmp);
        vc = tmp;
    }
} 


int main(){

    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> rd;
    turn();

    hz_to_str();
    work();

	return 0;
}