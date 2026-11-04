
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> weight(N);
    vector<long long> value(N);

    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = W; j >= weight[i]; j--) {
            dp[j] = max(dp[j],
                        dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}

