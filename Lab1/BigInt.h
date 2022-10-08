#ifndef BigInt_hpp
#define BigInt_hpp
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <functional>

class BigInt {
public:
    BigInt();
    BigInt(int);
    BigInt(std::string word);
    BigInt(const BigInt& other);
    BigInt(BigInt&& other) noexcept;
    ~BigInt();

    operator std::string() const;
    size_t size() const;
    operator int() const;

    BigInt& operator=(const BigInt& other);
    BigInt& operator=(BigInt&& other) noexcept;
    BigInt operator~() const;

    BigInt& operator++();
    const BigInt operator++(int);
    BigInt& operator--();
    const BigInt operator--(int);

    BigInt& operator+=(const BigInt& other);
    BigInt& operator*=(const BigInt& other);
    BigInt& operator-=(const BigInt& other);
    BigInt& operator/=(const BigInt& other);
    BigInt& operator^=(const BigInt& other);
    BigInt& operator%=(const BigInt& other);
    BigInt& operator&=(const BigInt& other);
    BigInt& operator|=(const BigInt& other);

    BigInt operator+() const;
    BigInt operator-() const;

    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;

private:
    bool sign = false;
    std::vector<int> vecBigInt;
    std::string line;
    static void transferFromTenToTwo(BigInt& mainObj);
    void transferFromTwoToTen();
    static void addBitsConvertingComplete(int _size, BigInt& mainObj);
    static void isDigitOrSign(char symbol);
    void  leadZeros();
    bool isZero() const;
    bool isZero();
    void generalToBinaryOperator(const BigInt& suppOther, const std::function<void(BigInt&, BigInt&, int size)>& binOperator);
    BigInt binSearch(const BigInt& dividend,const BigInt& other);
};

BigInt operator+(const BigInt& v1, const BigInt& v2);
BigInt operator-(const BigInt& v1, const BigInt& v2);
BigInt operator*(const BigInt& v1, const BigInt& v2);
BigInt operator/(const BigInt& v1, const BigInt& v2);
BigInt operator%(const BigInt& v1, const BigInt& v2);
BigInt operator^(const BigInt& v1, const BigInt& v2);
BigInt operator&(const BigInt& v1, const BigInt& v2);
BigInt operator|(const BigInt& v1, const BigInt& v2);


std::ostream& operator<<(std::ostream& o,  BigInt& i);

#endif /* BigInt_hpp */


