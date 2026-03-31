#include <stdio.h>
#include <limits.h>

#define MAXP 10
#define MAXN 20

long long dp[MAXN][MAXP];  // memoization

// Compute minimum moves using DP
long long min_moves(int n, int k) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (k == 3) return (1LL << n) - 1;

    if (dp[n][k] != -1) return dp[n][k];

    long long ans = LLONG_MAX;

    for (int t = 1; t < n; t++) {
        long long moves =
            2 * min_moves(t, k) + min_moves(n - t, k - 1);

        if (moves < ans)
            ans = moves;
    }

    return dp[n][k] = ans;
}

// Print moves (recursive)
void hanoi(int n, int k, int from, int to, int pegs[], int pcount) {
    if (n == 0) return;

    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }

    if (k == 3) {
        int aux = pegs[0];
        hanoi(n-1, 3, from, aux, &to, 1);
        printf("Move disk %d from %d to %d\n", n, from, to);
        hanoi(n-1, 3, aux, to, &from, 1);
        return;
    }

    int best_t = 1;
    long long best = LLONG_MAX;

    for (int t = 1; t < n; t++) {
        long long val =
            2 * min_moves(t, k) + min_moves(n - t, k - 1);

        if (val < best) {
            best = val;
            best_t = t;
        }
    }

    int temp = pegs[0];

    // Step 1: move t disks to temp
    hanoi(best_t, k, from, temp, &pegs[1], pcount-1);

    // Step 2: move remaining using k-1 pegs
    hanoi(n - best_t, k - 1, from, to, &pegs[1], pcount-1);

    // Step 3: move t disks to target
    hanoi(best_t, k, temp, to, &pegs[1], pcount-1);
}

int main() {
    int n, k;
    printf("Enter number of disks and pegs: ");
    scanf("%d %d", &n, &k);

    // init DP
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXP; j++)
            dp[i][j] = -1;

    int pegs[MAXP];
    int idx = 0;

    // define pegs (excluding source=1 and target=2)
    for (int i = 3; i <= k; i++)
        pegs[idx++] = i;

    printf("Minimum moves = %lld\n", min_moves(n, k));

    hanoi(n, k, 1, 2, pegs, idx);

    return 0;
}
