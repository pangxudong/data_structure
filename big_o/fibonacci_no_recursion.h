
//f(0) = f(1) = 1
int fibonacci_no_recursion(int n) {
  if (n==0 || n==1){
    return 1;
  }
  else {
    int p = 1;
    int q = 1;
    for (int i = 2; i <= n; ++i){
      int temp = q;
      q = p + q;
      p = temp;
    }
    return q;
  }
}