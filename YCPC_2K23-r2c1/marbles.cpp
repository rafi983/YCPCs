#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        vector<long long> marbles(N);
        for (int i = 0; i < N; ++i) {
            cin >> marbles[i];
        }

        int Q;
        cin >> Q;

        vector<long long> diff(N + 1, 0);
        for (int i = 0; i < Q; ++i) {
            int A, B;
            long long X;
            cin >> A >> B >> X;
            diff[A] += X;
            if (B + 1 <= N) {
                diff[B + 1] -= X;
            }
        }

        long long current_add = 0;
        for (int i = 0; i < N; ++i) {
            current_add += diff[i];
            marbles[i] += current_add;
        }

        for (int i = 0; i < N; ++i) {
            cout << marbles[i] << (i == N - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}

