#include<iostream>
using namespace std;

int main()
{
    int temp;
    cout << "Enter a temperature: ";
    cin >> temp;

    double celsiusToFahrenheit = temp * 1.8 + 32;
    double fahrenheitToCelsius = (temp - 32) / 1.8;

    cout << temp << " degrees Celsius is " << celsiusToFahrenheit << " degrees Fahrenheit" << endl;
    cout << temp << " degrees Fahrenheit is " << fahrenheitToCelsius << " degrees Celsius" << endl;

    return 0;
}
