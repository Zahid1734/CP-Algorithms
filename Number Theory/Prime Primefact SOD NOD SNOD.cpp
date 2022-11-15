const int N = 1e5 + 5;
vector<int> primes;
vector<char> sieve(N, 0);
vector<pair<int, int>> fact;

void gen_primes(int n) {
  sieve[0] = sieve[1] = 1;
  for (int i = 4; i <= n; i += 2) sieve[i] = 1;
  for (int i = 3; (long long)i * i <= n; i++) {
    if (sieve[i] == 0) {
      for (int j = i * i; j < N; j += 2  * i) {
        sieve[j] = 1;
      }
    }
  }
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (sieve[i] == 0)primes.push_back(i);
  }
}

void prime_factorization(int n) {
  int u = sqrt(n);
  for (int i  = 0; i < (int)primes.size() && primes[i] <= u; i++) {
    if (sieve[n] == 0) {
      break;
    }
    int cnt = 0;
    while (n % primes[i] == 0) {
       n = n / primes[i];
      cnt++;
    }
    u = sqrt(n);
    if(cnt) fact.push_back({primes[i], cnt});
  }
  if (n != 1) {
    fact.push_back({n, 1});
  }
}

int NOD (int n) {
  int ans =  1;
  prime_factorization(n);
  for (int i = 0; i < (int)fact.size(); i++) {
    ans *= (fact[i].second + 1);
  }
  return ans;
}

int SOD (int n) {
  prime_factorization(n);
  int res = 1;
  for (int i = 0; i < (int)fact.size(); i++) {
    int prime = fact[i].first;
    int temp = 1;
    int sum = 1;
    for (int j = 1; j <= fact[i].second; j++) {
      temp *= prime;
      sum += temp;
    }
    res *= sum;
  }
  return res;
}

int SNOD(int n) {
  int res = 0;
  int u = (int)sqrt(n);
  for (int i = 1; i <= u; i++) {
    res += (n / i) - i;
  }
  res *= 2;
  res += u;
  return res;
}
