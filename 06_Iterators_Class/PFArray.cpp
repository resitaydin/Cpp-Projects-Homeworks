#include "PFArray.h"

using std::cout;
using std::cerr;
using std::endl;

namespace TPFA{

    template <class T>
    PFArray<T>::PFArray() : size_(0), data(nullptr){
    // EMPTY.
    }

    template <class T>
    PFArray<T>::PFArray(const PFArray<T>& other){  // Cpy Constr. (Does deep copying.)
        data.reset(new T(other.size()));
        size_ = other.size_;
        for(int i=0; i<size(); ++i){
            data.get()[i] = other.data.get()[i];
        }
        data = other.data;
    }

    template<typename T>
    PFArray<T>::PFArray(PFArray<T>&& other){  // Move constr. (Does shallow copying.)
    try{
        data = other.data;
        size_ = other.size_;

        other.data = nullptr;
        other.size_ = 0;
    }
    catch(const std::exception& e){
        cerr<<"Exception occured! "<<e.what();
    }
        
    }

    template<class T>
    PFArray<T>& PFArray<T>::operator=(const PFArray<T>& other){  // Overloaded = operator(deep copying)
            data.reset(new T(other.size()));
            size_ = other.size_;
            for(int i=0; i<size(); ++i){
                data.get()[i] = other.data.get()[i];
            } 
            data = other.data;

        return *this;
    }

    template<class T>
    PFArray<T>& PFArray<T>::operator=(PFArray<T>&& other){  // Overloaded move = operator(shallow copying)
    
            data = other.data;
            size_ = other.size_;

            other.data = nullptr;
            other.size_ = 0;
        
        return *this;
    }

    template <class T>
    void PFArray<T>::push_back(const T& element){ // Overloading push_back function for our array.
        try{
            std::shared_ptr <T> temp(new T(size()+1));
            for(int i=0; i<size(); ++i) temp.get()[i] = data.get()[i];
    
            temp.get()[size()] = element;
            data.swap(temp); // Swapping the addresses of temp and data.

            ++size_;
        }
        catch(const std::bad_alloc& e){
            cout << "Allocation failed: " << e.what() << '\n';
        }
        
    }

    template<typename T>
    T* PFArray<T>::begin (){

        return data.get();
    }

    template<typename T>
    T* PFArray<T>::end (){

        return data.get() + size();
    }


    template<typename T>
    const T* PFArray<T>::cbegin () const{

        return data.get();
    }

    template<typename T>
    const T* PFArray<T>::cend () const{

        return data.get() + size();
    }

    template<typename T>
    void PFArray<T>::clean() {
        data = nullptr;
        size_ = 0;
    }

    template<typename T>
    void PFArray<T>::erase(const Iterator& it){  // Erase the element pointed by the given iterator.
        bool found= false;
        Iterator my_it;
        std::shared_ptr <T> temp(new T(size()));

        for( my_it = begin(); my_it!=end(); my_it++) {
        if(my_it == it) found =true;
        }

        if(found){
            int j =0;
            for(Iterator my_it = begin(); my_it!=end(); ++my_it){
                if(!(my_it == it)){
                    temp.get()[j] = *my_it;
                    ++j;
                } 
            }
        }
        else{
                throw("Invalid Iterator!");

            return;
        }
        data = temp;
        --size_;
    }

    template<typename T>
    size_t PFArray<T>::erase(const T& element){
        bool found= false;
        int counter= 0; // Counter to count how many element there are for calculating size.
        Iterator my_it;
        std::shared_ptr <T> temp(new T(size()));

        for( my_it = begin(); my_it!=end(); my_it++) {
        if(*my_it == element) found =true;
        }

        if(found){
            int j =0;
            for(Iterator my_it = begin(); my_it!=end(); ++my_it){
                if(!(*my_it == element)){
                    temp.get()[j] = *my_it;
                    ++j;
                } 
                else counter++;
            }
        }
        else{
            try{
                throw std::invalid_argument("Invalid element!");
            }
            catch(const std::invalid_argument& e){
                cerr<<"Exception occured! "<<e.what()<<endl<<endl;
            }
            return size_;
        }

        data = temp;
        size_ -= counter;  // counter* sizeof(T)

        return size_;
    }

} //namespace