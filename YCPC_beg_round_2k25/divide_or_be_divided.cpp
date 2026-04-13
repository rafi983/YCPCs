#include <iostream>
#include <string>

int main() {
    int n, x, y;
    if (!(std::cin >> n >> x >> y)) return 0;

    std::string s;
    std::cin >> s;

    int dx = s[x - 1] - '0';
    int dy = s[y - 1] - '0';

    bool ok = false;
    if (dy != 0 && dx % dy == 0) ok = true;
    if (dx != 0 && dy % dx == 0) ok = true;

    std::cout << (ok ? "YES" : "NO");

    return 0;
}

