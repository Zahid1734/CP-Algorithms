const int N = 1e5 + 1;
char sieve[N];
vector<int> primes;
void find_primes(int n) {
  sieve[0] = sieve[1] = 0;
  for (int i = 4; i <= n; i += 2) sieve[i] = 1;
  int sq = sqrt(n);
  for (int i = 3; i <= sq; i++) {
      if (sieve[i] == 0) {
          for (int j = i * i; j <= n; j += 2 * i) {
            sieve[j] = 1;
          }
      }
  }
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) if (sieve[i] == 0) primes.push_back(i);
}
