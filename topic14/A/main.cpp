#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string t, p;
    std::cin >> t >> p;

    for (int i = 0; i + (int)p.size() <= (int)t.size(); ++i) {
        if (p == t.substr(i, p.size())) {
            std::cout << i << std::endl;
        }
    }
}
