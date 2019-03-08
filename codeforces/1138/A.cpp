#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  vi32 a(n);
  REP(i, 0, n) {
    cin >> a[i];
  }
  i32 prev = a[0], cur = 0;
  vi32 s(1, 1);

  REP(i, 1, n) {
    if (a[i] == a[i - 1]) {
      s[cur]++;
    } else {
      prev = a[i];
      cur++;
      s.push_back(1);
    }
  }

  i32 best = 0;
  REP(i, 1, cur + 1) {
    best = max(min(s[i - 1], s[i]), best);
  }
  cout << best * 2 << endl;
}
