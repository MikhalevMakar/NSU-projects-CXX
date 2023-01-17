#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Vector {
    int x, y, z;
public:
    
    Vector();
    
    Vector(int x, int y, int z);
    
    Vector operator +(const Vector &supV);
    
    void operator =(const Vector &supV);
    
    Vector operator ++();

    Vector operator ++(int decrement);
    
    Vector& operator +=(const Vector &v);
    
    bool operator < (const Vector &v);
    
    friend  ostream& operator << (ostream &s, const Vector &v);
};

int main()
{
    vector<int> vcr;
    Vector a(2,1,1);
    Vector b(3, 4, 6);
    Vector c;
    
    c = a + b;
    c +=a;
    cout << (c < a) << endl;
    cout << a;
    return 0;
}

void Vector::operator =(const Vector &supV)
{
    this->x = supV.x;
    this->y = supV.y;
    this->z = supV.z;
}

Vector::Vector(int x, int y, int z) : x(x), y(y), z(z)
{
    cout << this->x << " " << this->y << " " << this->z << endl;
}

Vector Vector::operator ++(int decrement)
{
    return Vector(this->x++, this->y++, this->z++);
}

bool Vector::operator < (const Vector &v)
{
    double vT1 = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
    double vT2 = sqrt(pow(this->x, 2) + pow(this->y, 3) + pow(this->z, 2));
    return vT2 < vT1;
}

ostream& operator << (ostream &s, const Vector &v)
{
    s << v.x << " "  << v.y << " " << v.z << endl;
    return s;
}

Vector& Vector::operator +=(const Vector &v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *(this);
}

Vector Vector::operator ++()
{
    return Vector(++this->x, ++this->y, ++this->z);
}

Vector Vector::operator +(const Vector &supV)
{
    return Vector(this->x+supV.x, this->y+supV.y, this->z+supV.z);
}

Vector::Vector():x(0), y(0), z(0)
{
    cout << this->x << " " << this->y << " " << this->z << endl;
}

