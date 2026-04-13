#include <iostream>
#include <string>

using namespace std;

void zaman() {
    string input_num;
    if (cin >> input_num) {
        char last_char = input_num.back();
        cout << last_char << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    zaman();

    return 0;
}

