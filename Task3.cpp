#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <tuple>

const int MAX_P = 1000;
const int MAX_N = 1000 / 2;

template <typename SOME_VECTOR>
void myPrint(const SOME_VECTOR& vec) {
    for (const auto& myTuple : vec) {
        std::cout << "(" << std::get<0>(myTuple) << ", " 
                    << std::get<1>(myTuple) << ", " 
                    << std::get<2>(myTuple) << "), "
                    << std::get<3>(myTuple) << "), ";
    }
    std::cout << "\n";
}

int main() {
    std::map<int, std::vector<std::tuple<int, int, int, int>>> res;
    int best_len = 1;
    int best_p = -1;

    for (int a = 1; a <= MAX_N; ++a) {
        for (int b = a; b <= MAX_N; ++b) {
            double c = std::sqrt(a * a + b * b);
            int ic = static_cast<int>(c);  
            if (c == ic) {
                int p = a + b + ic;
                if (p > MAX_P) {
                    continue;
                }
                res[p].push_back(std::make_tuple(a, b, ic, p));

                int new_len = res[p].size();
                if (new_len > best_len) {
                    best_len = new_len;
                    best_p = p;
                    myPrint(res[p]);
                }
            }
        }
    }

    if (best_p != -1) {
        myPrint(res[best_p]);
        std::cout << "Best length: " << best_len << "\n";
    }

    return 0;
}
