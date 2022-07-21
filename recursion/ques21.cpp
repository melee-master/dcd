#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;

void printSubsequences(string inp, string out = "") {
    if (inp.size() == 0) {
        res.push_back(out);
        return;
    }

    string ros = inp.substr(1);
    char ch = inp[0];

    printSubsequences(ros, out);
    printSubsequences(ros, out + ch);
}

int main() {
    int t ;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        printSubsequences(s);

        sort(res.begin(), res.end());

        for (int i=0; i<res.size(); i++) {
            cout << res[i] << endl;
        }

        res.clear();
    }

    return 0;
}