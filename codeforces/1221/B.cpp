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

vector<pi32> dirs = {
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2}};

i32 main() {
  i32 n;
  cin >> n;
  vector<vector<char>> board(n);
  REP(i, 0, n)
  board[i] = vector<char>(n);

  REP(i, 0, n) {
    REP(j, 0, n) {
      if (board[i][j]) continue;
      board[i][j] = 'W';

      queue<pi32> q;
      q.push({i, j});
      while (!q.empty()) {
        auto item = q.front();
        q.pop();

        for (auto dir : dirs) {
          i32 newX = item.first + dir.first;
          i32 newY = item.second + dir.second;

          if (newX < 0 || newY < 0 || newX >= n || newY >= n || board[newX][newY]) continue;
          board[newX][newY] = board[item.first][item.second] == 'W' ? 'B' : 'W';
          q.push({newX, newY});
        }
      }
    }
  }

  REP(i, 0, n) {
    REP(j, 0, n) {
      cout << board[j][i];
    }
    cout << "\n";
  }
}
