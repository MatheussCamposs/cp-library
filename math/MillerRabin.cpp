// Teste de Primalidade de Miller-Rabin
// Verifica se um numero e primo de forma probabilistica
// Funciona corretamente ate cerca de 2^64 para os witnesses escolhidos
// Complexidade: O(k * log^3 n), onde k e o numero de testes
// Fonte: cp-algorithms

bool check_composite(int n, int a, int d, int s) {
  int x = fexp(a, d, n);
  if(x == 1 || x == n - 1) return false;
  for(int r = 1; r < s; r++) {
    x = (__int128_t)x * x % n;
    if(x == n - 1) return false;
  }
  return true;
}

bool MillerRabin(int n) {
  if(n < 4) return n == 2 || n == 3;
  int d = n - 1, r = 0;
  while((d & 1) == 0) {
    d >>= 1;
    r += 1;
  }
  for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if(n == a) return true;
    if(check_composite(n, a, d, r)) return false;
  }
  return true;
}
