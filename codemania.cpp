#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef ZAHID_LOCAL
    ~debug() { cerr << endl; }
    eni(!= ) cerr << boolalpha << i; ris;
}
eni(== ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

const int N = 1e6 + 5;
const int NN = 2e6 + 10;

using ll = long long;

vector<bool> sieve1(N, 0);
vector<bool> sieve2(N, 0);
vector<int> primes;
vector<vector<int>> adj(NN);
vector<bool> vis(NN, false);

int ans = 0;
int n;

void generate_primes() {
    sieve2[0] = sieve2[1] = 1;
    for (int i = 4; i <= n; i += 2) sieve2[i] = 1;
    primes.push_back(2);

    for (int i = 3; i * i <= n; i += 2) {
        if (!sieve2[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                sieve2[j] = 1;
            }
        }
    }

    for (int i = 3; i <= n; i += 2) {
        if (!sieve2[i]) {
            primes.push_back(i);
        }
    }
}

void segmented_sieve(ll l, ll r) {
    int n = primes.size();
    for (int i = 0; i < n; i++) {
        for (ll j = max(1LL * primes[i] * primes[i], (l + primes[i] - 1) / primes[i] * primes[i]); j <= r; j += primes[i]) {
            sieve1[j - l] = 1;
            int to;
            if (j <= n) to = j;
            else to = j - l + n + i;
            adj[primes[i]].push_back(to);
            adj[to].push_back(primes[i]);
        }
    }

}

void dfs(int root) {
    vis[root] = 1;
    for (auto i : adj[root]) {
        if (!vis[i]) dfs(i);
    }
}

void solve() {
    long long l, r;
    cin >> l >> r;

    n = sqrt(r);
    generate_primes();
    segmented_sieve(l, r);
    
    int ans = 0;
    for (int i = 1; i <= n + (r - l) + 1
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef ZAHID_LOCAL
    FILE *fp = freopen("input.txt", "r", stdin);
    if (fp == NULL) {
        exit(0);
    }
#endif

    int tt = 1;
    //cin >> tt;

    while (tt--) solve();
    
    return 0;
}


