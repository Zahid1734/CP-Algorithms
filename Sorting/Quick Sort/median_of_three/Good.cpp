#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else 
#define dbg(...) 42
#endif


int main() {

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
       cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}