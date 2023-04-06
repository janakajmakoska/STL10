#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "MyClass constructor called" << endl;
    }
    ~MyClass() {
        cout << "MyClass destructor called" << endl;
    }
};

int main() {
    try {
        MyClass* ptr = new MyClass();
        throw ptr;
    }
    catch (MyClass* ptr) {
        cout << "Exception caught" << endl;
    }
    return 0;
}
