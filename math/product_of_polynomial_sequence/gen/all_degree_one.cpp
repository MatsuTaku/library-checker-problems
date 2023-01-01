#include <cstdio>
#include "../params.h"
#include "random.h"

using namespace std;

int main(int, char* argv[]) {
  long long seed = atoll(argv[1]);
  auto gen = Random(seed);

  int N = D_MAX;

  vector<int> deg(N, 1);

  auto gen_poly = [&](int d) -> vector<int> {
    vector<int> f(d + 1);
    for (int j = 0; j <= d; ++j) {
      int lo = 0;
      if (j == d) lo = 1;
      f[j] = gen.uniform<int>(lo, MOD - 1);
    }
    return f;
  };

  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    int d = deg[i];
    vector<int> f = gen_poly(d);
    printf("%d", d);
    for (int j = 0; j <= d; ++j) { printf(" %d", f[j]); }
    printf("\n");
  }
  return 0;
}