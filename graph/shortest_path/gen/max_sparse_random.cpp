#include <stdio.h>
#include "random.h"
#include "../params.h"

int main(int, char **argv) {
	long long seed = atoll(argv[1]);
	auto gen = Random(seed);

	int n = N_MAX / 2; // to make chance to have at least one path
	int m = M_MAX;
	int s = gen.uniform(0, n - 1);
	int t;
	do t = gen.uniform(0, n - 1); while (s == t);
	printf("%d %d %d %d\n", n, m, s, t);
	
	std::set<std::pair<int, int> > used;
	for (int i = 0; i < m; i++) {
		int a, b;
		do a = gen.uniform(0, n - 1), b = gen.uniform(0, n - 1); while (a == b || !used.insert({a, b}).second);
		int c = gen.uniform(C_MIN, C_MAX);
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}
