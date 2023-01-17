# Большое целое число BigInt


## Общая информация
В этой задаче требуется реализовать большое целое число произвольной точности и набор операций над ним.


* = ## Задача

Реализовать большое целое  с заданным интерфейсом (см. раздел “Реализация”). Выбрать способ хранения и изменения размера содержимого.
Вместо malloc использовать new, вместо free использовать delete
Методы строки можно посмотреть здесь: https://en.cppreference.com/w/cpp/string/basic_string 
Тщательно задокументировать публичные члены класса на языке, приближенном к техническому английскому.
Написать юнит-тесты на все публичные методы класса с помощью любой специализированной библиотеки (рекомендуется Google Test Framework http://code.google.com/p/googletest/), либо без оной (на усмотрение преподавателя). Убедиться в полноте покрытия кода тестами (каждая строчка кода должна исполняться хотя бы одним тестом).

* ## Реализация

      class BigInt {
       public:
        BigInt();
        BigInt(int);
        BigInt(std::string); // бросать исключение std::invalid_argument при ошибке
        BigInt(const BigInt&);
        ~BigInt();

        BigInt& operator=(const BigInt&);  //возможно присваивание самому себе!

        BigInt operator~() const;

        BigInt& operator++();
        const BigInt operator++(int) const;
        BigInt& operator--();
        const BigInt operator--(int) const;

        BigInt& operator+=(const BigInt&);
        BigInt& operator*=(const BigInt&);
        BigInt& operator-=(const BigInt&);
        BigInt& operator/=(const BigInt&);
        BigInt& operator^=(const BigInt&);
        BigInt& operator%=(const BigInt&);
        BigInt& operator&=(const BigInt&);
        BigInt& operator|=(const BigInt&);

        BigInt operator+() const;  // unary +
        BigInt operator-() const;  // unary -

        bool operator==(const BigInt&) const;
        bool operator!=(const BigInt&) const;
        bool operator<(const BigInt&) const;
        bool operator>(const BigInt&) const;
        bool operator<=(const BigInt&) const;
        bool operator>=(const BigInt&) const;

        operator int() const;
        operator std::string() const;

        size_t size() const;  // size in bytes
      };

      BigInt operator+(const BigInt&, const BigInt&);
      BigInt operator-(const BigInt&, const BigInt&);
      BigInt operator*(const BigInt&, const BigInt&);
      BigInt operator/(const BigInt&, const BigInt&);
      BigInt operator^(const BigInt&, const BigInt&);
      BigInt operator%(const BigInt&, const BigInt&);
      BigInt operator&(const BigInt&, const BigInt&);
      BigInt operator|(const BigInt&, const BigInt&);
      
      std::ostream& operator<<(std::ostream& o, const BigInt& i);

* ## Повышенная сложность (по желанию):

Реализовать семантику перемещения 
    
    BigInt(BigInt&&); 
    BigInt& operator=(BigInt&&);
    
Реализовать оператор ввода из потока с корректной обработкой ошибок 
    
    std::istream& operator>>(std::istream& o, BigInt& i);
