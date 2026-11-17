
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> freq;
    int n;
    cin >> n;

    vector<vector<string>> words;

    while (n--) {
        string s;
        cin >> s;

        vector<string> tokens;

        for (char x : s) {
            tokens.push_back(string(1, x));
        }

        for (int i = 1; i < tokens.size(); i++) {
            string t = tokens[i - 1] + tokens[i];
            freq[t]++;
        }

        words.push_back(tokens);
    }

    string op;
    int maxFreq = 0;

    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            op = it.first;
        }
    }

    if (op.empty()) {
        cout << "No pair available\n";
        return 0;
    }

    for (auto &elem : words) {
        vector<string> merged;

        for (int i = 0; i < elem.size();) {

            if (i + 1 < elem.size() && elem[i] + elem[i + 1] == op) {
                merged.push_back(op);
                i += 2;
            }
            else {
                merged.push_back(elem[i]);
                i++;
            }
        }

        elem = move(merged);
    }

    cout << "\nUpdated corpus:\n";

    for (auto &word : words) {
        for (auto &token : word) {
            cout << "[" << token << "] ";
        }
        cout << '\n';
    }

    return 0;
}
