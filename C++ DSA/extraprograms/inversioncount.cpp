#include <iostream>
#include <vector>

using namespace std;

long count(vector<long>& arr, long s, long e) {
    // Base case
    if (s >= e)
        return 0;

    long mid = (s + e) / 2;

    // Left Part inversion
    long inv = count(arr, s, mid);
    inv += count(arr, mid + 1, e);
    inv += merge(arr, s, e);
    return inv;
}

long merge(vector<long>& arr, long s, long e) {
    long ans = 0;

    int mid = (s + e) / 2;

    int l1 = mid - s + 1;
    int l2 = e - mid;

    vector<long> a1(l1);
    vector<long> a2(l2);

    int idx = s;

    // Copy elements
    for (int i = 0; i < l1; i++) {
        a1[i] = arr[idx++];
    }

    for (int i = 0; i < l2; i++) {
        a2[i] = arr[idx++];
    }

    int idx1 = 0;
    int idx2 = 0;
    idx = s;
    while (idx1 < l1 && idx2 < l2) {
        // Check for inversions
        if (a1[idx1] > a2[idx2]) {
            ans += (l1 - idx1);
            arr[idx++] = a2[idx2++];
        } else {
            arr[idx++] = a1[idx1++];
        }
    }

    while (idx1 < l1) {
        arr[idx++] = a1[idx1++];
    }
    while (idx2 < l2) {
        arr[idx++] = a2[idx2++];
    }

    return ans;
}

long inversionCount(vector<long>& arr) {
    return count(arr, 0, arr.size() - 1);
}

int main() {
    vector<long> arr = {1, 20, 6, 4, 5};
    long inversions = inversionCount(arr);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
