#include <iostream>

using namespace std;

class Fraction
{
    int numerat;
    int denominat;
public:
    int gcd(int a, int b) const
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify()
    {
        int div = gcd(numerat, denominat);
        numerat /= div;
        denominat /= div;
    }

    Fraction(int num = 0, int den = 1) : numerat(num), denominat(den)
    {
        if (denominat == 0)
        {
            cout << "Denominator = 0!!! \n Now 1." << endl;
            denominat = 1;
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const
    {
        int num = numerat * other.denominat + other.numerat * denominat;
        int den = denominat * other.denominat;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const
    {
        int num = numerat * other.denominat - other.numerat * denominat;
        int den = denominat * other.denominat;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const
    {
        int num = numerat * other.numerat;
        int den = denominat * other.denominat;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) const
    {
        int num = numerat * other.denominat;
        int den = denominat * other.numerat;
        return Fraction(num, den);
    }

    Fraction& operator++()
    {
        numerat += denominat;
        simplify();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        numerat += denominat;
        simplify();
        return temp;
    }

    Fraction& operator--()
    {
        numerat -= denominat;
        simplify();
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        numerat -= denominat;
        simplify();
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Fraction& fraction)
    {
        os << fraction.numerat << "/" << fraction.denominat;
        return os;
    }
};

int main()
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    cout << "Add: " << a + b << endl;
    cout << "Sub: " << a - b << endl;
    cout << "Multi: " << a * b << endl;
    cout << "Divis: " << a / b << endl;

    cout << "Pre increment: " << ++a << endl;
    cout << "Post increment: " << a++ << endl;
    cout << "After post increment: " << a << endl;

    cout << "Pre decrement: " << --a << endl;
    cout << "Post decrement: " << a-- << endl;
    cout << "After post decrement: " << a << endl;

}