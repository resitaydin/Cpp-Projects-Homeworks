#include <memory>
#include <iostream>

namespace TPFA{

    template <class T>
    class PFArray{

        public:
            PFArray();
            PFArray(const PFArray<T>&); // Copy constr.
            PFArray(PFArray<T>&&); // Move constr.
            ~PFArray(){} // Destructor

            int size() const{ return size_;}
            void push_back (const T&);
            // T& operator[](int);
            PFArray<T>& operator=(const PFArray<T>& other); // Assignment operator.
            PFArray<T>& operator=(PFArray<T>&& other); // Move Assignment operator.
            bool empty () const{ return size() == 0;}


        class Iterator{
            public:
                Iterator(T* ptr) : ptr_(ptr) {}
                Iterator() : ptr_(nullptr) {}
                T& operator*() const { return *ptr_; }
                T* operator-> () const { return ptr_; }

                Iterator& operator++()  { ++ptr_; return *this;} //pre increment
                Iterator operator++(int)  { Iterator temp = *this; ++ptr_; return temp;}

                Iterator& operator--() { --ptr_; return *this; } //pre decrement
                Iterator operator--(int)  { Iterator temp = *this; --ptr_; return temp;}
                Iterator& operator=(const Iterator& other) { ptr_ = other.ptr_; return *this;}
                bool operator==(const Iterator& other) const { return ptr_== other.ptr_; }
                bool operator!=(const Iterator& other) const { return ptr_!= other.ptr_; }

            private:
                T* ptr_;
        };

        void erase(const Iterator& it);
        size_t erase(const T& element);
        void clean ();

        T* begin();
        const T* cbegin() const;

        T* end();
        const T* cend() const;


        private:
            std::shared_ptr <T> data;
            size_t size_;
    };

} //Namespace