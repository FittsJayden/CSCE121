#include <iostream>
using std::cout;
using std::endl;

class AllocatorShort {
    private:
        short** mem;
        int size;
        int capacity;

    
    public:
        AllocatorShort() : mem(nullptr), size(0), capacity(0) {}
        AllocatorShort(const AllocatorShort& src);
        ~AllocatorShort();
        const AllocatorShort& operator=(const AllocatorShort& src);
        
        //defined defs
        void clear();
        const short * operator[](int val);
        void printAllocator() const;
        const int getSize() const {return size;}
        //todo
        short* giveShort(short val);

        //rule oif three
        //to do
};



//2.2

AllocatorShort::~AllocatorShort() {
    this->clear();
}

AllocatorShort::AllocatorShort(const AllocatorShort& src) : size(src.size), capacity(src.capacity) {
    if (size > 0) {
        this->mem = new short*[capacity];
        for (int i=0; i < capacity; i++) {
            this->mem[i] = src.mem[i];
        }
    }
    else {
        mem = nullptr;
    }
}

const AllocatorShort& AllocatorShort::operator=(const AllocatorShort& src) {
    if (src.size > 0) {
        this->mem = new short*[capacity];
        this->size = src.size;
        this->capacity = src.capacity;

        for (int i=0; i < capacity; i++) {
            this->mem[i] = src.mem[i];
        }
    }
    else {
        this->mem = nullptr;
    }
}




//2.1


short* AllocatorShort::giveShort(short val) {
    short* newShort = new short(val);

    if (mem == nullptr) {
        mem = new short*[1];
        mem[0] = newShort;

        capacity = 1;
        size = 1;
        return newShort;
    }


    if (capacity <= size + 1) {
        capacity *= 2;
        short** newMem = new short*[capacity];

        for (int i = 0; i < capacity; i++) {
            if (i < size) {
                newMem[i] = mem[i];
            }

            else {
                newMem[i] = nullptr;
            }           
        }

        mem = newMem;

        for (int i=0; i < capacity; i++) {
            delete newMem[i];
        }
        delete [] newMem;
        newMem = nullptr;

    }

    mem[size] = newShort;
    size += 1;
    return newShort;
    


}









const short* AllocatorShort::operator[](int val) {
    if (val < 0 || val >= size) {
        throw std::invalid_argument("Array OOB");
    }
    return mem[val];
}

void AllocatorShort::printAllocator() const {
    for (int i=0; i < this->getSize(); i++) {
        cout << *(*this)[i] << endl;
    }
}

void AllocatorShort::clear() {
    if (mem != nullptr) {
        for (int i=0; i < size; i++) {
            delete mem[i];
        }
        delete [] mem;
        mem = nullptr;
    }
    size = 0;
    capacity = 0;
}
