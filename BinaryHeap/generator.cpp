#include <bits/stdc++.h>

using namespace std;

int gen(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main() {

	srand(time(0));

	freopen("in", "w", stdout);

	int n = gen(1, 10000); 
	cout << n << "\n";
	for (int i = 0; i < n; i++) {
		int x = gen(1, 1000000);
		cout << x << " ";
	}

	cout << "\n";

	return 0;	
}
