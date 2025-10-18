#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<double> coeffs; // coeffs[i] = coefficient for x^i

public:
    // constructor with degree input
    Polynomial(int degree) {
        coeffs.resize(degree + 1);
        cout << "enter coefficients from highest degree to lowest\n";
        for (int i = degree; i >= 0; --i)
            cin >> coeffs[i];
    }

    // add two polynomials
    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(coeffs.size(), other.coeffs.size());
        Polynomial result(0);
        result.coeffs.assign(maxDegree, 0.0);

        for (int i = 0; i < maxDegree; ++i) {
            double a = (i < coeffs.size()) ? coeffs[i] : 0.0;
            double b = (i < other.coeffs.size()) ? other.coeffs[i] : 0.0;
            result.coeffs[i] = a + b;
        }
        return result;
    }

    // subtract two polynomials
    Polynomial subtract(const Polynomial& other) const {
        int maxDegree = max(coeffs.size(), other.coeffs.size());
        Polynomial result(0);
        result.coeffs.assign(maxDegree, 0.0);

        for (int i = 0; i < maxDegree; ++i) {
            double a = (i < coeffs.size()) ? coeffs[i] : 0.0;
            double b = (i < other.coeffs.size()) ? other.coeffs[i] : 0.0;
            result.coeffs[i] = a - b;
        }
        return result;
    }

    // print polynomial (highest degree to lowest)
    void print() const {
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            if (coeffs[i] >= 0 && i != coeffs.size() - 1)
                cout << "+";
            cout << coeffs[i];
            if (i > 0)
                cout << "x^" << i << " ";
        }
        cout << endl;
    }
};

int main() {
    int degree1, degree2;
    cout << "degree of first poly: ";
    cin >> degree1;
    Polynomial p1(degree1);

    cout << "degree of second poly: ";
    cin >> degree2;
    Polynomial p2(degree2);

    cout << "\nfirst poly: ";
    p1.print();

    cout << "second poly: ";
    p2.print();

    Polynomial sum = p1.add(p2);
    Polynomial diff = p1.subtract(p2);

    cout << "\nsum: ";
    sum.print();

    cout << "difference: ";
    diff.print();

    return 0;
}
