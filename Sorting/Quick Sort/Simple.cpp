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

template<typename T> 
void QuickSort(vector<T> &a, int l, int r) {
    if (r <= l) return ;

    int ind = generate(l, r);
    int x = a[ind];
    int i = l, m = l;
    while(i <= r) {
        if (a[i] < x) {
            swap(a[i], a[m]);
            m++;
        }
        i++;
    } 
    QuickSort(a, l, m - 1);
    QuickSort(a, m, r);
}

int main() {

    srand(time(0));
    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    QuickSort(b, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    cout << "\n";
    return 0;
}