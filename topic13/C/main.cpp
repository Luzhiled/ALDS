#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1001001001;
constexpr int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

int get_mandist(int val, int y, int x) {
    if (val == 0) return 0;
    else val--;
    return abs(y - val / 4) + abs(x - val % 4);
}

int get_sum_of_mandist(vector< vector< int > > vs) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res += get_mandist(vs[i][j], i, j);
        }
    }

    return res;
}

inline bool is_inside(int y, int x) {
    return (0 <= y && y < 4) && (0 <= x && x < 4);
}

int cost_diff(const vector< vector< int > > &vs, int y, int x, int ny, int nx) {
    int now  = get_mandist(vs[y][x], y, x) + get_mandist(vs[ny][nx], ny, nx);
    int next = get_mandist(vs[y][x], ny, nx) + get_mandist(vs[ny][nx], y, x);

    return next - now;
}

int solve(vector< vector< int > > &vs, int y, int x) {
    struct data {
        int cost, score;
        int y, x;
        int pre;
        vector< vector< int > > vs;

        data() {}
        data(int cost, int score, vector< vector< int > > vs, int y, int x, int pre) : cost(cost), score(score), vs(vs), y(y), x(x), pre(pre) {}
    };

    auto c = [](const data &a, const data &b) { return a.cost > b.cost; };
    priority_queue< data, vector< data >, decltype(c)> pq{c};

    int res = 46;
    pq.emplace(get_sum_of_mandist(vs), 0, vs, y, x, -1);

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if (p.cost == 0) {
            res = min(res, p.score);
            continue;
        }

        if (res <= p.score + p.cost) {
            continue;
        }

        int y = p.y;
        int x = p.x;

        for (int i = 0; i < 4; ++i) {
            if (p.pre == i) continue;
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!is_inside(ny, nx)) continue;

            swap(p.vs[y][x], p.vs[ny][nx]);
            int ncost = get_sum_of_mandist(p.vs);
            if (ncost + p.score + 1 < res) {
                pq.emplace(ncost, p.score + 1, p.vs, ny, nx, (i + 2) % 4);
            }
            swap(p.vs[y][x], p.vs[ny][nx]);
        }
    }

    return res;
}

int main() {
    int y, x;
    vector< vector< int > > vs(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int v;
            cin >> v;

            vs[i].emplace_back(v);

            if (v == 0) {
                y = i;
                x = j;
            }
        }
    }

    cout << solve(vs, y, x) << endl;;
}
