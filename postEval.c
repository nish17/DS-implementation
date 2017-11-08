#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stackFunctions.h" 

int evaluatePostfix(char* exp){
  struct Stack* stack = createStack(strlen(exp));
  int i;
  if (!stack) return -1;
  for (i = 0; exp[i]; ++i){
    if (isdigit(exp[i])) push(stack, exp[i] - '0');
    else{
      int val1 = pop(stack);
      int val2 = pop(stack);
      switch (exp[i]){
        case '+': push(stack, val2 + val1); break;
        case '-': push(stack, val2 - val1); break;
        case '*': push(stack, val2 * val1); break;
        case '/': push(stack, val2/val1);   break;
      }
    }
  }
  return pop(stack);
}
int main(){
    char exp[] = "462/-6+";
    printf ("Value of %s is %d\n", exp, evaluatePostfix(exp));
    return 0;
}