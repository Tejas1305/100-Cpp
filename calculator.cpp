#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class ScientificCalculator {
public:
    // Basic Operations
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b == 0) throw runtime_error("Error: Division by zero!");
        return a / b;
    }
    int modulo(int a, int b) {
        if (b == 0) throw runtime_error("Error: Modulo by zero!");
        return a % b;
    }

    // Advanced Functions
    double power(double base, double exp) { return pow(base, exp); }
    double logarithm(double value) {
        if (value <= 0) throw runtime_error("Error: Logarithm of non-positive number!");
        return log(value);
    }
    double sine(double angle) { return sin(angle); }
    double cosine(double angle) { return cos(angle); }
    double tangent(double angle) {
        if (cos(angle) == 0) throw runtime_error("Error: tan(angle) is undefined!");
        return tan(angle);
    }
};

int main() {
    ScientificCalculator calc;
    double num1, num2;
    char operation;

    cout << "Enter an operation (+, -, *, /, ^ for power, l for log, s for sin, c for cos, t for tan): ";
    cin >> operation;

    if (operation == 's' || operation == 'c' || operation == 't') {
        cout << "Enter angle in radians: ";
        cin >> num1;
        if (operation == 's') cout << "sin(" << num1 << ") = " << calc.sine(num1) << endl;
        if (operation == 'c') cout << "cos(" << num1 << ") = " << calc.cosine(num1) << endl;
        if (operation == 't') cout << "tan(" << num1 << ") = " << calc.tangent(num1) << endl;
    }
    else {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        try {
            if (operation == '+') cout << "Result: " << calc.add(num1, num2) << endl;
            else if (operation == '-') cout << "Result: " << calc.subtract(num1, num2) << endl;
            else if (operation == '*') cout << "Result: " << calc.multiply(num1, num2) << endl;
            else if (operation == '/') cout << "Result: " << calc.divide(num1, num2) << endl;
            else if (operation == '^') cout << "Result: " << calc.power(num1, num2) << endl;
            else cout << "Invalid operation!" << endl;
        } catch (runtime_error &e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}