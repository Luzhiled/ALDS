#include <iostream>
#include <vector>
#include <functional>

int main() {
    int k;
    std::cin >> k;

    std::vector< std::vector< char > > borad(8, std::vector< char >(8, '.'));

    auto d1 = [](int r, int c) {
        return r;
    };

    auto d2 = [](int r, int c) {
        return c;
    };

    auto d3 = [](int r, int c) {
        return r + c;
    };

    auto d4 = [](int r, int c) {
        return r + (7 - c);
    };

    int b1, b2, b3, b4;
    b1 = b2 = b3 = b4 = 0;
    for (int i = 0; i < k; ++i) {
        int r, c;
        std::cin >> r >> c;

        borad[r][c] = 'Q';
        b1 = b1 + (1 << d1(r, c));
        b2 = b2 + (1 << d2(r, c));
        b3 = b3 + (1 << d3(r, c));
        b4 = b4 + (1 << d4(r, c));
    }

    bool f = false;
    std::function< void(int, int, int, int) > dfs = [&](int b1, int b2, int b3, int b4) {
        if (b1 == (1 << 8) - 1) {
            f = true;
        }

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (b1 & (1 << d1(i, j))) continue;
                if (b2 & (1 << d2(i, j))) continue;
                if (b3 & (1 << d3(i, j))) continue;
                if (b4 & (1 << d4(i, j))) continue;

                borad[i][j] = 'Q';
                dfs(b1 | (1 << d1(i, j)), b2 | (1 << d2(i, j)), b3 | (1 << d3(i, j)), b4 | (1 << d4(i, j)));
                if (f) return;
                borad[i][j] = '.';
            }
        }
    };

    dfs(b1, b2, b3, b4);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) { 
            std::cout << borad[i][j];
        }
        std::cout << std::endl;
    }
}
