#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    char yearType;
    int p, h;
    cin >> yearType >> p >> h;

    double freeWeekends = 0.75 * (48 - h);
    double holidayGames = 2 / 3.0 * p;
    double games = freeWeekends + h + holidayGames;
    if (yearType == 'L') {
        games *= 1.15;
    }
    cout << (int)games;
}