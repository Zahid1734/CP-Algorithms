#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef ZAHID_LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;
using ull = unsigned long long;

#define pb push_back
#define ss second
#define ff first
#define PI acos(-1)
#define setbit(a, b) (a |= (1LL << b))
#define checkbit(a, b) (a & (1LL << b))
#define countbit(a) __builtin_popcount(a) // use __builtin_popcountll for long long
#define erasebit(a, b) (a &= (~(1LL << b)))
#define reversebit(a, b) (a ^= (1LL << b))
#define sz(a) (int)a.size()

const ll INF = (1LL << 63);


void solve() {
    
    
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int tt = 1;
    //cin >> tt;
    for (int i = 1; i <= tt; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}
