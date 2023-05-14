
#ifdef ZAHID_LOCAL
    #define _GLIBCXX_DEBUG
	#define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

#define eb emplace_back
#define second ss
#define ff first
#define PI acos(-1)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define setbit(a, b) (a |= (1LL << b))
#define checkbit(a, b) (a & (1LL << b))
#define countbit(a) __builtin_popcount(a) // use __builtin_popcountll for long long
#define sz(a) int(a.size())
#define erasebit(a, b) (a &= (~(1LL << b)))
#define reversebit(a, b) (a ^= (1LL << b))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// less<int> is the comparing function
// null_type means it is being used as a set
// int is the type of the data being stored. It can be float, pair etc
// find_by_order(x) -> returns the (x + 1) th element in the set
// order_of_key(x) -> number of items strictly smaller than x

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
    //cin >> tt;
    for (int i = 1; i <= tt; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}
