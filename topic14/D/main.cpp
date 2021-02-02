#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct suffix_array {
    std::string s;
    std::vector<int> sa, rev;

    suffix_array() {}
    suffix_array(const std::string& S) : s(S) {
        s.push_back('$');
        int n = s.size();

        sa.resize(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int a, int b) {
            if (s[a] == s[b]) return a > b;
            return s[a] < s[b];
        });

        std::vector<int> cs(n), cnt(n), rs(n);
        for (int i = 0; i < n; ++i) {
            rs[i] = (int)s[i];
        }

        for (int len = 1; len < n; len *= 2) {
            for (int i = 0; i < n; ++i) {
                cs[sa[i]] = i;
                if (i > 0 && rs[sa[i - 1]] == rs[sa[i]] &&
                    rs[sa[i - 1] + len / 2] == rs[sa[i] + len / 2]) {
                    cs[sa[i]] = cs[sa[i - 1]];
                }
            }

            std::iota(cnt.begin(), cnt.end(), 0);
            std::copy(sa.begin(), sa.end(), rs.begin());
            for (int i = 0; i < n; ++i) {
                int s1 = rs[i] - len;
                if (s1 >= 0) sa[cnt[cs[s1]]++] = s1;
            }
            cs.swap(rs);
        }

        rev.resize(n);
        for (int i = 0; i < n; ++i) {
            rev[sa[i]] = i;
        }
    }

    int operator[](int i) const { return sa[i]; }

    bool lt_substr(const std::string& t, int si, int ti) const {
        int sn = s.size(), tn = t.size();
        while (si < sn && ti < tn) {
            if (s[si] < t[ti]) return 1;
            if (s[si] > t[ti]) return 0;
            si++;
            ti++;
        }
        return si == sn && ti < tn;
    }

    int lower_bound(const std::string& t) {
        int l = 0, r = s.size();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (lt_substr(t, sa[m], 0)) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

    int upper_bound(std::string& t) {
        t.back()++;
        int res = lower_bound(t);
        t.back()--;
        return res;
    }

    int count(std::string& T) { return upper_bound(T) - lower_bound(T); }
};

int main() {
    std::string t;
    std::cin >> t;
    suffix_array sa(t);

    int q;
    std::cin >> q;

    while (q--) {
        std::string p;
        std::cin >> p;

        std::cout << std::clamp(sa.count(p), 0, 1) << std::endl;
    }
}
