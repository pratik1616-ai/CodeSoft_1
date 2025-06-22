#include <iostream>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        if (cin >> number) {
            return number;
        } else {
            cout << "Invalid input! Please enter a valid number." << endl;
            clearInputBuffer();
        }
    }
}

char getOperation() {
    char op;
    while (true) {
        cout << "Choose operation (+, -, *, /): ";
        cin >> op;
        
        if (op == '+' || op == '-' || op == '*' || op == '/') {
            return op;
        } else {
            cout << "Invalid operation! Please choose +, -, *, or /" << endl;
        }
    }
}

void performCalculation(double num1, double num2, char operation) {
    double result;
    bool validCalculation = true;
    
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;
            
        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;
            
        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;
            
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Cannot divide by zero!" << endl;
                validCalculation = false;
            }
            break;
            
        default:
            cout << "Error: Unknown operation!" << endl;
            validCalculation = false;
    }
    
    if (validCalculation) {
        cout << "Calculation completed successfully!" << endl;
    }
}

int main() {
    cout << "=== SIMPLE CALCULATOR ===" << endl;
    cout << "This calculator can perform basic arithmetic operations." << endl;
    
    char continueCalc;
    
    do {
        cout << "\n--- New Calculation ---" << endl;
 
        double firstNumber = getNumber("Enter the first number: ");

        char operation = getOperation();
       
        double secondNumber = getNumber("Enter the second number: ");
        
  
        cout << "\nResult:" << endl;
        performCalculation(firstNumber, secondNumber, operation);
        
     
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> continueCalc;
        
    } while (continueCalc == 'y' || continueCalc == 'Y');
    
    cout << "Thank you for using the calculator! Goodbye!" << endl;
    
    return 0;
}