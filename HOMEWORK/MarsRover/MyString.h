// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

# include <iostream>


class MyString {
    private:
        size_t size_;
        size_t capacity_;
        char* str_;

    public:
        MyString();
        MyString(const MyString& src);
        MyString(const char* src);
        ~MyString();

        MyString& operator=(const MyString& src);
        friend std::ostream& operator<<(std::ostream& os, const MyString& src);
        MyString& operator+= (const MyString& src);

        void resize(size_t n);
        size_t capacity() const;
        size_t size() const;
        size_t length() const; //sizeof()
        const char* data();
        bool empty();
        const char& front();
        const char& at(size_t pos) const;
        void clear();
        unsigned int find(const MyString& src, unsigned int pos = 0) const;



};



#endif

