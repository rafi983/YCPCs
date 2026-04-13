#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        long long prev2 = 0;
        long long prev1 = 0;

        for (int i = 0; i < N; ++i) {
            long long a;
            cin >> a;

            long long cur;
            if (a == -1) {
                cur = prev1;
            } else {
                cur = max(prev1, prev2 + a);
            }

            prev2 = prev1;
            prev1 = cur;
        }
        cout << prev1 << endl;
    }
    return 0;
}

