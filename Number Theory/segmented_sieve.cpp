vector<ll> segmented_sieve(ll n, ll m) {
  vector<ll> ans;
  vector<char> sieve2(m - n + 1, 0);
  ll sqrtn = sqrt(m);
  // we need primes till sqrt(max(m))
  for (int i = 0; i < primes.size() && primes[i] <= sqrtn; i++) {
    ll x = primes[i] * primes[i];
    x = max(((n + primes[i] - 1) / primes[i]) * primes[i], (ll)primes[i] * primes[i]);
    while (x <= m) {
      sieve2[x - n] = 1;
      x += primes[i];
    }
  }
  for (int i = 0; i < (m - n + 1); i++) {
    if (sieve2[i] == 0 && n + i != 1) ans.PB(n + i);
  }

  return ans;
}
