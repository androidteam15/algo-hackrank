#include <iostream>
#include <map>

#define ll long long
#define miterator map<int, int>::iterator

#define MOD 1000000007
#define MAXN 100000
#define MAXM 100000

using namespace std;

int A[MAXN], B[MAXM], C[MAXM];

map<int, int> factor; 

inline int modMult(int a, int b) {
  return (a * (ll) b) % MOD;
}

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < m; i++) cin >> B[i];
  for(int i = 0; i < m; i++) cin >> C[i];

  for(int i = 0; i < m; i++) {
    int old = factor.count(B[i]) ? factor[B[i]] : 1;
    factor[B[i]] = modMult(old, C[i]);

    cout << factor[B[i]] << " ";
  }

  for(miterator it = factor.begin(); it != factor.end(); it++) {
    int step = it->first;
    for(int i = step - 1; i < n; i += step) {
      A[i] = modMult(A[i], it->second);
    }
  }

  // cout << A[0];
  // for(int i = 1; i < n; i++) {
  //   cout << " " << A[i];
  // }
  // cout << endl;

  return 0;
}