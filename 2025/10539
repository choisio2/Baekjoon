#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    int n, tmp; 
    int sum = 0; 
    int arr[102]; 
    int result; 

    cin >> n; 

    for (int i = 0; i < n; i++) {
        cin >> tmp; 
        result = (tmp * (i+1)) - sum;
        arr[i] = result;
        sum += result; 
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }

    return 0;
}
