#include <iostream>
#include <vector>

constexpr int inf = 1001001001;

int merge_sort(std::vector<int>& as, int l, int r) {
    if (r - l <= 1) return 0;

    int mid = (l + r) / 2;
    int res = 0;
    res += merge_sort(as, l, mid);
    res += merge_sort(as, mid, r);

    std::vector<int> bs;
    int idxl = l, idxr = mid;
    while (idxl < mid || idxr < r) {
        res++;
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

    int cnt = merge_sort(ss, 0, n);

    for (int i = 0; i < n; ++i) {
        std::cout << ss[i] << (i + 1 == n ? "\n" : " ");
    }
    std::cout << cnt << std::endl;
}

