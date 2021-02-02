#include <iostream>
#include <algorithm>
#include <vector>

int selection_sort(std::vector< int > &as, int n) {
    int res = 0;

    for (int i = 0; i < n; ++i) {
        int minj = i;

        for (int j = i; j < n; ++j) {
            if (as[j] < as[minj]) minj = j;
        }

        if (i != minj) res++;
        std::swap(as[i], as[minj]);
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;

    std::vector< int > as(n);
    for (auto &a: as) std::cin >> a;

    int ans = selection_sort(as, as.size());

    for (int i = 0; i < as.size(); ++i) {
        std::cout << as[i] << (i + 1 == as.size() ? '\n' : ' ');
    }

    std::cout << ans << std::endl;
}

