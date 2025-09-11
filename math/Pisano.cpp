// Calcula um valor divisivel pelo periodo de Pisano(m)
// Complexidade: O(sqrt(m)) devido a fatorização
 
int pisano(int m) {
  int res = 1;
  for(int p = 2; p * p <= m; p++) {
    int e = 0, power = 1;
    while(m % p == 0) {
      m /= p;
      power *= p;
      e += 1;
    }
    if(e) {
      power /= p;
      if(p == 2) {
        if(e == 1) res = lcm(res, 3);
        else if(e == 2) res = lcm(res, 6);
        else res = lcm(res, 3 * power);
      }
      else if(p == 5) res = lcm(res, 20 * power);
      else {
        if(p % 10 == 1 or p % 10 == 9) res = lcm(res, (p - 1) * power);
        else res = lcm(res, (2 * (p + 1)) * power);
      }
    }
  }
  if(m != 1) {
    if(m == 2) res = lcm(res, 3);
    else if(m == 5) res = lcm(res, 20);
    else {
      if(m % 10 == 1 or m % 10 == 9) res = lcm(res, m - 1);
      else res = lcm(res, 2 * (m + 1));
    }
  }
  return res;
}
