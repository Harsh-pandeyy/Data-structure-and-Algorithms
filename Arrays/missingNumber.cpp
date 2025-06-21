#include <iostream>
#include <vector>

using namespace std;

// Function to find the missing number in an array containing n distinct numbers from 0 to n
int missingNumber(vector<int>& a) {
    int n = a.size();
    int sum = (n * (n + 1)) / 2;
    
    for (int i = 0; i < n; i++) {
        sum -= a[i];
    }

    return sum;
}

// Helper function to print a vector (optional, for debugging)
void printArray(const vector<int>& a) {
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example input: numbers from 0 to 5, with one missing (e.g., 3)
    vector<int> nums = {0, 1, 2, 4, 5};

    cout << "Input array: ";
    printArray(nums);

    int missing = missingNumber(nums);

    cout << "Missing number is: " << missing << endl;

    return 0;
}
