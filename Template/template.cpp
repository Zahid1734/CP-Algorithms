#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using int128 = __int128_t;

#define pb push_back
#define second ss
#define ff first
#define PI acos(-1)
#define setbit(a, b) (a |= (1LL << b))
#define checkbit(a, b) (a & (1LL << b))
#define countbit(a) __builtin_popcount(a) // use __builtin_popcountll for long long
#define erasebit(a, b) (a &= (~(1LL << b)))
#define reversebit(a, b) (a ^= (1LL << b))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// less<int> is the comparing function
// null_type means it is being used as a set
// int is the type of the data being stored. It can be float, pair etc
// find_by_order(x) -> returns the (x + 1) th element in the set
// order_of_key(x) -> number of items strictly smaller than x
const ll INF = (1LL << 63);

void solve() {

}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}
