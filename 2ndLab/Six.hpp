#ifndef SIX_HPP
#define SIX_HPP

#include <exception>
#include <iostream>

void removeFirstZero(std::string &str);
bool checkSix(std::string &number);

class Six {
public:
    Six();                           // Стандартный
    Six(const std::string &number);  // С инициализацией
    Six(const Six &other);           // Копирования
    Six(Six &&other) noexcept;       // Перемещения
    ~Six() noexcept;

    Six(const std::initializer_list<unsigned char> &list);

    std::string getNumber() const;
    int getSize() const;

    friend std::ostream &operator<<(std::ostream &os, const Six &obj);

    Six &operator=(const Six &other);
    Six &operator=(Six &&other);

    bool operator==(const Six &other);
    bool operator!=(const Six &other);
    bool operator>(const Six &other);
    bool operator<(const Six &other);
    bool operator>=(const Six &other);
    bool operator<=(const Six &other);

    Six operator+(const Six &other) const;
    Six operator-(const Six &other) const;
    Six &operator+=(const Six &other);
    Six &operator-=(const Six &other);

private:
    unsigned char *number;
    int size;
};

#endif