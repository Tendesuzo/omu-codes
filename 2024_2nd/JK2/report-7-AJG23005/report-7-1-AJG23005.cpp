//AJG23005 中 天花
//講義・課題に関するコメント
//割り算をする場合の実装が大変だった。

#include <iostream>
using namespace std;

class Complex {
    double real, imag;

    public:
    Complex() { real = 0, imag = 0; }
    Complex(double a, double b) { real = a, imag = b; }
    void get_real_imag(double &a, double &b) { a = real, b = imag; }
    Complex operator+(Complex ob2);
    Complex operator-(Complex ob2);
    Complex operator*(Complex ob2);
    Complex operator/(Complex ob2);
    int operator==(Complex &ob2) {
        return real == ob2.real && imag == ob2.imag;
    }
};

Complex Complex::operator+(Complex ob2) {
    Complex temp;
    temp.real = real + ob2.real;
    temp.imag = imag + ob2.imag;
    return temp;
}

Complex Complex::operator-(Complex ob2) {
    Complex temp;
    temp.real = real - ob2.real;
    temp.imag = imag - ob2.imag;
    return temp;
}

Complex Complex::operator*(Complex ob2) {
    Complex temp;
    temp.real = real * ob2.real - imag * ob2.imag;
    temp.imag = real * ob2.imag + imag * ob2.real;
    return temp;
}

Complex Complex::operator/(Complex ob2) {
    Complex temp;
    temp.real = (real * ob2.real + imag * ob2.imag) / (ob2.real *ob2.real + ob2.imag *ob2.imag);
    temp.imag = (imag * ob2.real - real * ob2.imag) / (ob2.real *ob2.real + ob2.imag * ob2.imag);
    return temp;
}

int main() {
    Complex o1(10, 10), o2(5, 3), o3;
    double real, imag;

    cout << "o1 = (10, 10)" << endl;
    cout << "o2 = (5, 3)" << endl;

    o3 = o1 + o2;
    o3.get_real_imag(real, imag);
    if(imag>0){
        cout << "o1 + o2 = " << real <<"+" << imag << "i" << endl;
    } else {
        cout << "o1 + o2 = " << real << imag << "i" << endl;
    }

    o3 = o1 - o2;
    o3.get_real_imag(real, imag);
    if(imag>0){
        cout << "o1 - o2 = " << real <<"+" << imag << "i" << endl;
    } else {
        cout << "o1 - o2 = " << real << imag << "i" << endl;
    }

    o3 = o1 * o2;
    o3.get_real_imag(real, imag);
    if(imag>0){
        cout << "o1 * o2 = " << real <<"+" << imag << "i" << endl;
    } else {
        cout << "o1 * o2 = " << real << imag << "i" << endl;
    }

    o3 = o1 / o2;
    o3.get_real_imag(real, imag);
    if(imag>0){
        cout << "o1 / o2 = " << real <<"+" << imag << "i" << endl;
    } else {
        cout << "o1 / o2 = " << real << imag << "i" << endl;
    }

    Complex p1(10, 10), p2(10, 10), p3(10, 20);

    cout << "p1 = (10, 10)" << endl;
    cout << "p2 = (10, 10)" << endl;
    cout << "p3 = (10, 20)" << endl;

    if (p1 == p2) {
        cout << "p1 is equal to p2" << endl;
    } else {
        cout << "p1 is NOT equal to p2" << endl;
    }
    if (p1 == p3) {
        cout << "p1 is equal to p3" << endl;
    } else {
        cout << "p1 is NOT equal to p3" << endl;
    }

    return 0;
}
