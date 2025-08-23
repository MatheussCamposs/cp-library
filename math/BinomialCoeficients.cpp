//Classe para combinatoria
//Calcula fatorial, inverso modular, choose e desarranjo
//Complexidade: O(n)

struct Combinatorics {
  int MOD, MAXN;
  vector<mint> fact, inve, d;

  Combinatorics(int maxn, int mod) : MOD(mod), MAXN(maxn), fact(maxn + 1), inve(maxn + 1), d(maxn + 1) {
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i;
    inve[MAXN] = fexp(fact[MAXN], MOD - 2);
    for(int i = MAXN; i >= 1; i--) inve[i - 1] = inve[i] * i;
  }

  mint choose(int n, int k) {
    if(k < 0 or k > n) return mint(0);
    return fact[n] * inve[k] * inve[n - k];
  }

  void derangement(int n) {
    d[0] = 1;
    if(n >= 1) d[1] = 0;
    for(int i = 2; i <= n; i++)
    d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
  }
};
