#include <stdio.h>
int IsValid(char identity[]);
int main() {
  char identity[10];
  scanf("%s", identity);
  printf(IsValid(identity)?"real":"fake");
  return 0;
}

int IsValid(char identity[]){
  int city[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33};
  int number[10], ans = 0;

  for(int j = 0; j < 26; j++){
    if (identity[0] == 'A'+ j){
      number[0] = city[j-1];
    }
  }
  for(int i = 1; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if (identity[i] == '0'+ j){
        number[i] = j;
      }
    }
  }
  ans = number[0]/10 + number[0]%10*9 + number[9];
  for(int i = 1; i < 9; i++){
    ans += number[i]*(9 - i);
  }
  if(ans % 10 == 0) return 1;
  else return 0;
}