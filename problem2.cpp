#include <bits/stdc++.h>
using namespace std;

void solve() {
    // input size
    int n;
    cin >> n;

    // input values
    vector<int> house_money(n);
    for (int i = 0; i < n; i++) {
        cin >> house_money[i];
    }

    // Edge Cases
    if (n == 0) {
        cout << 0 << endl;
        return;
    } else if (n == 1) {
        cout << max(0, house_money[0]) << endl;
        return;
    }

    // Dynamic Programming using Tabulation.

    // dp[i] = maximum amount of money stolen till house i - 2.
    vector<int> dp(n+2, 0);
    // base cases: no money stolen from houses -2 & -1 respectively.
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n+1; i++) {
        // Case 1: we would have to either skip this house if we want to keep the amount stolen from the previous house
        // Case 2: we can steal from this house and keep the amount stolen from the second last house.
        dp[i] = max(dp[i - 1], dp[i - 2] + house_money[i - 2]);
    }

    // the last value of our dp table will hold the answer to the original problem.
    cout << dp[n+1] << endl;
    // TIME COMPLEXITY: 
    //  O(N), where N is the number of houses in input.
    //  this is because we iterate using loop of size N for our exhaustive search.
    // SPACE COMPLEXITY (Auxillary): O(N), where N is the number of houses in input.
    //  this is because we create a vector (array) of size N to perform tabulation dynamic programming.
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
        solve();

    return 0;
}