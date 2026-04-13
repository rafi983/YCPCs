#include <iostream>

using namespace std;

const int BUFFER_SIZE = 1 << 16;
char buffer[BUFFER_SIZE];
int buffer_pos = 0, buffer_len = 0;

inline char get_char() {
    if (buffer_pos >= buffer_len) {
        cin.read(buffer, BUFFER_SIZE);
        buffer_len = cin.gcount();
        buffer_pos = 0;
        if (buffer_len == 0) return EOF;
    }
    return buffer[buffer_pos++];
}

inline void fast_scan(int &number) {
    char c = get_char();
    number = 0;
    // Skip non-digits
    while (c < '0' || c > '9') {
        if (c == EOF) return;
        c = get_char();
    }
    // Read digits
    while (c >= '0' && c <= '9') {
        number = (number * 10) + (c - '0');
        c = get_char();
    }
}

void solve() {
    int N;
    fast_scan(N);

    bool has_odd = false;
    bool has_even = false;
    int a;

    for (int i = 0; i < N; ++i) {
        fast_scan(a);

        if (has_odd && has_even) continue;

        if (a & 1) {
            has_odd = true;
        } else {
            has_even = true;
        }
    }

    if (has_odd && has_even) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    fast_scan(T);
    while (T--) {
        solve();
    }
    return 0;
}
