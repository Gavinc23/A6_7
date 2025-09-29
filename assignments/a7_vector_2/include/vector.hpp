#pragma once
#include <iostream>

namespace dsa{

template <typename T>
class Vector {

private:
    int cap{0};       // capacity of the array
    int sz{0};        // number of actual entries
    T* data{nullptr}; // pointer to array of elements

public:
    //empty
    Vector() = default;
    
    //capacity
    int capacity() const {
        return cap;
    }

    //elements stored
    int size() const {
        return sz;
    }
    
    // True is empty
    bool empty() const {
        return sz == 0;
    }
    
    //element at index when vector is const
    const T& operator[](int i) const { 
        return data[i];
    }
    
    //element at index when vector is non-const
    T& operator[](int i) { 
        return data[i];
    }
    
    // at function for const
    const T& at(int i) const{
        if( i < 0 || i >= sz){
            throw std::out_of_range("out of bounds error");
        }
        return data[i];
    }
    
    // at function for non const
    T& at(int i){
        if( i < 0 || i >= sz){
            throw std::out_of_range("out of bounds error");
        }
        return data[i];
    }
    
    // first element
    const T& front() const { 
        return data[0];
    }

    // first element
    T& front() {
        return data[0];
    }
    
    // last element
    const T& back() const { 
        return data[sz -1];
    }

    // last element
    T& back() {
        return data[sz -1];
    }
    
    // insert at end
    // double array size
    void push_back(const T& elem){
        if(sz == cap){
            reserve(std::max(1,2*cap));
        }
        data[sz] = elem;
        sz++;
    }

    // remove from end
    void pop_back() { 
         sz--;
         shrink();
    }

    // insert at index
    void insert(int i, const T& elem){
  if(sz == cap){
            reserve(std::max(1,2*cap));
        }
            for(int k = sz-1; k >= i; k--){
                data[k+1] = data[k];
            }      
        data[i] = elem;
        sz++;    
    }

    // removes at index
    void erase(int i){
        for(int k = i+1; k < sz; k++){
            data[k-1] = data[k];
        }
        sz--;
        shrink();
    }

    //capacity >= minimum
    void reserve(int minimum){
          if(cap < minimum){
            T* new_data = new T[minimum];
            for(int k = 0; k < sz; k++){
                new_data[k] = data[k];
            }
            delete[] data;
            data = new_data;
            cap = minimum;
        }
    }

    // nested iterator class
    class iterator {
        // needed by Vector's insert and erase
        friend class Vector;
        
        private:
            Vector* vec;
            int ind;   // index within the vector
        public:
            // constructor
            iterator(Vector* v=nullptr, int i=-1){ 
                vec = v; ind=i; 
            }

            T& operator*() const { 
                return (*vec)[ind]; 
            }

            T* operator->() const { 
                return &((*vec)[ind]);
            }

            //pre increment overloaded without param
            iterator& operator++(){
                ind++; 
                return *this;
            }

            //post increment overloaded with parameter
            iterator operator++(int){ 
                iterator old = *this;
                ind++;
                return old;
            }

            //pre decrementr overloaded without param
            iterator& operator--(){
                ind--; 
                return *this;
            }
            
            //post decrement overloaded with parameter
            iterator operator--(int){
                iterator old = *this;
                ind--;
                return old;
            }

            bool operator==(iterator rhs) const{
                return vec == rhs.vec && ind == rhs.ind;
            }

            bool operator!=(iterator rhs) const{
                return !(*this == rhs);
            }
    };

    // nested const_iterator class
    class const_iterator {
        private:
            const Vector* vec;
            int ind;   // index within the vector
        
        public:
            const_iterator(const Vector* v=nullptr, int i=-1){
                vec = v; ind=i;
            }

            const T& operator*() const { 
                return (*vec)[ind];
            }
            
            const T* operator->() const { 
                 return &((*vec)[ind]);
            }

            //pre
            const_iterator& operator++(){
                ind++;
                return *this;
            }

            //post
            const_iterator operator++(int){
                const_iterator old = *this;
                ind++;
                return old;
            }

            //pre
            const_iterator& operator--(){
                ind--;
                return *this;
            }

            //post
            const_iterator operator--(int){
                const_iterator old = *this;
                ind--;
                return old;
            }

            bool operator==(const_iterator rhs) const{
                return vec == rhs.vec && ind == rhs.ind;
            }

            bool operator!=(const_iterator rhs) const{
                return !(*this == rhs);
            }
    };
public:
    // additional functions of Vector class
    
    //return vector and index 0
    iterator begin(){
        return iterator(this, 0);
    }

    //return vector and index sz
    iterator end(){
        return iterator(this, sz);
    }

    //return vector and index 0
    const_iterator begin() const{
       return const_iterator(this, 0);
    }

    //return vector and index sz
    const_iterator end() const{
        return const_iterator(this, sz);
    }

    // Inserts an element immediately before iterator position
    iterator insert(iterator it, const T& elem){
        insert(it.ind, elem);
        return iterator(this, it.ind);
    }

    // Removes the element at the given iterator position
    iterator erase(iterator it){
        erase(it.ind);
        return iterator(this, it.ind);
    }
    

    // Rule of Five
    private:

        void clone(const Vector& other){
            cap = other.cap;
            sz = other.sz;
            data = new T[cap];
            for(int i = 0; i < sz; i++){
                data[i] = other.data[i];
            }
        }

        void transfer(Vector& other){
            cap = other.cap;
            sz = other.sz;
            data = other.data;
            other.cap = 0;
            other.sz = 0;
            other. data = nullptr;
        }

    public:
        // Copy constructor
        Vector(const Vector& other){ 
            clone(other); 
        }

        // Copy assignment
        Vector& operator=(const Vector& other){
            // nothing to be done if self-assignment
            if (this != &other) {
                delete[] data;
                clone(other);
            }
            return *this;
        }

        // Move constructor
        Vector(Vector&& other){ 
            transfer(other); 
        }

        // Move assignment
        Vector& operator=(Vector&& other){
            // nothing to be done for self-assignment
            if (this != &other) {
                delete[] data;
                transfer(other);
            }
            return *this;
        }

        // Destructor suffices
        ~Vector(){
            delete[] data; 
        }

    // additional assignment functions
    // Reallocate storage to exactly new_cap (>= sz), moving elements.
    void reallocate(int new_cap){ // optional helper
        if(new_cap == cap){
        return;
    }
    T* new_data = new T[new_cap];
    for(int k = 0; k <= sz-1; k++){
        new_data[k] = data[k];
    }
    delete[] data;
    data = new_data;
    cap = new_cap;
    }

    void shrink(){
        if(cap > 0 && sz <= cap/4){
            reallocate(std::max(1,cap/2));
        }
    }
    
    // explicitly reduce the cap to sz and keep at least 1 slot
    void shrink_to_fit(){
          if(cap > sz){
            reallocate(std::max(1,sz));
        }
    }

}; //end class Vector
}//end namespace dsa

