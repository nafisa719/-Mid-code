#include <iostream>
#include <string>
using namespace std;

bool isAccepted(string input) {
    // q0 is both start and final state
    for (char ch : input) {
        if (ch == 'a' || ch == 'b') {
            continue;   // stay in q0
        } else {
            return false;   // reject invalid symbols
        }
    }
    return true; // always accept if only a,b
}

int main() {
    string testCases[5] = {
        "ab",     // accepted
        "baab",   // accepted
        "aabb",   // accepted
        "abc",    // rejected (c is invalid)
        "a1b"     // rejected (1 is invalid)
    };

    for (string str : testCases) {
        cout << "Input: \"" << str << "\" -> ";

        if (isAccepted(str)) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }
    }

    return 0;
}
