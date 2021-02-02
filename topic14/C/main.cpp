#include <iostream>
#include <string>
#include <vector>

struct hash_2d {
  private:
    using i64 = long long;
    std::vector<std::string> ss;
    std::vector<std::vector<i64>> hs;
    std::vector<i64> Bi, Ci;

    static constexpr i64 B = 13333333;
    static constexpr i64 C = 12300119;
    static constexpr i64 M = 998244353;

    i64 inv(i64 a) {
        int m = M - 2;
        i64 res = 1;
        while (m) {
            if (m & 1) {
                res = (res * a) % M;
            }
            a = (a * a) % M;
            m /= 2;
        }
        return res;
    }

  public:
    hash_2d(std::vector<std::string> ss) : ss(ss) {
        int h = ss.size(), w = ss[0].size();
        hs.assign(h + 1, std::vector<i64>(w + 1));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                hs[i + 1][j + 1] = ss[i][j];
            }
        }

        i64 r = B, c = C;
        for (int i = 1; i <= h; ++i) {
            c = C;
            for (int j = 1; j <= w; ++j) {
                hs[i][j] = hs[i][j] * (r * c % M) % M;
                c = (c * C) % M;
            }

            r = (r * B) % M;
        }

        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                hs[i][j] = (hs[i][j] + hs[i - 1][j] + hs[i][j - 1] + M -
                            hs[i - 1][j - 1]) %
                           M;
            }
        }

        Bi.assign(h + 1, 0);
        Ci.assign(w + 1, 0);
        Bi.back() = inv(r) * B % M;
        Ci.back() = inv(c) * C % M;

        for (int i = h - 1; i >= 0; --i) {
            Bi[i] = Bi[i + 1] * B % M;
        }

        for (int i = w - 1; i >= 0; --i) {
            Ci[i] = Ci[i + 1] * C % M;
        }
    }

    // (y_min, y_max] & (x_min, x_max]
    i64 get_hash(int y_min, int y_max, int x_min, int x_max) {
        i64 res = hs[y_max][x_max] + hs[y_min][x_min];
        res = res + 2 * M - hs[y_max][x_min] - hs[y_min][x_max];
        res = res * Bi[y_min] % M;
        res = res * Ci[x_min] % M;

        return res;
    }
};

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> S(h);
    for (auto& s : S) std::cin >> s;

    hash_2d Hs(S);

    int r, c;
    std::cin >> r >> c;

    std::vector<std::string> T(r);
    for (auto& s : T) std::cin >> s;

    hash_2d Ht(T);

    for (int i = 0; i + r <= h; ++i) {
        for (int j = 0; j + c <= w; ++j) {
            if (Hs.get_hash(i, i + r, j, j + c) == Ht.get_hash(0, r, 0, c)) {
                std::cout << i << " " << j << std::endl;
            }
        }
    }
}
