#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> books;

    for (int i = 0; i < n; i++) {
        string title;
        cin >> title;
        books[title]++;  // 판매 횟수 카운트
    }

    string best;
    int max_count = 0;

    for (auto& p : books) {
        if (p.second > max_count) {
            max_count = p.second;
            best = p.first;
        }
    }

    cout << best << "\n";
    return 0;
}
