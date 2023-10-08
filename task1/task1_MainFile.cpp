#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

const int base = 1000000000;
class BigInteger;
bool operator==(const BigInteger& tmp, const BigInteger& b);
bool operator>(const BigInteger& tmp, const BigInteger& b);
bool operator!=(const BigInteger& tmp, const BigInteger& b);
bool operator<(const BigInteger& tmp, const BigInteger& b);
BigInteger operator*(BigInteger result, const BigInteger& b);
BigInteger operator+(BigInteger result, const BigInteger& b);
BigInteger operator-(BigInteger result, const BigInteger& b);
class BigInteger {
    friend std::ostream& operator<<(std::ostream& output, const BigInteger& bi);
    friend std::istream& operator>>(std::istream& input, BigInteger& bi);
    friend bool operator<(const BigInteger& tmp, const BigInteger& b);
    friend bool operator>=(const BigInteger& tmp, const BigInteger& b);
    friend bool operator==(const BigInteger& tmp, const BigInteger& b);
  private:
    std::vector<int64_t> digits;
    size_t sz = 0;
  public:
    explicit operator bool() const {
        return !(sign == 0);
    }
    int sign = 0;
    BigInteger() {}
    ~BigInteger(){}
    BigInteger (const BigInteger& s) {
        digits.clear();
        for (size_t i = 0; i < s.size(); ++i) {
            digits.push_back(s.digits[i]);
        }
        sz = (s.sz);
        sign = s.sign;
    }
    BigInteger (const std::string& str) {
        size_t j = 0;
        size_t t = 0;
        sign = 1;
        std::vector<int64_t> tmp;
        if (str[0] == '-') {
            j = 1;
            sign = -1;
        }
        int k = 0;
        size_t p = (str.size() - j) % 9;
        for (size_t y = j; y < p + j; ++y) {
            t *= 10;
            t += str[y] - '0';
        }
        if (p != 0) {
            tmp.push_back(t);
            ++sz;
            t = 0;
        }
        size_t i = j + p;
        while (i < str.size()) {
            t *= 10;
            t += str[i] - '0';
            ++k;
            if (k == 9) {
                tmp.push_back(t);
                ++sz;
                t = 0;
                k = 0;
            }
            ++i;
        }
        if (k != 0) {
            throw("why");
            tmp.push_back(t);
            ++sz;
        }
        for (int e = tmp.size() - 1; e >= 0; --e) {
          digits.push_back(tmp[e]);
        }
        if (str.size() == 0 || (str.size() == 1 && str[0] == '0')) {
            sign = 0;
            sz = 0;
        }
    }
    BigInteger(int64_t x) {
        sign = 1;
        if (x < 0) {
            sign = -1;
            x *= -1;
        } else if (x == 0) {
            sign = 0;
        }
        while (x / base != 0) {
            digits.push_back(x % base);
            ++sz;
            x /= base;
        }
        if (x % base != 0) {
            digits.push_back(x % base);
            ++sz;
        }
    }
    
    BigInteger abs() const {
        BigInteger tmp = *this;
        if (tmp.sign == -1) {
            tmp.sign = 1;
        }
        return tmp;
    }
    size_t size() const {
        return sz;
    }
    BigInteger& operator+=(const BigInteger& other) {
        size_t i = 0;
        if (sign == 0) {
            *this = other;
            return *this;
        } else if(other.sign == 0) {
            return *this;
        }
        if (digits.size() < std::max(sz, other.sz) + 1) {
            digits.resize((std::max(sz, other.sz)) * 2 + 1, 0);
        }
        if (sign == other.sign) {
            while (i < sz && i < other.sz) {
                digits[i] += other.digits[i];
                ++i;
            }
            while (i < other.sz) {
                digits[i] = other.digits[i];
                ++i;
                ++sz;
            }
        } else {
            BigInteger copy = other;
            if (*this == (-other)) {
                sign = 0;
                sz = 0;
                return *this;
            }
            if ((*this) < -other && other.sign == -1) {
                swap(copy);
            }
            if ((*this) > -other && other.sign == 1) {
                swap(copy);
            }
            while (i < copy.sz) {
                digits[i] -= copy.digits[i];
                ++i;
            }
            i = 0;
            while (i < std::min(sz, copy.sz + 1)) {
                if (digits[i] < 0) {
                    digits[i] += base;
                    digits[i + 1] -= 1;
                }
                ++i;
            }
            while (digits[i] < 0) {
                digits[i] += base;
                digits[i + 1] -= 1;
                ++i;
            }
            i = sz - 1;
            while (digits[i] == 0) {
                --sz;
                --i;
            }
        }
        return *this;
    }
    BigInteger& operator=(const BigInteger& s) {
        BigInteger tmp(s);
        swap(tmp);
        return *this;
    }
    void swap(BigInteger& s) {
        std::swap(digits, s.digits);
        std::swap(sz, s.sz);
        std::swap(sign, s.sign);
    }
    BigInteger& operator-=(const BigInteger& other) {
        return *this += (-other);
    }
    BigInteger& operator*=(const BigInteger& other) {
        std::vector<int64_t> tmp(sz + other.sz, 0);
        int64_t k = 0, r = 0;
        if (sign == 0 || other.sign == 0) {
            for (size_t i = 0; i < sz; ++i) {
                digits[i] = 0;
            }
            sign = 0;
            sz = 0;
            return *this;
        }
        if (other == 1) {
            return *this;
        }
        if (other == -1) {
            sign *= -1;
            return *this;
        }
        for(size_t i = 0; i < sz; ++i) {
            r = 0;
            for (size_t j = 0; j < other.sz; ++j) {
                k = (digits[i] * other.digits[j] + r + tmp[i + j]) % base;
                r = (digits[i] * other.digits[j] + r + tmp[i + j]) / base;
                tmp[i + j] = k;
            }
            tmp[i + other.sz] += r;
        }
        r = 0;
        for (size_t i = 0; i < tmp.size(); ++i) {
            k = (r + tmp[i]) % base;
            r = (r + tmp[i]) / base;
            tmp[i] = k;
        }   
        if (digits.size() < tmp.size()) {
            digits.resize(tmp.size(), 0);
        }
        for (size_t i = 0; i < tmp.size(); ++i) {
            digits[i] = tmp[i];
        }
        if (digits[tmp.size() - 1] == 0) {
            sz = tmp.size() - 1;
        } else {
            sz = tmp.size();
        }
        sign *= other.sign;
        return *this;
    }
    BigInteger& operator++() {
        *this += 1;
        return *this;
    }
    BigInteger operator++(int) {
        BigInteger copy = *this;
        ++*this;
        return copy;
    }
    BigInteger& operator--() {
        *this -= 1;
        return *this;
    }
    BigInteger operator--(int) {
        BigInteger copy = *this;
        --*this;
        return copy;
    }
    BigInteger operator-() const {
        BigInteger a = *this;
        if (a.sign == -1) {
            a.sign = 1;
        } else if (sign == 1) {
            a.sign = -1;
        }
        return a;
    }
    
    std::string toString() const {
        std::string s;
        if (sign == 0) {
            s += '0';
            return s;
        } else if (sign == -1) {
            s += '-';
        }
        s += std::to_string(digits[sz - 1]);
        for (int i = sz - 2; i >= 0; --i) {
            std::string m = std::to_string(digits[i]);
            for (int j = m.size(); j < 9; ++j) {
              s += '0';
            }
            s += m;
        }
        return s;
    }
};

BigInteger operator+(BigInteger result, const BigInteger& b) {
    result += b;
    return result;
}
BigInteger operator-(BigInteger result, const BigInteger& b) {
    result -= b;
    return result;
}
BigInteger operator*(BigInteger result, const BigInteger& b) {
    result *= b;
    return result;
}
bool operator<(const BigInteger& tmp, const BigInteger& b) {
    if (tmp.sign < b.sign) {
        return true;
    } else if (tmp.sign > b.sign) {
        return false;
    } else if (tmp.sign == 0) {
        return false;
    }
    if (tmp.sz < b.sz) {
        if (tmp.sign == 1) {
            return true;
        }
        return false;
    } else if (tmp.sz > b.sz) {
        if (tmp.sign == 1) {
            return false;
        }
        return true;
    }
    for (int i = tmp.sz - 1; i >= 0; --i) {
        if (tmp.digits[i] < b.digits[i]) {
            if (tmp.sign == -1) {
                return false;
                
            } else {
                return true;
            }
        } else if (tmp.digits[i] > b.digits[i]){
            if (tmp.sign == 1) {
                return false;
            } else {
                return true;
            }
        }
    }
    return false;
}
bool operator>(const BigInteger& tmp, const BigInteger& b) {
    return b < tmp;
}
bool operator<=(const BigInteger& tmp, const BigInteger& b) {
    return !(tmp > b);
}
bool operator>=(const BigInteger& tmp, const BigInteger& b) {
    return !(tmp < b);
}
bool operator==(const BigInteger& tmp, const BigInteger& b) {
    if (tmp.size() != b.size()) {
        return false;
    }
    if (tmp.sign != b.sign) {
        return false;
    }
    for (int i = tmp.size() - 1; i >= 0; --i) {
        if (tmp.digits[i] != b.digits[i]) {
            return false;
        }
    }
    return true;
}
bool operator!=(const BigInteger& tmp, const BigInteger& b) {
    return !(tmp == b);
}
std::ostream& operator<<(std::ostream& output, const BigInteger& bi) {
    std::string temp = bi.toString();
    for (size_t i = 0; i < temp.size(); ++i) {
        output << temp[i];
    }
    return output;
}
std::istream& operator>>(std::istream& input, BigInteger& bi) {
    std::string str;
    input >> str;
    bi = str;
    return input;
}

