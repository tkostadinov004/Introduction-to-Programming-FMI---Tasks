#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    cout << "Menu:" << endl;
    cout << "1. Calculate BMI" << endl;
    cout << "2. Convert Temperature" << endl;
    cout << "3. Display Information" << endl;
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You chose option 1: BMI Calculator" << endl;
        int weight;
        double height;
        cout << "Enter your weight in kilograms: ";
        cin >> weight;
        cout << "Enter your height in meters and centimeters: ";
        cin >> height;

        double bmi;
        bmi = weight / (height * height);
        cout << "Your BMI is: " << bmi << endl;
        break;
    case 2:
        cout << "Choose the type of conversion:" << endl;
        cout << "1. Miles to Kilometers" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;
        cout << "Enter your choice (1-2): ";

        cin >> choice;
        switch (choice)
        {
        case 1: {
            cout << "You chose option 1: Miles to Kilometers." << endl;
            cout << "Enter the distance in miles: ";

            int miles;
            cin >> miles;

            double kilometers = miles * 1.609;
            cout << miles << " miles is equal to " << kilometers << " kilometers.";
            break;
        }
        case 2:
            cout << "You chose option 2. Fahrenheit to Celsius" << endl;
            cout << "Enter degrees in Fahrenheit: ";

            int fahrenheit;
            cin >> fahrenheit;

            double celsius = (fahrenheit - 32) / 1.8;
            cout << fahrenheit << " degrees Fahrenheit is equal to " << celsius << " degrees celsius.";
            break;
        }
        break;
    case 3:
        cout << "Information";
        break;
    }
}