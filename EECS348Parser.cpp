#include <iostream>
#include <iomanip> 
#include <string>
using namespace std; 

#define EXIT 0
#define DECIMAL_LENGTH 4
#define INVALID_DOUBLE_PRECISION_VALUE -999999.99
#define INPUT_END "END"

double extractNumeric( const string& str );

int main () 
{
    string input;
    while( true ) 
    {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
        
        if( input == INPUT_END ) 
        {
            break;
        }
#if 1
        double number = extractNumeric( input ) ;
        
        if( number != INVALID_DOUBLE_PRECISION_VALUE ) 
        {
            cout << "The input is: " << fixed << setprecision(DECIMAL_LENGTH)
                << number << endl;
        } 
        else 
        {
            cout << "The input is invalid." << endl;
        }
#endif
    }
    return EXIT;
}

double extractNumeric( const string& str )
{
#if 1
    double result = 0.0;
    size_t index = 0;
    bool isNegative = false;

    if( str.empty() ) 
    {
        return INVALID_DOUBLE_PRECISION_VALUE;
    }

    if( str[index] == '-' ) 
    {
        isNegative = true;
        ++index;
    } 
    else if( str[index] == '+' ) 
    {
        ++index;
    }

    double decimalPlace = 0.1;
    bool decimalFound = false;
    bool foundError = false;
    for( ; index < str.length() && !foundError; ++index ) 
    {
        const char& charDigit = str[index];
        if( isdigit( charDigit ) ) 
        {
            const char charDigitValue = charDigit - '0';
            if( decimalFound ) 
            {
                result += charDigitValue * decimalPlace;
                decimalPlace *= 0.1;
            } 
            else 
            {
                result = result * 10 + charDigitValue;
            }
        }
        else if( charDigit == '.' && !decimalFound ) 
        {
            decimalFound = true;
        } 
        else 
        {
            result = INVALID_DOUBLE_PRECISION_VALUE;
            foundError = true;
        }

    }
    return !foundError && isNegative ? -result : result;
#endif
}