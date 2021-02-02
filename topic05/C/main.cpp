#include <complex>
#include <iostream>
#include <vector>

// basis
namespace geometry {
using real_number = long double;

constexpr real_number eps = 1e-8;
constexpr real_number pi = acos(-1);

real_number radian_to_degree(real_number r);
real_number degree_to_radian(real_number d);

inline int sign(real_number x) {
    if (x < -eps) return -1;
    if (x > +eps) return +1;
    return 0;
}

inline bool is_equal(real_number r1, real_number r2) {
    return sign(r1 - r2) == 0;
}
}  // namespace geometry

// point
namespace geometry {
using point = std::complex<real_number>;
using points = std::vector<point>;

point operator*(const point& p, const real_number& k) {
    return point(p.real() * k, p.imag() * k);
}

std::istream& operator>>(std::istream& is, point& p) {
    real_number x, y;
    is >> x >> y;
    p = point(x, y);
    return is;
}

std::ostream& operator<<(std::ostream& os, point& p) {
    return os << p.real() << " " << p.imag();
}

point rotate(real_number theta, const point& p) {
    return point(std::cos(theta) * p.real() + std::sin(-theta) * p.imag(),
                 std::sin(theta) * p.real() + std::cos(-theta) * p.imag());
}
}  // namespace geometry

void func(geometry::point l, geometry::point r, int n) {
    if (n == 0) {
        using namespace geometry;
        std::cout << l << std::endl;
        return;
    }

    geometry::real_number k = 1.0 / 3;
    geometry::point s((l + l + r) * k);
    geometry::point u = s + geometry::rotate(geometry::pi * k, (r - l) * k);
    geometry::point t((l + r + r) * k);

    func(l, s, n - 1);
    func(s, u, n - 1);
    func(u, t, n - 1);
    func(t, r, n - 1);
}

int main() {
    int n;
    std::cin >> n;

    geometry::point l(0, 0), r(100, 0);
    func(l, r, n);
    using namespace geometry;
    std::cout << r << std::endl;
}
