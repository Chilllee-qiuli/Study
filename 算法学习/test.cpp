<<<<<<< Updated upstream
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int> 
#define mk make_pair
#define fi first 
#define se second
int n, m, k;

const int maxn = 1e5 + 10;
pr a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n, [](pr x, pr y){
        return x.first > y.fi;
    }); // 按照每块田原本的需要时间降序

    ll tmp = 0;
    a[0].fi = a[1].fi;
    a[n + 1].fi = k;
    for(int i = 1; i <= n + 1; i++){
        tmp += a[i].se; // 记录前面所有田降低1单位的代价

        if(a[i].fi != a[i + 1].fi){
            int cur = a[i].fi;
            int nxt = max(a[i + 1].fi, k);

            ll diff = cur - nxt; // 记录当前能降低的最大差值
            ll cost = diff * tmp;

            if(m >= cost){
                m -= cost;
                if(nxt == k){
                    cout << k << endl;
                    return 0;
                }
            }
            else{
                cout << cur - m / tmp << endl;
                return 0;
            }
        }
    }
    cout << k << endl;

	return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/types.h>

int flag_int = 0;     // 收到 SIGINT 的标志
int flag_tstp = 0;    // 收到 SIGTSTP 的标志


void handler(int sig){
    if (sig == SIGINT) flag_int = 1;
    if (sig == SIGTSTP) flag_tstp = 1;
}

void run(char *name){
    int prio;
    int policy;

    signal(SIGINT, handler);
    signal(SIGTSTP, handler);

    while (1) {
        prio = getpriority(PRIO_PROCESS, 0);

        // SIGINT，优先数加 1
        if (flag_int == 1) {
            flag_int = 0;
            setpriority(PRIO_PROCESS, 0, prio + 1);
            printf("%s receive SIGINT, priority + 1\n", name);
        }

        // SIGTSTP，优先数减 1
        if (flag_tstp == 1) {
            flag_tstp = 0;
            setpriority(PRIO_PROCESS, 0, prio - 1);
            printf("%s receive SIGTSTP, priority - 1\n", name);
        }

        prio = getpriority(PRIO_PROCESS, 0);
        policy = sched_getscheduler(0);

        printf("%s: pid = %d, ppid = %d, priority = %d, policy = ", name, getpid(), getppid(), prio);

        if (policy == SCHED_OTHER)  printf("SCHED_OTHER");
        else if (policy == SCHED_FIFO)  printf("SCHED_FIFO");
        else if (policy == SCHED_RR)  printf("SCHED_RR");
        else  printf("UNKNOWN");

        printf("(%d)\n", policy);

        sleep(2); // ！
    }
}

int main(){

    int pid = fork();

    if (pid < 0) {
        printf("fork error!\n");
        exit(1);
    }

    if (!pid) run("child ");
    else run("parent");
  
    return 0;
}
>>>>>>> Stashed changes
