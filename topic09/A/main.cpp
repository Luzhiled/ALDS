#include <iostream>
#include <vector>

int main() {
    int h;
    std::cin >> h;

    std::vector< int > vs(h + 1);
    for (int i = 1; i <= h; ++i) {
        std::cin >> vs[i];
    }

    auto print_parent = [h, vs](int idx) {
        int p_idx = idx / 2;
        if (p_idx == 0) return;
        std::cout << "parent key = " << vs[p_idx] << ", ";
    };

    auto print_left = [h, vs](int idx) {
        int l_idx = 2 * idx;
        if (h < l_idx) return;
        std::cout << "left key = " << vs[l_idx] << ", ";
    };

    auto print_right = [h, vs](int idx) {
        int r_idx = 2 * idx + 1;
        if (h < r_idx) return;
        std::cout << "right key = " << vs[r_idx] << ", ";
    };

    for (int i = 1; i <= h; ++i) {
        std::cout << "node " << i << ": key = " << vs[i] << ", ";
        print_parent(i);
        print_left(i);
        print_right(i);
        std::cout << std::endl;
    }
}
