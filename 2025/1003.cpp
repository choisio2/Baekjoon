
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcase;
    cin >> testcase;

    int count_zero[41] = { 0, };
    int count_one[41] = { 0, };

    // 초기값 설정
    count_zero[0] = 1; // fibo(0) -> 0 한번 호출
    count_one[0] = 0;

    count_zero[1] = 0;
    count_one[1] = 1;  // fibo(1) -> 1 한번 호출

    // N=2부터 40까지의 값을 미리 계산
    for (int i = 2; i <= 40; i++) {
        count_zero[i] = count_zero[i - 1] + count_zero[i - 2];
        count_one[i] = count_one[i - 1] + count_one[i - 2];
    }

    for (int i = 0; i < testcase; i++) {
        int n;
        cin >> n;
        // 미리 계산된 값을 바로 출력
        cout << count_zero[n] << " " << count_one[n] << "\n";
    }

    return 0;
}



/* 
시간오류남.......... 이렇게 하면 재귀를 너무 많이 돌기 때문에 
동적으로 문제를 해결해야 함. 
따라서 위처럼 미리 40까지의 피보나치수열을 계산하고 그에 따른 인덱스를 출력해야함. 


#include <iostream>
#include <algorithm> 

using namespace std;

int count0 = 0; 
int count1 = 0; 

int fibo(int n) {
    if (n == 0) {
        count0++; 
        return 0; 
    }
    else if (n == 1) {
        count1++; 
        return 0; 
    }
    else {
        return fibo(n - 1) + fibo(n - 2); 
    }

}


int main() {
    int testcase; 
    int input; 
    
    cin >> testcase; 

    for (int i = 0; i < testcase; i++) {
        cin >> input; 
        fibo(input); 
        cout << count0 << " " << count1 << endl;
        count0 = 0; 
        count1 = 0; 
    }


    return 0;
}


*/
