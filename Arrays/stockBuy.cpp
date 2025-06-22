#include <iostream>
#include <vector>
#include <algorithm>  // For std::max

using namespace std;

int maxProfit(vector<int>& prices) {
    int buyPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (buyPrice > prices[i]) {
            buyPrice = prices[i];
        }

        profit = max(profit, prices[i] - buyPrice);
    }

    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};  // Example input
    int result = maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
