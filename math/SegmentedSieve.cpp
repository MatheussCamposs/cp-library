// Crivo de Eratostenes Segmentado
// Executa o crivo em blocos de tamanho S para melhor uso de cache
// Complexidade: O(N log log N), com constante menor que o crivo tradicional
// Fonte: cp-algorithms

// Conta a quantidade de primos até N
int count_primes(int n) {
  const int S = 10000;
  int root = sqrt(n);
  vector<char> bs(root + 1, true);
  vector<int> primes;
  for(int i = 2; i <= root; i++) {
    if(!bs[i]) continue;
    primes.push_back(i);
    for(int j = i * i; j <= root; j += i) bs[j] = false;
  }
  int ret = 0;
  vector<char> block(S);
  for(int k = 0; k * S <= n; k++) {
    fill(block.begin(), block.end(), true);
    int st = k * S;
    for(int p : primes) {
      int stid = (st + p - 1) / p;
      int j = max(stid, p) * p - st;
      while(j < S) {
        block[j] = false;
        j += p;
      }
    }
    if(k == 0) block[0] = block[1] = false;
    for(int i = 0; i < S && st + i <= n; i++) {
      ret += block[i];
    }
  }
  return ret;
}

// Retorna vetor booleano de primalidade no intervalo [low, high]
// Requer que (high - low + 1) seja pequeno (cabe em memoria)
// upper_bound (high) pode ser ate 1e12
vector<char> primes_in_range(int low, int high) {
  int root = sqrt(high);
  vector<char> bs(root + 1, true);
  vector<int> primes;
  for(int i = 2; i <= root; i++) {
    if(!bs[i]) continue;
    primes.push_back(i);
    for(int j = i * i; j <= root; j += i) bs[j] = false;
  }
  vector<char> isprime(high - low + 1, true);
  for(int p : primes) {
    for(long long i = max(1LL * p * p, (1LL * low + p - 1) / p * p); i <= high; i += p) {
      isprime[i - low] = false;
    }
  }
  if(low == 1) isprime[0] = false;
  return isprime;
}
