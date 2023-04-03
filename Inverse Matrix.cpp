#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<double>> coeff;
vector<vector<double>> constants;
vector<vector<double>> identity;
vector<vector<double>> res;

int n;

void CreateIdentity() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) identity[i][j] = 1;
		}
	}
}

long long Determinant(vector<vector<double>> &mat, int now) {
	long long determinant = 0;

	if (now == 1) return mat[1][1];
	
	vector<vector<double>> v(now, vector<double>(now));

	for (int i = 1; i <= now; i++) {
		int rr = 1;
		int cc = 1;

		for (int j = 2; j <= now; j++) {
			for (int k = 1; k <= now; k++) {
				if (k != i) {
					v[rr][cc] = mat[j][k];
					cc++;
					if (cc == now) cc = 1, rr++;
				}
			}
		}
		determinant += (ll)(pow(-1, i + 1) * (ll)mat[1][i] * (ll)Determinant(v, now - 1));
	}

	return determinant;
}

void Pivot() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j != i) {
				for (int k = 1; k <= n; k++) {
					coeff[i][k] += coeff[j][k];
					identity[i][k] += identity[j][k];
				}
			}
		}
	}
}

void CreateInverse() {

	for (int i = 1; i <= n; i++) {
		double key = coeff[i][i];

		for (int j = 1; j <= n; j++) {
			coeff[i][j] /= key;
			identity[i][j] /= key;
		}

		for (int j = i + 1; j <= n; j++) {
			double factor = coeff[j][i] / coeff[i][i];
			for (int k = 1; k <= n; k++) {
				coeff[j][k] = coeff[j][k] - factor * coeff[i][k];
				identity[j][k] = identity[j][k] - factor * identity[i][k];
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			double factor = coeff[j][i] / coeff[i][i];
			for (int k = 1; k <= n; k++) {
				coeff[j][k] = coeff[j][k] - factor * coeff[i][k];
				identity[j][k] = identity[j][k] - factor * identity[i][k];
				
			}
		}
	}
}

void Product() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res[i][1] += identity[i][j] * constants[j][1];
		}
	}
}

int main() {

	cout << "Enter the number of unknowns : ";
	cin >> n;

	coeff.resize(n + 1, vector<double>(n + 1));
	constants.resize(n + 1, vector<double>(2));
	identity.resize(n + 1, vector<double>(n + 1));
	res.resize(n + 1, vector<double>(2));

	for (int i = 1; i <= n; i++) {
		cout << "Enter the coefficients of the equation: " << i << ": ";
		for (int j = 1; j <= n; j++) cin >> coeff[i][j];
	}
	cout << "Enter the constant terms: " ;
	for (int i = 1; i <= n; i++) cin >> constants[i][1];

	CreateIdentity();

	if (Determinant(coeff, n) == 0) {
		cout << "Inverse of the matrix does not exist!";
		exit(0);
	}

	Pivot();
	CreateInverse();

	Product();

	cout << "The result matrix is : [ ";

	for (int i = 1; i <= n; i++) {
		cout << res[i][1] << " , "[i < n];
	}
	cout << "]\n";
	
	return 0;
}
