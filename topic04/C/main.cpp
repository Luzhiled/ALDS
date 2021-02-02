#include <iostream>
#include <cstddef>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    auto to_idx = [](const std::string &s) {
        const char ACGT[] = {'.', 'A', 'C', 'G', 'T'};
        int res = 0;
        for (int i = 0, k = 1; i < (int)s.size(); i += 1, k *= 5) {
            int digit = 0;
            for (int j = 1; j <= 4; ++j) {
                if (s[i] == ACGT[j]) {
                    digit = j;
                }
            }

            res += k * digit;
        }

        return res;
    };

    constexpr std::size_t dict_size = 244140625; // 5^{12}
    std::vector< bool > dict(dict_size);

    for (int i = 0; i < n; ++i) {
        std::string query, s;
        std::cin >> query >> s;

        if (query == "insert") {
            dict[to_idx(s)] = true;
        } else {
            std::cout << (dict[to_idx(s)] ? "yes" : "no") << std::endl;
        }
    }
}
