#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>


using namespace std;


bool is_in_board(pair<int, int> pos) {
    return pos.first >= 0 && pos.first < 8 && pos.second >= 0 && pos.second < 8;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 이동 방향에 따른 좌표변화량을 map에 저장
    map<string, pair<int, int>> moves; 
    moves["R"] = { 1,0 }; 
    moves["L"] = { -1, 0 }; 
    moves["B"] = { 0, -1 };
    moves["T"] = { 0, 1 };
    moves["RT"] = { 1, 1 };
    moves["LT"] = { -1, 1 };
    moves["RB"] = { 1, -1 };
    moves["LB"] = { -1, -1 };

    // 초기 위치 입력받기 
    string king_str, stone_str; 
    int n; 
    cin >> king_str >> stone_str >> n; 

    // 입력받은 체스 좌표를 숫자로 변경
    pair<int, int> king_pos = { king_str[0] - 'A', king_str[1] - '1' }; 
    pair<int, int> stone_pos = { stone_str[0] - 'A', stone_str[1] - '1' };


    for (int i = 0; i < n; i++) {
        string direction; 
        cin >> direction; 

        pair<int, int> move = moves[direction];

        pair<int, int> king_next = { king_pos.first + move.first, king_pos.second + move.second };

        if (is_in_board(king_next)) {
            // 킹의 다음 위치가 돌의 현재 위치와 겹치는지 확인
            if (king_next == stone_pos) {
                // 돌의 예상 다음 위치 계산
                pair<int, int> stone_next = { stone_pos.first + move.first, stone_pos.second + move.second };

                // 돌의 다음 위치가 체스판 안인지 확인
                if (is_in_board(stone_next)) {
                    // 모든 조건 통과 -> 킹과 돌 모두 이동
                    king_pos = king_next;
                    stone_pos = stone_next;
                }
            }
            else {
                // 돌과 겹치지 않으면 킹만 이동
                king_pos = king_next;
            }
        }
    }

    cout << (char)(king_pos.first + 'A') << (char)(king_pos.second + '1') << "\n";
    cout << (char)(stone_pos.first + 'A') << (char)(stone_pos.second + '1') << "\n";
        
}
