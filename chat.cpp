#include <map>
#include <iostream>

using namespace std;

int fun(int x, int y, std::map<std::pair<int, int>, int> &memo) {
    auto it = memo.find({x, y});
    if (it != memo.end()) return it->second;

    int result;
    if (x == 0) {
        if (y == 0) {
            result = 1;
        } else {
            result = fun(1, y-1, memo);
        }
    } else if (y == 0) {
        result = x + 1;
    } else {
        cout << " CHOOSe " << endl;
        result = fun(x-1, fun(x-1, y-1, memo), memo);
    }
    memo[{x, y}] = result;
    return result;
}

int main() {
    std::map<std::pair<int, int>, int> memo;
    int x = 5, y = 5;
    printf("fun(%d, %d) = %d\n", x, y, fun(x, y, memo));
    return 0;
}