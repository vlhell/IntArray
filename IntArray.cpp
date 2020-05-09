#include <iostream>
#include <algorithm>

using namespace std;

class IntArray {
public:
    explicit IntArray(size_t size)
        : size_(size)
        , data(new int[size])
    { 
        for (int i = 0; i != size_; ++i)
            data[i] = 0;
    }

    IntArray(IntArray const& a) : //copying
        size_(a.size), data(new int[size_])
    {
            for (size_t i = 0; i != size_; ++i)
                data_[i] = a.data_[i];
    }

    IntArray & operator=(IntArray const& a) { //assignment
        if (this != &a)
            IntArray(a).swap2(*this);
        return *this;
    }

    ~IntArray() {
        delete [] data;
    }

    int & get(size_t i) {
        return data_[i];
    }

    size_t size() const { return size_; }

    void set(size_t i, int num) {
        data_[i] = num;
    }

    void resize(int nsize) {
        int * ndata = new int[nsize];
        size_t n = nsize > size_ ? size_ : nsize;

        for (int i = 0; i != n; ++i)
            ndata[i] = data_[i];

        delete [] data_;
        data_ = ndata;
        size_ = nsize;
    }

    void resize2(int nsize) {
        IntArray t(nsize);
        size_t n = nsize > size_ ? size_ : nsize;

        for (int i = 0; i != n; ++i)
            t.data_[i] = data_[i];

        swap(t);
    }
    
    void swap(IntArray & a) {
        size_t const t1 = size_;
        size_ = a.size_;
        a.size_ = t1;

        int * const t2 = data_;
        data_ = a.data_;
        a.data_ = t2;
    }

    void swap2(IntArray & a) {
        std::swap(size_, a.size_);
        std::swap(data_, a.data_);
    }
private:
    // IntArray(IntArray const& a); // prohibition of copying objects
    // IntArray & operator=(IntArray const& a); // prohibition of copying objects

    size_t size_;
    int * data_;
};

int main() {
    IntArray * pa = new IntArray(10);
    delete pa;

    IntArray * pb = 
        (IntArray *)malloc(sizeof(IntArray));

    IntArray * pc = new IntArray[10];
    delete [] pc;

    IntArray a1(10);
    IntArray a2(20);
    IntArray a3 = a1; // copying
    a2 = a1; // assignment
    return 0;
}