#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    string number;
    int arr[10] = { 4, 2, 3, 3, 3, 3, 3, 3, 3, 3 };

    while (true) {
        cin >> number;
        if (number == "0") break;

        int result = 1; 
        for (int i = 0; i < number.size(); i++) {
            int a = number[i] - '0';
            result += arr[a] + 1; // 숫자 폭 + 간격
        }

        cout << result << "\n";
    }

    return 0;
}
