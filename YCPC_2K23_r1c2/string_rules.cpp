#include <iostream>
#include <string>

using namespace std;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
    string s;
    cin >> s;

    string result = "";
    int n = s.length();
    int i = 0;

    while (i < n) {
        if (is_digit(s[i])) {
            int count = s[i] - '0';
            i++;
            string temp = "";
            while (i < n && !is_operator(s[i])) {
                temp += s[i];
                i++;
            }
            for (int k = 0; k < count; k++) {
                result += temp;
            }
        } else if (is_operator(s[i])) {
            result += s[i];
            i++;
        } else {
            i++;
        }
    }

    cout << result << endl;

    return 0;
}

