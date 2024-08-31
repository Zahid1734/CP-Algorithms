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

    int ind1 = generate(l, r);
    int ind2 = generate(l, r);
    int ind3 = generate(l, r);
    int ind4 = generate(l, r);
    int ind5 = generate(l, r);

    int b[] = {a[ind1], a[ind2], a[ind3], a[ind4], a[ind5]};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (b[j] < b[i]) swap(b[j], b[i]);
        }
    }
    int x = b[1]; // Take the median of the three values 
    int i = l, m = l;
    while(i <= r) {
        if (a[i] < x) {
            swap(a[i], a[m]);
            m++;
        }
        i++;
    } 
    int ind = m - 1;
    for (int i = m; i <= r; i++) {
        if (a[i] == x) {
            swap(a[i], a[m++]);
        }
    }
    QuickSort(a, l, ind);
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