// Exponenciacao binaria
// Calcula (base ^ expo) % m
// Complexidade: O(log(expo))
// Fonte: cp-algorithms

int fexp(int base, int expo, int m = MOD) {
  int ans = 1;
  while(expo) {
    if(expo & 1) ans = ans * base % m;
    base = base * base % m;
    expo >>= 1;
  }
  return ans;
}
