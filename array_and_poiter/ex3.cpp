
#include <iostream>
using namespace std;

// (a+bi) + (c+di) = (a+c) + (b+d)i
// (a+bi)(c+di) = (ac−bd) + (ad+bc)i

struct Complex {
    double real;
    double image;
}; // nhớ dấu chấm phẩy ở cuối

Complex add(Complex x, Complex y) {
    Complex result;
    result.real = x.real + y.real;
    result.image = x.image + y.image;
    return result;
}

Complex multiply(Complex x, Complex y) {
    Complex result;
    result.real = x.real * y.real - x.image * y.image;
    result.image = x.real * y.image + x.image * y.real;
    return result;
}

void output(Complex z) {
    cout << z.real << " " << z.image;
}

int main() {
    Complex a = {2, 3};
    Complex b = {5, 6};

    Complex sum = add(a, b);
    Complex multiplyResult = multiply(a, b);

    cout << "a + b = ";
    output(sum);
    cout << endl;

    cout << "a * b = ";
    output(multiplyResult);
    cout << endl;
    return 0;
}