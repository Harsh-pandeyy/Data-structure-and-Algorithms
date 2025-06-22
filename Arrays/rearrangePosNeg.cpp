#include <iostream>
#include <vector>

using namespace std;

vector<int> rearrangeArray(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, 0);
    int pos = 0;
    int neg = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            ans[neg] = a[i];
            neg += 2;
        } else {
            ans[pos] = a[i];
            pos += 2;
        }
    }

    return ans;
}

int main() {
    // Example input
    vector<int> input = {3, 1, -2, -5, 2, -4};

    // Call the function
    vector<int> result = rearrangeArray(input);

    // Print the result
    cout << "Rearranged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
