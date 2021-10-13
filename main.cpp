#include <iostream>
#include <tuple>

using namespace std;

auto f1 = [](int x){return 20 - abs(x);};
auto f2 = [](int i){return (2 * (i % 2) - 1) * i / 2;};

auto obliczenia = [](auto f1, auto f2, int n) {
    int max_x = f2(0);
    int max_y = f1(max_x);
    for(int i = 1; i < n; i++) {
        int x = f2(i);
        int y = f1(x);
        if (y > max_y) {
            max_x = x;
            max_y = y;
        }
    }
    int max[2] = {max_x, max_y};
    cout << max[0] << " : " << max[1];
};

int main() {
    obliczenia(f1, f2, 10);
    return 0;
}
