#include "BigInt.h"
enum{base = 1000000000, maxSelValue = 999999999};
#define cast_int  static_cast<int>
#define cast_ll static_cast<long long>

BigInt::BigInt() : sign(false) {}

void BigInt::isDigitOrSign(char symbol) {
    if((symbol < '0' || symbol > '9') && symbol != '-') {
        throw std::invalid_argument("invalid symbol :(");
    }
}

BigInt::BigInt(int value) {
    auto newValue = cast_ll(value);
    if(newValue < 0) {
        sign = true;
        newValue *= (-1);
    }
    do{
        vecBigInt.push_back(newValue % base);
        newValue /= base;
    }
    while(newValue != 0);
}


BigInt::BigInt(const BigInt& other) {
    this->sign = other.sign;
    for(auto value : other.vecBigInt) {
        this->vecBigInt.push_back(value);
    }
}

BigInt::BigInt(std::string word) {
    int count = 0, digit = 0, degree = 1;

    for(int value  = cast_int(word.size())-1; value >= 0; value--) {
        isDigitOrSign(word[value]);
        if(word[value] == '-') {
            sign = true;
        } else {
            digit = digit + cast_int(word[value] - '0') * degree;
            count++;
            degree *= 10;
        }
        if(count > 8) {
            vecBigInt.push_back(digit);
            count = digit = 0;
            degree = 1;
        }
    }
    if(count > 0) {
        vecBigInt.push_back(digit);
    }
    if(isZero()) sign = false;
}

BigInt::BigInt(BigInt&& other) noexcept{
    this->vecBigInt = other.vecBigInt;
    this->line = other.line;
    this->sign = other.sign;

    other.sign = false;
    other.vecBigInt.clear();
    other.line.clear();
}

BigInt::~BigInt() {
    sign = false;
    vecBigInt.clear();
}

BigInt::operator std::string() const {
    std::string supLine;
    if(sign) supLine += '-';
    if(vecBigInt.empty()) throw std::invalid_argument("vector is nullptr");
    supLine += std::to_string(vecBigInt[vecBigInt.size()-1]);
    int count = 0, index;
    int digit;
    for(index = cast_int(vecBigInt.size() - 2); index >= 0; --index) {
        digit = vecBigInt[index];
        while(digit != 0) {
            digit /= 10;
            count++;
        }
        for(auto i = 0; i < 9-count; ++i) {
            supLine += '0';
        }
        if(count != 0)  supLine+=std::to_string(vecBigInt[index]);
        count = 0;
    }
    return supLine;
}

size_t BigInt::size() const {
    return vecBigInt.size()+1;
}

BigInt::operator int() const {
    int result = 0;
    for(int value : vecBigInt) {
        result = result*base+value;
    }
    if(result < 0) { throw std::invalid_argument("int variable overflow"); }
    if(sign) result *= (-1);
    return result;
}

BigInt BigInt::operator~() const {
    BigInt temp(*this);
    temp.sign = !sign;

    (temp.sign) ? --temp : ++temp;
    return temp;
}

BigInt& BigInt::operator=( BigInt&& other) noexcept {
    this->line.clear();
    this->vecBigInt.clear();

    this->vecBigInt = other.vecBigInt;
    this->line = other.line;
    this->sign = other.sign;

    other.sign = false;
    other.vecBigInt.clear();
    other.line.clear();
    return *this;
}

BigInt& BigInt::operator=(const BigInt& other) {
    if(this == &other) return *this;
    this->vecBigInt.clear();
    this->sign = other.sign;
    for(auto value : other.vecBigInt) {
        this->vecBigInt.push_back(value);
    }
    return *this;
}

bool BigInt::isZero() const{
    for (auto digit: vecBigInt)
        if (digit != 0) return false;

    return true;
}

bool BigInt::isZero() {
    for (auto digit: vecBigInt)
        if (digit != 0) return false;

    return true;
}

BigInt& BigInt::operator++() {
    bool statAddSel = true;
    if(!sign) {
        for(int& digit : vecBigInt) {
            digit++;
            if(digit > maxSelValue) digit = 0;
            else {
                statAddSel = false;
                break;
            }
        }
        if(statAddSel) vecBigInt.push_back(1);
        leadZeros();
        return *this;
    }
    for(auto& digit : vecBigInt) {
        if(digit == 0) digit = maxSelValue;
        else digit--;
        if(isZero()) {
            sign = false;
            break;
        }
    }
    leadZeros();
    return *this;
}

const BigInt BigInt::operator++(int) {
    const BigInt other(*this);
    ++(*this);
    return other;
}

BigInt& BigInt::operator--() {
    bool statAddSel = true;
    if(!sign) {
        for (auto &digit: vecBigInt)
            if (isZero()) {
                sign = true;
                digit++;
            } else if (digit == 0) digit = maxSelValue;
            else digit--;
        leadZeros();
        return *this;
    }
    for(auto& digit : vecBigInt) {
        digit++;
        if(digit > maxSelValue) digit = 0;
        else {
            statAddSel = false;
            break;
        }
    }
    if(statAddSel) vecBigInt.push_back(1);
    leadZeros();
    return *this;
}

const BigInt BigInt::operator--(int) {
    const BigInt other(*this);
    --(*this);
    return other;
}

BigInt BigInt::operator+() const {
    return *this;
}

BigInt BigInt::operator-() const {
    BigInt other(*this);
    other.sign = !(sign);
    return other;
}

bool BigInt::operator==(const BigInt& other) const {
    return (this->vecBigInt == other.vecBigInt && this->sign == other.sign);
}

bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

bool BigInt::operator<(const BigInt& other)  const{
    if(!sign && other.sign) return false;
    else if(sign && !other.sign) return true;
    else if(sign == other.sign && vecBigInt.size() < other.vecBigInt.size()) return !sign;
    else if(sign == other.sign && vecBigInt.size() > other.vecBigInt.size()) return sign;

    for(int i = static_cast<int>(vecBigInt.size()-1); i >= 0; --i) {
        if(vecBigInt[i] > other.vecBigInt[i]) return sign;
        else if(vecBigInt[i] < other.vecBigInt[i]) return !sign;
    }
    return false;
}

bool BigInt::operator>(const BigInt& other) const {
    return !(*this < other || *this == other);
}

bool BigInt::operator<=(const BigInt& other) const {
    return (*this < other || *this == other);
}

bool BigInt::operator>=(const BigInt& other) const {
    return (*this > other || *this == other);
}

BigInt& BigInt::operator+=(const BigInt& other) {
    if(this->vecBigInt.size() < other.vecBigInt.size()) {
        this->vecBigInt.resize(other.vecBigInt.size(), 0);
    }
    long long result = 0;
    if(this->sign == other.sign) {
        for(int i = 0; i < vecBigInt.size(); ++i) {
            if(i >= other.vecBigInt.size())  vecBigInt[i] += result;
            else {
                vecBigInt[i] += other.vecBigInt[i] + result;
            }
            result = 0;
            if(vecBigInt[i] > maxSelValue) {
                result = vecBigInt[i];
                vecBigInt[i] = result % base;
                result /= base;
            }
        }
        if(result != 0) vecBigInt.push_back((int)result);
        return *this;
    }
    this->sign = !this->sign;
    (*this) -= other;
    return *this;
}

BigInt& BigInt::operator -=(const BigInt& other) {
    if(this->vecBigInt.size() < other.vecBigInt.size()) {
        this->vecBigInt.resize(other.vecBigInt.size(), 0);
    }
    if(this->sign != other.sign) {
        bool curSign = this->sign;
        this->sign = !this->sign;
        (*this) += other;
        this->sign = curSign;
        return *this;
    }
    bool statSign = true;
    for(int i = 0; i < this->vecBigInt.size()-1; ++i ) {
        if(i == other.vecBigInt.size()) {
            statSign = false;
            break;
        }
        this->vecBigInt[i] -= other.vecBigInt[i];
        if(this->vecBigInt[i] < 0) this->vecBigInt[i] *= -1;
    }
    if(statSign) {
        vecBigInt[vecBigInt.size()-1] -= other.vecBigInt[vecBigInt.size()-1];
        if(vecBigInt[vecBigInt.size()-1] < 0) {
            this->vecBigInt[vecBigInt.size()-1] *= -1;
            this->sign = true;
        }
    }
    if(isZero()) sign = false;
    return *this;
}
void  BigInt::leadZeros() {
    if(vecBigInt.size() < 2) return;
    for(int i = (int)vecBigInt.size()-1; i>=0; --i) {
        if(vecBigInt[i] == 0) vecBigInt.erase(vecBigInt.end() - 1);
        else break;
    }
}

BigInt& BigInt::operator*=(const BigInt& other) {
    std::vector<int> curVector;
    std::string lineAddZero;
    BigInt suppResult(0), result(0);
    unsigned long long curResult = 0;
    sign = sign != other.sign;
    for(auto& v1 : vecBigInt) {
        for(auto& v2 : other.vecBigInt) {
            curResult  += (unsigned long long)v1 * (unsigned long long)v2;
            curVector.push_back(cast_int(curResult % base));
            curResult /= base;
        }
        if(curResult != 0) curVector.push_back(cast_int(curResult % base));
        suppResult.vecBigInt = curVector;
        suppResult = ((std::string)suppResult + lineAddZero);
        result +=suppResult;
        lineAddZero += "000000000";
        curResult = 0;
        curVector.clear();
    }
    if(this->isZero()) *this = 0;
    this->vecBigInt = result.vecBigInt;
    leadZeros();
    return *this;
}

BigInt BigInt::binSearch(const BigInt& dividend,const BigInt& other) {
    BigInt result(0);
    int mid = 0, left = 0, right = base;
    while(left <= right) {
        mid = (left+right) / 2;
        result = mid;
        if(dividend == result * other) break;
        (dividend > result * other) ? left = mid+1 : right = mid-1;
    }
    BigInt o = result * other;
    while(dividend < result * other) {
        --result;
    }
    return result;
}

BigInt& BigInt::operator/=(const BigInt& other) {
    if(other.isZero()) throw std::invalid_argument("division by zero");
    else if(this->isZero() || (vecBigInt.size() < other.vecBigInt.size())) {
        *this = 0; return *this;
    }
    bool _sign = this->sign;
    this->sign = false;

    BigInt remainder(0),
           result(0),
           curResult(0),
           objNumberSeparator(base), suppObj(other);

    suppObj.sign = false;
    for(int i = static_cast<int>(vecBigInt.size()-1); i >= 0; --i) {
        curResult = objNumberSeparator * remainder;
        remainder = vecBigInt[i];
        remainder += curResult;
        curResult = remainder;
        remainder = binSearch(remainder, suppObj);

        result *= objNumberSeparator;
        result += remainder;
        if(remainder.isZero()) {
            remainder = vecBigInt[i];
        } else {
            remainder = curResult - (suppObj * remainder);
        }
    }
    vecBigInt.clear();
    this->vecBigInt = result.vecBigInt;
    if(_sign && other.sign) {
        this->sign = false;
    } else {
        this->sign = _sign || other.sign;
    }
    return *this;
}

BigInt operator+(const BigInt& v1, const BigInt& v2) {
    BigInt objMain(v1);
    objMain += v2;
    return objMain;
}

BigInt& BigInt::operator%=(const BigInt& other) {
    BigInt suppObj(*this);
    suppObj /= other;
    *this -= suppObj*other;
    leadZeros();
    sign = false;
    return *this;
}

BigInt operator-(const BigInt& v1, const BigInt& v2) {
    BigInt objMain(v1);
    objMain -= v2;
    return objMain;
}

BigInt operator*(const BigInt& v1, const BigInt& v2) {
    BigInt objMain(v1);
    objMain *= v2;
    return objMain;
}

BigInt operator/(const BigInt& v1, const BigInt& v2) {
    BigInt objMain(v1);
    objMain /= v2;
    return objMain;
}

BigInt operator%(const BigInt& v1, const BigInt& v2) {
    BigInt objMain(v1);
    objMain %= v2;
    return objMain;
}

void BigInt::addBitsConvertingComplete(int _size, BigInt& mainObj) {
    for(int i = 0; i < _size; ++i) {\
        if(i == mainObj.line.size()) {
            mainObj.line += (mainObj.sign) ?  "1" : "0";
        }
        else if(mainObj.sign) {
            mainObj.line[i] = (mainObj.line[i] == '0') ? '1' : '0';
        }
    }
}

void BigInt::transferFromTenToTwo(BigInt& mainObj) {
    BigInt tempObj(mainObj), suppObj(tempObj), devObj(2);
    while(!tempObj.isZero()) {
        suppObj = tempObj;
        tempObj /= devObj;
        suppObj %= devObj;
        mainObj.line += (suppObj.isZero()) ? "0" : "1";
    }
}

void BigInt::transferFromTwoToTen() {
    BigInt result(0), devObj(1);
    for(char symbol : line) {
        if(symbol != 48) result += devObj;
        devObj *= 2;
    }
    vecBigInt = result.vecBigInt;
}

void BigInt::generalToBinaryOperator(const BigInt& other, const std::function<void(BigInt&, BigInt&, int size)>& binOperator) {
    BigInt  suppOther(other);
    this->line.clear();
    suppOther.line.clear();

    if(this->sign){
        ++(*this);
        sign = true;
    }
    if(other.sign) {
        ++suppOther;
        suppOther.sign = true;
    }

    transferFromTenToTwo(*this);
    transferFromTenToTwo(suppOther);

    int _size = static_cast<int>((line.size() > suppOther.line.size()) ? line.size() : suppOther.line.size());
    addBitsConvertingComplete(_size, *this);
    addBitsConvertingComplete(_size, suppOther);

    binOperator(*this, suppOther, _size);

    if(this->sign) {
        addBitsConvertingComplete(_size, *this);
    }
    transferFromTwoToTen();
    if(this->sign) --(*this);
}

BigInt& BigInt::operator&=(const BigInt& other) {
    std::function<void(BigInt&, BigInt&, int size)> BinOperatorAND;
    BinOperatorAND = [](BigInt& thisObj, BigInt& suppObj, int _size) {
        for(int i = 0; i < _size; ++i) {
            if(thisObj.line[i] != suppObj.line[i]) thisObj.line[i] = '0';
        }
        thisObj.sign = thisObj.sign && suppObj.sign;
    };
    generalToBinaryOperator(other, BinOperatorAND);

    return *this;
}

BigInt& BigInt::operator|=(const BigInt& other) {
    std::function<void(BigInt&, BigInt&, int size)> BinOperatorOR;
    BinOperatorOR = [](BigInt& thisObj, BigInt& suppObj, int _size) {
        for(int i = 0; i < _size; ++i) {
            if(suppObj.line[i] == '1') thisObj.line[i] = '1';
        }
        thisObj.sign = thisObj.sign || suppObj.sign;
    };
    generalToBinaryOperator(other, BinOperatorOR);

    return *this;
}


BigInt& BigInt::operator^=(const BigInt& other) {
    std::function<void(BigInt&, BigInt&, int size)> BinOperatorOR;
    BinOperatorOR = [](BigInt& thisObj, BigInt& suppObj, int _size) {
        for(int i = 0; i < _size; ++i) {
            thisObj.line[i] = (suppObj.line[i] != thisObj.line[i]) ? '1' : '0';
        }
        thisObj.sign = (thisObj.sign != suppObj.sign);
    };
    generalToBinaryOperator(other, BinOperatorOR);

    return *this;
}

BigInt operator^(const BigInt& v1, const BigInt& v2) {
    BigInt obj(v1);
    obj ^= v2;
    return obj;
}

BigInt operator&(const BigInt& v1, const BigInt& v2) {
    BigInt obj(v1);
    obj &= v2;
    return obj;
}

BigInt operator|(const BigInt& v1, const BigInt& v2) {
    BigInt obj(v1);
    obj |= v2;
    return obj;
}

std::ostream& operator<<(std::ostream& o,  BigInt& i) {
    return  o << (std::string)i;
}
