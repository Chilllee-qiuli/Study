#include <stdio.h>
long long  income_tax(long long  p) {
  long long d = 0, f = 0;
  p -= 60000 + d;

  if(p <= 0) return 0;
  if(p <= 36000) return  p * 0.03 ;
  if(p <= 144000) return 1080 + (p - 36000) * 0.1 ;
  if(p <= 300000) return 11880 + (p - 144000) * 0.2 ;
  if(p <= 420000) return 43080 + (p - 300000) * 0.25 ;
  if(p <= 660000) return 73080 + (p - 420000) * 0.3  ;
  if(p <= 960000) return 145080 + (p - 660000) * 0.35 ;
  return 250080 + (p - 960000) * 0.45;
}
int main(){
  long long T;
  scanf("%lld",&T);
  if(T == 0){
    printf("60000\n");
    return 0;
  }
  long long left = 60000;
  long long right = T * 100 / 3 + 60000;
  long long result = 0;
  while (left <= right){
    long long mid = left + (right - left) / 2;
    long long tax = income_tax(mid);
    if(tax <= T){
      result = mid;
      left = mid + 1;
    }else {
      right = mid - 1;
    }
  }
  printf("%lld",result);
  return 0;
}