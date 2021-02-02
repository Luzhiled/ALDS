#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <algorithm>

bool is_inside(int r, int c) {
    return 0 <= r && r < 3 && 0 <= c && c < 3; 
};

bool check(const std::vector< std::vector< int > > &board) {
    constexpr int ok[3][3] = 
       {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != ok[i][j]) return false;
        }
    }

    return true;
};

inline int dfs(int r, int c, int dep, int pk, int ans, std::vector< std::vector< int > > &board) {
    if (ans <= dep) return ans;
    if (check(board)) {
        return std::min(ans, dep);
    }

    constexpr int dr[] = {-1, 0, 1, 0};
    constexpr int dc[] = {0, 1, 0, -1};
    for (int k = 0; k < 4; ++k) {
        if ((k + 2) % 4 == pk) continue;
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (!is_inside(nr, nc)) continue;

        std::swap(board[r][c], board[nr][nc]);
        ans = std::min(ans, dfs(nr, nc, dep + 1, k, ans, board));
        std::swap(board[r][c], board[nr][nc]);
    }

    return ans;
};

int main() {
    std::vector< std::vector< int > > board(3, std::vector< int >(3));

    int r = -1, c = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> board[i][j];

            if (board[i][j] == 0) {
                r = i;
                c = j;
            }
        }
    }

    std::cout << dfs(r, c, 0, -1, 31, board) << std::endl;
}
