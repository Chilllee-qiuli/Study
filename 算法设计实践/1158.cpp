#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void matrix_mul(const int A[], const int B[], int C[], int m, int n, int p) {
  // TODO
  for(int i = 0; i < m; i++)
  for(int k = 0; k < p; k++)
  for(int j = 0; j < n; j++)
    C[i * p + k] += A[i * n + j] * B[j * p + k];
  
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}