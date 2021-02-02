#include <iostream>
#include <vector>

using i64 = long long;
constexpr int inf = 1001001001;

i64 merge_sort(std::vector<int>& as, int l, int r) {
  if (r - l <= 1) return 0;

  int mid = (l + r) / 2;
  i64 res = 0;
  res += merge_sort(as, l, mid);
  res += merge_sort(as, mid, r);

  std::vector<int> bs;
  int idxl = l, idxr = mid;
  while (idxl < mid || idxr < r) {
    if (idxr == r) {
      bs.emplace_back(as[idxl]);
      idxl++;
      continue;
    }

    if (idxl == mid) {
      bs.emplace_back(as[idxr]);
      idxr++;
      continue;
    }

    if (as[idxl] <= as[idxr]) {
      bs.emplace_back(as[idxl]);
      idxl++;
    } else {
      bs.emplace_back(as[idxr]);
      idxr++;
      res += mid - idxl;
    }
  }

  for (int i = l; i < r; ++i) {
    as[i] = bs[i - l];
  }

  return res;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> ss(n);
  for (auto& s : ss) std::cin >> s;

  std::cout << merge_sort(ss, 0, n) << std::endl;
}

