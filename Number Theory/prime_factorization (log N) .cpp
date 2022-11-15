
const int N = 100005;
vector<int> spf(N);
vector<bool> sieve(N, 0);
vector<int> primes;
void smallest_prime() {
  spf[1] = 1;
  for (int i = 2; i < N; i += 2) spf[i] = 2, sieve[i] = 1;
  for (int i = 3; i < N; i += 2) {
    if (!sieve[i]) {
      spf[i] = i;
      for (long long j = (long long)i * i; j < N; j += 2 * i) {
        if (!sieve[j]) spf[j] = i, sieve[j] = 1 ;
      }
    }
  }
}

void prime_fact(int n) {
  if (n == 0 || n == 1) return ;
  while (n - 1) {
    primes.push_back(spf[n]);
    n = n / spf[n];
  }
}
