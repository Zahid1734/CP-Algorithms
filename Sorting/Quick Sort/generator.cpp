#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else 
#define dbg(...) 42
#endif

int generate(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main() {

    srand(time(0));

    int n = generate(100000, 100000);

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << generate(1, 1000000) << " ";
    }

    cout << "\n";
    
    return 0;
}