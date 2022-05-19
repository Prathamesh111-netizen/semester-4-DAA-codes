#include <bits/stdc++.h>
using namespace std;

int n = 3;
bool check(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) {
        return false;
    }
    return true;
}
void swap(int x1, int y1, int x2, int y2, vector<vector<int>>&arr) {
    int temp = arr[x1][y1];
    arr[x1][y1] = arr[x2][y2];
    arr[x2][y2] = temp;
}
void solve() {
// int n = 3;
    vector<vector<int>>given = {{1, 2, 3}, {0, 4, 6}, {7, 5, 8}}, actual = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    int blank_x = 1, blank_y = 0, cost = 0, level = 1;
    bool leftused = false, rightused = false, upused = false, downused = false;
    while (true) {
        int l = INT_MAX, r = INT_MAX, u = INT_MAX, d = INT_MAX;
        if (given == actual) {
            break;
        }
        //left
        if (check(blank_x, blank_y - 1) && !rightused) {
            swap(blank_x, blank_y, blank_x, blank_y - 1, given);
            l = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (given[i][j] != actual[i][j]) {
                        l++;
                    }
                }
            }
            swap(blank_x, blank_y, blank_x, blank_y - 1, given);
        }
        //right
        if (check(blank_x, blank_y + 1) && !leftused) {
            r = 0;
            swap(blank_x, blank_y, blank_x, blank_y + 1, given);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (given[i][j] != actual[i][j]) {
                        r++;
                    }
                }
            }
            swap(blank_x, blank_y, blank_x, blank_y + 1, given);
        }
        //up
        if (check(blank_x - 1, blank_y) && !downused) {
            u = 0;
            swap(blank_x, blank_y, blank_x - 1, blank_y , given);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (given[i][j] != actual[i][j]) {
                        u++;
                    }
                }
            }
            swap(blank_x, blank_y, blank_x - 1, blank_y , given);
        }
        //down
        if (check(blank_x + 1, blank_y) && !upused) {
            d = 0;
            swap(blank_x, blank_y, blank_x + 1, blank_y , given);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (given[i][j] != actual[i][j]) {
                        d++;
                    }
                }
            }
            swap(blank_x, blank_y, blank_x + 1, blank_y, given);
        }
        // debug(l)
        // debug(r)
        // debug(u)
        // debug(d)
        l += level;
        r += level;
        u += level;
        d += level;
        if (min({l, r, u, d}) == l) {
            //bring the blank to left
            int temp = given[blank_x][blank_y - 1];
            given[blank_x][blank_y - 1] = given[blank_x][blank_y];
            given[blank_x][blank_y] = temp;
            blank_y--;
            leftused = true;
            rightused = false;
            upused = false;
            downused = false;
        } else if (min({l, r, u, d}) == r) {
            //bring the blank to right
            int temp = given[blank_x][blank_y + 1];
            given[blank_x][blank_y + 1] = given[blank_x][blank_y];
            given[blank_x][blank_y] = temp;
            blank_y++;
            rightused = true;
            leftused = false;
            upused = false;
            downused = false;
        } else if (min({l, r, u, d}) == u) {
            //bring the blank to up
            int temp = given[blank_x - 1][blank_y];
            given[blank_x - 1][blank_y] = given[blank_x][blank_y];
            given[blank_x][blank_y] = temp;
            blank_x--;
            upused = true;
            leftused = false;
            rightused = false;
            downused = false;
        } else if (min({l, r, u, d}) == d) {
            //bring the blank down
            int temp = given[blank_x + 1][blank_y];
            given[blank_x + 1][blank_y] = given[blank_x][blank_y];
            given[blank_x][blank_y] = temp;
            blank_x++;
            downused = true;
            leftused = false;
            rightused = false;
            upused = false;
        }
        cost = min({l, r, u, d});
        level++;
        //debug(given)
    }
    cout << cost << endl;
}
int main() {

    solve();
    return 0;
}