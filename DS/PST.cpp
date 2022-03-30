#include <stdio.h>
#define MX 1e9

struct node {
	int x;
	int l, r;
}T[3535353];

int rt[100005];
int ID = 1;
int A[100005];

int make_tree(int bef, int s, int e, int p) {
	if(e < s || p < s || e < p) return bef;

	int now = ID++;

	if(s == e) {
		T[now].x = T[bef].x + 1;
		return now;
	}

	int m = s + e >> 1;
	T[now].l = make_tree(T[bef].l, s, m, p);
	T[now].r = make_tree(T[bef].r, m + 1, e, p);

	T[now].x = T[T[now].l].x + T[T[now].r].x;

	return now;
}

int query(int now, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[now].x;
	int m = s + e >> 1;
	return query(T[now].l, s, m, p, q) + query(T[now].r, m + 1, e, p, q);
}

int main() {
	int N, Q; scanf("%d", &N);

	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for(int i = 1; i <= N; i++) rt[i] = make_tree(rt[i - 1], 0, MX, A[i]);

	scanf("%d", &Q);

	for(int i = 1; i <= Q; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", query(rt[b], 0, MX, c + 1, MX) - query(rt[a - 1], 0, MX, c + 1, MX));
	}
	return 0;
}