// Crivo de Eratostenes Linear
// Calcula o menor fator primo (lp) de cada numero no intervalo [2, MAXN]
// Util para fatoracoes rapidas em O(log x) por numero
// Complexidade do crivo: O(n)
// Fonte: cp-algorithms

const int MAXN = 2e5;
vector<int> lp(MAXN + 1);
vector<int> primes;

void linear_sieve() {
  for(int i = 2; i <= MAXN; i++) {
    if(lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for(int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && i * primes[j] <= MAXN; j++) {
      lp[i * primes[j]] = primes[j];
    }
  }
}

// Retorna os fatores primos (com repeticoes), em O(log x)
vector<int> factorize(int x) {
  vector<int> ret;
  while(x > 1) {
    ret.push_back(lp[x]);
    x /= lp[x];
  }
  return ret;
}
