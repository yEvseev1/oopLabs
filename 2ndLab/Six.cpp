#include "Six.hpp"

void removeFirstZero(std::string &str) {
    int pos = 0;
    for (int i = 0; i < str.length(); i++) {
        pos += 1;
        if (str[i] != '0') break;
        str = str.substr(pos);
    }
}

bool checkSix(const std::string &number) {
    for (int i = 0; i < number.length(); i++) {
        if (number[i] < '0' || number[i] > '5') return false;
    }
    return true;
}

Six::Six() {
    size = 0;
    number = nullptr;
}

Six::Six(const std::string &number) {
    if (!checkSix(number)) throw std::invalid_argument("It`s not six number");

    std::string temp = number;
    removeFirstZero(temp);

    size = temp.size();
    this->number = new unsigned char[size];
    for (int i = size - 1; i >= 0; i--) {
        this->number[size - 1 - i] = temp[i];
    }
}

Six::Six(const std::initializer_list<unsigned char> &list)
    : Six(std::string(list.begin(), list.end())) {
}

Six::Six(const Six &other) {
    if (other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    this->size = other.size;
    this->number = new unsigned char[this->size];

    for (int i = 0; i < this->size; i++) {
        this->number[i] = other.number[i];
    }
}

Six::Six(Six &&other) noexcept {
    this->size = other.size;
    this->number = other.number;

    other.size = 0;
    other.number = nullptr;
}

Six::~Six() noexcept {
    if (number != nullptr) {
        delete[] number;
        number = nullptr;
    }
}

Six &Six::operator=(const Six &other) {
    if (this == &other) return *this;
    if (other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    this->size = other.size;

    delete[] this->number;

    this->number = new unsigned char[this->size];

    for (int i = 0; i < this->size; i++) {
        this->number[i] = other.number[i];
    }

    return *this;
}

Six &Six::operator=(Six &&other) {
    if (this == &other) return *this;

    this->size = other.size;
    delete[] this->number;
    this->number = other.number;

    other.number = nullptr;
    other.size = 0;

    return *this;
}

std::string Six::getNumber() const {
    if (number == nullptr)
        throw std::domain_error("The object is not initialized");

    std::string temp = "";

    for (int i = size - 1; i >= 0; i--) {
        temp += number[i];
    }

    return temp;
}

int Six::getSize() const {
    return size;
}

std::ostream &operator<<(std::ostream &os, const Six &object) {
    if (object.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
    os << object.getNumber();
    return os;
}

bool Six::operator==(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    if (this->size != other.size) return false;

    for (int i = 0; i < this->size; i++) {
        if (this->number[i] != other.number[i]) return false;
    }
    return true;
}

bool Six::operator!=(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    if (this->size != other.size) return true;

    return !(*this == other);
}

bool Six::operator>(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    if (this->size != other.size) return this->size > other.size;

    for (int i = size - 1; i >= 0; i--) {
        if (this->number[i] > other.number[i]) return true;
    }
    return false;
}

bool Six::operator<(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    if (this->size != other.size) return this->size < other.size;

    for (int i = size - 1; i >= 0; i--) {
        if (this->number[i] < other.number[i]) return true;
    }
    return false;
}

bool Six::operator>=(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    return !(*this < other);
}

bool Six::operator<=(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    return !(*this > other);
}

Six &Six::operator+=(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    const int maxSize = std::max(this->size, other.size);
    const int minSize = std::min(this->size, other.size);

    unsigned char *newNumber = new unsigned char[maxSize + 1];

    int carry = 0;
    for (int i = 0; i < maxSize; i++) {
        int sum = 0;
        if (i < minSize) {
            sum = this->number[i] - '0' + other.number[i] - '0';
        } else if (this->size > other.size) {
            sum = this->number[i] - '0';
        } else {
            sum = other.number[i] - '0';
        }
        sum += carry;
        carry = sum / 6;
        sum %= 6;
        newNumber[i] = sum + '0';
    }
    if (carry > 0) {
        newNumber[maxSize] = carry + '0';
    } else {
        this->size = maxSize;
    }

    delete[] this->number;
    this->number = newNumber;

    return *this;
}

Six Six::operator+(const Six &other) const {
    return Six(*this) += other;
}

Six &Six::operator-=(const Six &other) {
    if (this->number == nullptr || other.number == nullptr)
        throw std::domain_error("The object is not initialized");

    if (this->size < other.size) throw std::logic_error("Logic error");

    int carry = 0;
    for (int i = 0; i < this->size; ++i) {
        int subtraction = 0;
        if (i < other.size) {
            subtraction = this->number[i] - other.number[i];
        } else {
            subtraction = this->number[i] - '0';
        }
        subtraction += carry;
        carry = subtraction >= 0 ? 0 : -1;
        subtraction = (subtraction + 6) % 6;
        this->number[i] = subtraction + '0';
    }

    for (int i = this->size - 1; i > 0; --i) {
        if (this->number[i] != '0') {
            break;
        }
        this->size--;
    }

    return *this;
}

Six Six::operator-(const Six &other) const {
    return Six(*this) -= other;
}
