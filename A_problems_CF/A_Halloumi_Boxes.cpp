#include <iostream>
using namespace std;

class weight
{
private:
    int kilo;
    int kilometer;

public:
    weight(int k, int l)
    {
        kilo = k;
        kilometer = l;
    }

    weight operator+(const weight &obj)
    {
        kilo = kilo + obj.kilo;
        kilometer = kilometer + obj.kilometer;

        cout << kilo << endl;
        cout << kilometer << endl;

        return *this;
    }
};

int main()
{
    weight W1(30, 50), W2(20, 40);

    W1 + W2;

    return 0;
}