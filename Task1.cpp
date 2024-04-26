#include <vector>
#include <array>
#include <iostream>

using namespace std;

template<typename T>
double average(const T& values)
{
    double sum{ 0.0 };
    for (auto& value : values) {
        sum += value;
    }
    return sum / values.size();
}

int main()
{
    vector<double> values1{ 1.1, 2.2, 3.3, 4.4 };
    cout << average(values1) << endl;

    array<double, 4> values2{ 1.1, 2.2, 3.3, 4.4 };
    cout << average(values2) << endl;

    return 0;
}
