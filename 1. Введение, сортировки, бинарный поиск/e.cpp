#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iomanip>


int main() {
	double a, b, c, d,p,q,Q,alpha,beta,y,x;
	std::cin >> a >> b >> c >> d;
	p = (3 * a * c - b * b) / (3 * a * a);
	q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
	Q = (p / 3) * (p / 3) * (p / 3) + (q / 2) * (q / 2);

	assert(Q >= 0);
	if (Q < 0) {
		Q = 0;
	}
	alpha = std::cbrt(-q / 2 + std::sqrt(Q));
	beta = std::cbrt(-q / 2 - std::sqrt(Q));
	
	y = alpha + beta;
	x = y - b / (3 * a);

    std::cout << std::fixed;
    std::cout << std::setprecision(4);
	std::cout << x;

	return 0;
}