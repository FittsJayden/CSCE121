// TODO: Implement this source file
# include <iostream>
# include "MyString.h"


MyString::MyString() : size_(0), capacity_(50), str_(new char[50]) {
    for (unsigned int i = 0; i < capacity_; i++) {
        str_[i] = '\0';
    }
}

MyString::MyString(const MyString& src) : size_(src.size_), capacity_(src.capacity_), str_(new char[50]) {
    for (unsigned int i = 0; i < src.size_; i++) {
        this->str_[i] = src.str_[i];
    }
}

MyString::MyString(const char* src) : size_(0), capacity_(50), str_(new char[50]) {
    for (unsigned int i = 0; src[i] != '\0'; i++) {
        str_[i] = src[i];
        this->size_ += 1;
    }
}

MyString::~MyString() {
    delete[] str_;
}








MyString& MyString::operator=(const MyString& src) {
    this->size_ = src.size_;
    this->capacity_ = src.capacity_;

    for (unsigned int i = 0; i < src.size_; i++) {
        this->str_[i] = src.str_[i];
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& src) {
    for (unsigned int i = 0; i < src.size_; i++) {
        os << src.str_[i];
    }
    return os;
}

MyString& MyString::operator+=(const MyString& src) {

    while (this->size_ + src.size_ > this->capacity_) {
        this->capacity_ *= 2;
    }


    char* buffer = new char[this->capacity_];

    for (unsigned int i = 0; i < this->size_; i++) {
        buffer[i] = this->str_[i];
    }
    for (unsigned int i = this->size_; i < this->size_ + src.size_; i++) {
        buffer[i] = src.str_[i - this->size_];
    }
    delete[] str_;
    this->str_ = buffer;
    this->size_ += src.size_;

    return *this;
}







void MyString::resize(size_t n) {
    unsigned int newSize = size_;

    if (n > size_) {
        while (capacity_ < n) {
            capacity_ *= 2;
        }

        char* buffer = new char[capacity_];

        for (unsigned int i = 0; i < n; i++) {
            if (i < size_) {
                buffer[i] = str_[i];
            }
            else {
                buffer[i] = '\0';
            }
            newSize += 1;
        }
        delete[] str_;
        str_ = buffer;
        size_ = newSize;
    }
    else if (n < size_) {
        for (unsigned int i = size_; i > n; i--) {
            str_[i - 1] = '\0';
            newSize -= 1;
        }
        size_ = newSize;
    }

}

size_t MyString::capacity() const {
    return this-> capacity_;
}

size_t MyString::size() const {
    return this->size_;
}

size_t MyString::length() const {
    return this->size_;
}

const char* MyString::data() {
    char* buffer = new char[this->capacity_];
    for (unsigned int i = 0; i < this->size_; i++) {
        buffer[i] = this->str_[i];
    }

    delete[] str_;
    this->str_ = buffer;

    return this->str_;
}

bool MyString::empty() {
    return this->size_ > 0 ? false : true;
}

const char& MyString::front() {
    return str_[0];
}

const char& MyString::at(size_t pos) const {
    if (pos >= this->size_) {
        throw std::out_of_range("out of string");
    }
    return this->str_[pos];
}

void MyString::clear() {
    this->size_ = 0;
    for (unsigned int i = 0; i < this->capacity_; i++) {
        this->str_[i] = '\0';
    }
}

unsigned int MyString::find(const MyString& src, unsigned int pos) const {
    bool match = false;

    for (unsigned int i = pos; i < this->size_; i++) {
        if (this->str_[i] == src.str_[0]) {

            for (unsigned int j = 1; j < src.size_; j++) {
                if (!(this->str_[i + j] == src.str_[j])) {
                    break;
                }
                else {
                    if (j == src.size_ - 1) {
                        match = true;
                    }
                }
            }
            
            if (match == true) {
                return i;
            }
        }
    }

    return -1;
}
