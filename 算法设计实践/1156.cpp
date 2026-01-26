#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 * 评测环境已经实现了归并函数，你需要调用该函数完成归并操作。
 * 数组a、长度n。数组b、长度m。归并到目标数组w。
 */
void merge(const int a[], const int n, const int b[], const int m, int w[]);

/**
 * 对整型区间[b, e)进行归并排序。区间为左闭右开，不含右端点。
 * 指针b为区间开始位置，指针e为区间结束位置。
 * w[]为调用方提供的工作数组，容量保证不小于(e - b)。
 */

void merge_sort(int* b, int* e, int w[]) {
  // TODO
  int len = (e - b);
  if(len <= 1) return ;
  int* mid = b + (len >> 1);
  merge_sort(b, mid, w);
  merge_sort(mid, e, w);
  //int a[mid - b], b[e - mid];
  //copy(a, b, mid);
  //copy(b, mid,  e);
  merge(b, mid - b, mid, e - mid, w);
  for (int i = 0; i < len; ++i) b[i] = w[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}