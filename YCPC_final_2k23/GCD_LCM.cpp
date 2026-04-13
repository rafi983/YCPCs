#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

std::ostream& operator<<(std::ostream& os, __int128 n) {
    if (n == 0) return os << "0";
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

const int MAX_VAL_LIMIT = 1000005;
long long cnt[MAX_VAL_LIMIT + 1];
__int128 ans[MAX_VAL_LIMIT + 1];

void solve_optimized(int n, const vector<int>& a, int max_val) {
    for (int x : a) {
        cnt[x]++;
    }

    for (int g = max_val; g >= 1; --g) {
        __int128 sum_linear = 0;
        __int128 sum_sq = 0;

        for (int k = g; k <= max_val; k += g) {
            if (cnt[k] > 0) {
                long long term = k / g;
                sum_linear += (__int128)cnt[k] * term;
                sum_sq += (__int128)cnt[k] * term * term;
            }
        }

        __int128 sum_pairs = (sum_linear * sum_linear - sum_sq) / 2;
        ans[g] = sum_pairs;

        for (int k = 2 * g; k <= max_val; k += g) {
            long long k_val = k / g;
            ans[g] -= (__int128)k_val * k_val * ans[k];
        }
    }

    __int128 total_sum = 0;
    for (int g = 1; g <= max_val; ++g) {
        total_sum += ans[g];
    }
    cout << total_sum << endl;
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve_brute(int n, const vector<int>& a) {
    __int128 total_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long g = gcd(a[i], a[j]);
            __int128 term = ((__int128)a[i] * a[j]) / (g * g);
            total_sum += term;
        }
    }
    cout << total_sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        int max_val = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            max_val = max(max_val, a[i]);
        }

        if (max_val <= MAX_VAL_LIMIT) {
            solve_optimized(n, a, max_val);
        } else {
            solve_brute(n, a);
        }
    }
    return 0;
}

