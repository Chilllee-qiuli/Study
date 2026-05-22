
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define BUFSZ 256

/* ── IPC 工具函数原型 ─────────────────────────────── */
int   get_ipc_id(char *proc_file, key_t key);
int   set_sem(key_t sem_key, int sem_val, int sem_flg);
int   down(int sem_id);
int   up(int sem_id);

/* ── 信号灯控制联合体 ─────────────────────────────── */
typedef union semuns {
    int val;
} Sem_uns;

/*
 * 抽烟者问题信号量键值分配：
 *
 *  供应者 → 抽烟者 的通知信号量（初值 0，同步）：
 *    OFFER1_KEY (401)：供应者放出 纸(P)+胶水(G)，通知 抽烟者3（有烟草T）
 *    OFFER2_KEY (402)：供应者放出 烟草(T)+胶水(G)，通知 抽烟者2（有纸P）
 *    OFFER3_KEY (403)：供应者放出 烟草(T)+纸(P)，  通知 抽烟者1（有胶水G）
 *
 *  抽烟者 → 供应者 的完成信号量（初值 0，同步）：
 *    FINISH_KEY (404)：任一抽烟者抽完后，通知供应者继续
 */
#define OFFER1_KEY  401
#define OFFER2_KEY  402
#define OFFER3_KEY  403
#define FINISH_KEY  404

/* 全局信号量 ID（各进程内各自持有） */
int offer1_sem;  // P+G 已放出，通知 抽烟者3
int offer2_sem;  // T+G 已放出，通知 抽烟者2
int offer3_sem;  // T+P 已放出，通知 抽烟者1
int finish_sem;  // 抽烟完成，通知供应者

int get_ipc_id(char *proc_file, key_t key)
{
    FILE *pf;
    int   i, j;
    char  line[BUFSZ], colum[BUFSZ];

    if ((pf = fopen(proc_file, "r")) == NULL) {
        perror("Proc file not open");
        exit(EXIT_FAILURE);
    }

    fgets(line, BUFSZ, pf);          /* 跳过表头行 */

    while (!feof(pf)) {
        i = j = 0;
        fgets(line, BUFSZ, pf);

        /* 解析第一列：key 值 */
        while (line[i] == ' ') i++;
        while (line[i] != ' ') colum[j++] = line[i++];
        colum[j] = '\0';

        if (atoi(colum) != key) continue;   /* key 不匹配，跳过 */

        /* 解析第二列：IPC id */
        j = 0;
        while (line[i] == ' ') i++;
        while (line[i] != ' ') colum[j++] = line[i++];
        colum[j] = '\0';

        fclose(pf);
        return atoi(colum);
    }

    fclose(pf);
    return -1;
}

/*
 * down() —— 信号量 P 操作（原子地将信号量值减 1，若结果 < 0 则阻塞）
 *
 * 参数：sem_id —— 由 semget 返回的信号灯数组 id
 *
 * SEM_UNDO：进程意外退出时内核自动恢复该操作，防止死锁。
 */
int down(int sem_id)
{
    struct sembuf buf;
    buf.sem_op  = -1;       /* P 操作 */
    buf.sem_num =  0;       /* 操作数组中第 0 个信号灯 */
    buf.sem_flg = SEM_UNDO;

    if ((semop(sem_id, &buf, 1)) < 0) {
        perror("down error");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

/*
 * up() —— 信号量 V 操作（原子地将信号量值加 1，若有阻塞进程则唤醒）
 */
int up(int sem_id)
{
    struct sembuf buf;
    buf.sem_op  =  1;       /* V 操作 */
    buf.sem_num =  0;
    buf.sem_flg = SEM_UNDO;

    if ((semop(sem_id, &buf, 1)) < 0) {
        perror("up error");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

/*
 * set_sem() —— 创建或获取一个信号灯（数组中含 1 个信号灯）
 *
 * 参数：
 *   sem_key  —— 信号灯的键值（唯一标识）
 *   sem_val  —— 若是新建，设置的初始值
 *   sem_flg  —— 权限位（如 IPC_CREAT | 0644）
 *
 * 逻辑：先查询 key 是否已存在于内核中，若已存在则直接取 id（不修改值）；
 *       若不存在则新建并设置初值。这保证多进程启动时初值只被设置一次。
 */
int set_sem(key_t sem_key, int sem_val, int sem_flg)
{
    int     sem_id;
    Sem_uns sem_arg;

    if ((sem_id = get_ipc_id("/proc/sysvipc/sem", sem_key)) < 0) {
        /* 信号量不存在，新建 */
        if ((sem_id = semget(sem_key, 1, sem_flg)) < 0) {
            perror("semaphore create error");
            exit(EXIT_FAILURE);
        }
        /* 设置初值 */
        sem_arg.val = sem_val;
        if (semctl(sem_id, 0, SETVAL, sem_arg) < 0) {
            perror("semaphore set error");
            exit(EXIT_FAILURE);
        }
    }
    return sem_id;
}
