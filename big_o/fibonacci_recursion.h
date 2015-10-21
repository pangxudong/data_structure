
//f(0) = f(1) = 1
int fibonacci_recursion(int n) {
  if (n==0 || n==1){
    return 1;
  }
  else {
    return fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
  }
}