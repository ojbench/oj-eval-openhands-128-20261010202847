#include <bits/stdc++.h>
// Updated comment for new commit
// Final version before submission
// Ready for final submission
// End of file comment
using namespace std;

bool checkWin(const vector<string>& b, char p) {
    // rows
    for (int i = 0; i < 3; ++i) {
        if (b[i][0] == p && b[i][1] == p && b[i][2] == p) return true;
    }
    // cols
    for (int j = 0; j < 3; ++j) {
        if (b[0][j] == p && b[1][j] == p && b[2][j] == p) return true;
    }
    // diagonals
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p) return true;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(3);
    for (int i = 0; i < 3; ++i) {
        if(!(cin >> board[i])) return 0; // no input
        if(board[i].size()!=3){
            // invalid format, but treat as invalid board
        }
    }
    int cntX = 0, cntO = 0;
    for (auto &row: board) {
        for (char c: row) {
            if (c == 'x') ++cntX;
            else if (c == 'o') ++cntO;
        }
    }
    bool winX = checkWin(board, 'x');
    bool winO = checkWin(board, 'o');
    // validity checks
    bool valid = true;
    if (!(cntX == cntO || cntX == cntO + 1)) valid = false;
    if (winX && winO) valid = false;
    if (winX && cntX != cntO + 1) valid = false;
    if (winO && cntX != cntO) valid = false;
    if (!valid) {
        cout << "invalid\n";
        return 0;
    }
    if (winX) {
        cout << "win\n";
    } else if (winO) {
        cout << "lose\n";
    } else {
        if (cntX + cntO == 9) cout << "tie\n";
        else cout << "ongoing\n";
    }
    return 0;
}
// final commit
