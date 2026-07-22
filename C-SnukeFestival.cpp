// sort 3 arrays of n
// loop backwards thru last array
// use lower bound to find iterator to smallest val that is stricly greater or
// equal in middle array decrement iterator find val - and amount by using
// std::distance from begin to it + 1 use lower bound to find iterator to
// smallest val that is strictly greater or equal in top array decrement
// iterator get amount by using std::distance from begin to it + 1 multiply both
// amounts and sum to total

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<long long> A(n), B(n), C(n);

  for (int i = 0; i < n; ++i)
    std::cin >> A[i];
  for (int i = 0; i < n; ++i)
    std::cin >> B[i];
  for (int i = 0; i < n; ++i)
    std::cin >> C[i];

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::sort(C.begin(), C.end());

  long long total = 0;

  for (long long b : B) {
    long long numA = std::lower_bound(A.begin(), A.end(), b) - A.begin();
    long long numC = C.end() - std::upper_bound(C.begin(), C.end(), b);

    total += numA * numC;
  }

  std::cout << total << '\n';
}
