//Combinatoria
//fatorial, inverso modular, choose e desarranjo
//Complexidade: O(n)

const int MAXN = 2e5;

mint fact[MAXN + 1];
mint inve[MAXN + 1];

void init() {
  fact[0] = 1;
  for(int i = 1; i <= MAXN; i++) {
    fact[i] = fact[i-1] * i;
  }
  inve[MAXN] = inverse(fact[MAXN]);
  for(int i = MAXN; i >= 1; i--) {
    inve[i-1] = inve[i] * i;
  }
}

mint choose(int n, int k) {
  if(k < 0 or k > n) return mint(0);
  return fact[n] * inve[k] * inve[n - k];
}

mint de[MAXN + 1];

void derangement(int n) {
  de[0] = 1;
  if(n >= 1) de[1] = 0;
  for(int i = 2; i <= n; i++) {
    d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
  }
}

