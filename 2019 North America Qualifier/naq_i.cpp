#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, t, d; cin >> n >> m >> t >> d;
    long long adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = -1;
    }
    int loc[t + 2];
    for (int i = 0; i < t; i++) {
        cin >> loc[i];
        loc[i]--;
    }
    loc[t] = 0; loc[t + 1] = n - 1;
    t += 2;
    while (m--) {
        int i, j, k; cin >> i >> j >> k;
        i--; j--;
        adj[i][j] = adj[j][i] = k;
    }
    long long dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) dp[i][j] = adj[i][j];
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] != -1 && dp[k][j] != -1 && (dp[i][j] == -1 || dp[i][j] > dp[i][k] + dp[k][j])) dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (dp[i][j] > d) dp[i][j] = -1;
    }
    long long dist[n];
    bool vis[n];
    for (int i = 0; i < n; i++) {
        dist[i] = -1;
        vis[i] = 0;
    }
    dist[t - 2] = 0;
    for (int i = 0; i < t; i++) {
        int x = -1;
        for (int j = 0; j < t; j++) {
            if (!vis[j] && dist[j] != -1 && (x == -1 || dist[x] > dist[j])) x= j;
        }
        if (x == -1) break;
        vis[x] = 1;
        for (int j = 0; j < t; j++) {
            if (!vis[j] && dp[loc[j]][loc[x]] != -1 && (dist[j] == -1 || dist[j] > dist[x] + dp[loc[j]][loc[x]])) dist[j] = dist[x] + dp[loc[j]][loc[x]];
        }
    }
    if (dist[t - 1] == -1) {
        cout << "stuck";
        return 0;
    }
    cout << dist[t - 1];
    return 0;
}
