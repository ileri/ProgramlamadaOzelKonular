unsigned long long fibo(int n){
  unsigned long long f[2] = {1,1};
  for(int i = 3; i <= n; i++){f[1] = f[0]+f[1];f[0]=f[1]-f[0];}
  return f[1];
}