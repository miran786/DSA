#include <bits/stdc++.h>
using namespace std;

// Reference, not a problem to solve — just the binary search pattern/syntax

int main() {
    vector<int> nums = {1, 3, 5, 6, 9, 12};
    int target = 9;

    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;   // avoids overflow, NOT (high - low)/2 alone

        if (nums[mid] == target) {
            ans = mid;
            break;
        }
        else if (nums[mid] < target) {
            low = mid + 1;    // search right half
        }
        else {
            high = mid - 1;   // search left half
        }
    }

    cout << "Target " << target << " found at index: " << ans << endl;

    // --- Variants built on the same skeleton ---

    // Lower Bound: first index where nums[i] >= x
    int x = 5;
    low = 0, high = nums.size() - 1;
    int lb = nums.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x) {
            lb = mid;
            high = mid - 1;   // keep searching left for an earlier valid index
        } else {
            low = mid + 1;
        }
    }
    cout << "Lower bound of " << x << ": " << lb << endl;

    // Upper Bound: first index where nums[i] > x
    low = 0, high = nums.size() - 1;
    int ub = nums.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > x) {
            ub = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << "Upper bound of " << x << ": " << ub << endl;

    return 0;
}
