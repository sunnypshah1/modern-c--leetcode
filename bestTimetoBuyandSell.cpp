#include <iostream>

class Solution {
public:
  int maxProfit(std::span<const int> prices) {
    int profit{};
    int lowest_price{prices[0]};
    for (const auto &p : prices) {
      lowest_price = p < lowest_price ? p : lowest_price;
      profit = (p - lowest_price) > profit ? (p - lowest_price) : profit;
    }
  }
};
