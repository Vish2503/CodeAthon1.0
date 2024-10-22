#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string seats;
    cin >> seats;

    // find the number of people who need to be seated together.
    int total_occupants = 0;
    for (int i = 0; i < n; i++) {
        if (seats[i] == 'O')
            total_occupants++;
    }

    // APPROACH:
    //  we need to seat people consecutively in range of length total_occupants.
    //  we can perform an exhaustive search for all ranges i to i + total_occupants
    //  for each range, we can find the number of swaps needed by finding the number of empty seats in the range that need to be filled
    //  for each empty seat we will need to swap atleast one person from outside the range, hence the number of swaps is equivalent to the number of empty seats in the range.

    // prefix sum array: holds the cumulative count of the number of empty seats we've seen till now
    // we can use this prefix sum array to find the number of empty seats in a given range in O(1).
    vector<int> prefix_count_empty(n+1);
    prefix_count_empty[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_count_empty[i] = prefix_count_empty[i-1] + (seats[i - 1] == 'E');
    }

    // Answer variables, minimum_swaps_needed holds the smallest number of swaps we've seen so far
    // minimum_count holds the count of the number of times we've seen the current minimum_swaps_needed in our iteration.
    int minimum_swaps_needed = INT_MAX;
    int minimum_count = 0;
    for (int i = total_occupants; i <= n; i++) {
        // find the number of empty seats in range
        int swaps_needed = (prefix_count_empty[i] - prefix_count_empty[i - total_occupants]);

        // change answer variables as needed
        if (swaps_needed < minimum_swaps_needed) {
            minimum_swaps_needed = swaps_needed;
            minimum_count = 1;
        } else if (swaps_needed == minimum_swaps_needed) {
            minimum_count++;
        }
    }

    // Edge Case: no swaps needed, everyone is already sitting consecutively, answer should be "0 0".
    if (minimum_swaps_needed == 0) {
        cout << 0 << " " << 0 << endl;
    } else {
        cout << minimum_swaps_needed << " " << minimum_count << endl;
    }
    // TIME COMPLEXITY: O(N), where N is the size of the seats string as input.
    //  this is because we iterate using loop of size N for our exhaustive search.
    // SPACE COMPLEXITY (Auxillary): O(N), where N is the size of the seats string as input.
    //  this is because we create a vector (array) of size N to hold our prefix sums.
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
        solve();

    return 0;
}