#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    int weight;
    double height;
    cin >> weight >> height;

    cout << weight / (height * height);
}