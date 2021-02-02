#include <iostream>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector< int > &vs) {
    for (size_t i = 0; i < vs.size(); ++i) {
        os << vs[i] << (i + 1 == vs.size() ? "" : " ");
    }
    return os;
}

void insertion_sort(std::vector< int > vs) {
    std::cout << vs << std::endl;
    for (int i = 1; i < vs.size(); ++i) {
        int val = vs[i];
        int j = i;
        while (j > 0 && vs[j - 1] > val) {
            vs[j] = vs[j - 1];
            j--;
        }

        vs[j] = val;

        std::cout << vs << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;

    std::vector< int > As(N);
    for (auto &A: As) std::cin >> A;

    insertion_sort(As);
}
