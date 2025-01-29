#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class VectorIndexError : public std::exception {
protected:
  string msg;
public:
  VectorIndexError()=default;
  VectorIndexError(const char* e) noexcept : msg(e) 
  {}
  VectorIndexError(const VectorIndexError& other) noexcept : msg(other.msg) 
  {}
  const char* what(void) const noexcept {return msg.c_str();}
  virtual ~VectorIndexError()=default;
};

class VectorMemoryError : public VectorIndexError {
public:
  VectorMemoryError()=default;
  VectorMemoryError(const char* e) noexcept : VectorIndexError(e) 
  {}
  virtual ~VectorMemoryError()=default;
};

template <typename T>
class Vector {
  std::unique_ptr<T[]>data;
  size_t _capacity{0};
  size_t length{0};
  
  class Inner{
    Vector* current{nullptr};
    size_t index{0};
  public:
    Inner(Vector* curr, size_t indx) : current(curr), index(indx) { }

    T& operator=(T val) {
      if(current != nullptr && index < current->_capacity){
        current->data[index] = val;
        if(index >= current->length) 
          current->length = index + 1;
      }
      return current->data[index];
    }
    operator T() const{
      if(index < current->_capacity) {
        return current->data[index];
      }
      throw VectorIndexError("Invalid element index.");
    }
  };
public:
  Vector() : data(std::make_unique<T[]>(8)), length(0), _capacity(8) {}
  Vector(T* _data, size_t len, size_t cap) {
    set_coords(_data, len, cap);
  }
  Vector(const Vector& other) {
    length = other.length;
    _capacity = other._capacity;
  
    data = std::make_unique<T[]>(_capacity);
    for(size_t i=0; i<length; i++)
      data[i] = other.data[i];
  }
  void set_coords(T* _data, size_t len, size_t cap) {
    _capacity = cap;
    length = (len < cap) ? len : cap;
    data = std::make_unique<T[]>(_capacity);
    
    if(_data){
        for(size_t i=0; i < _capacity; i++)
        data[i] = _data[i];
    }
  }

  void push_back(T val){
    if(length >= _capacity){
      resize( (_capacity == 0) ? 1 : _capacity * 2 );
    }
    data[length++] = val;
  }
  void push_front(T val){
    if(length >= _capacity){
      resize( (_capacity == 0) ? 1 : _capacity * 2 );
    }
    for(size_t i=length; i>0; i--) {
        data[i] = data[i-1];
    }
    data[0] = val;
    length++;
  }
  void pop_back(void){
    if(length > 0)
      length--;
  }
  void pop_front(void){
    if(length > 0){
      for(size_t i=0; i<length-1; i++)
        data[i] = data[i+1];
      length--;
    }
  }

  void insert(size_t index, T val) {
    if (index > length) {
        throw VectorIndexError("Invalid element index.");
    }
    if (length >= _capacity) {
        resize((_capacity == 0) ? 1 : _capacity * 2);
    }
    for (size_t i=length;i>index;i--) {
        data[i]=data[i-1];
    }
    data[index]=val;
    length++;
  }
    
  void remove(size_t index){
    if(index >= length){
      throw VectorIndexError("Invalid element index.");
    }
    for(size_t i=index; i<length-1; i++){
      data[i] = data[i+1];
    }
    length--;
  }
  inline size_t capacity(void) const noexcept {return this->_capacity;}
  inline size_t size(void) const noexcept {return this->length;}

  Vector& operator+=(const Vector& other) {
    if(this == &other) return *this;

    size_t new_len=this->length+other.length;
    size_t new_capacity = new_len;

    auto new_data = std::make_unique<T[]>(new_capacity);
    if(new_data == nullptr) 
      throw VectorMemoryError("Error: memory allocation error");

    for(size_t i=0; i<length; i++)
      new_data[i] = data[i];
    
    for(size_t i=0; i<other.length; i++)
      new_data[length+i]=other.data[i];


    data = std::move(new_data);
    length = new_len;
    _capacity = new_capacity;

    return *this;
  }

  Vector operator+(const Vector& right) const {
    int new_len = length + right.length;
    int new_cap = new_len;
    auto new_data = std::make_unique<T[]>(new_cap);
    if(new_data == nullptr) 
      throw VectorMemoryError("Error: memory allocation error");

    for(size_t i=0; i<this->length; i++)
      new_data[i] = this->data[i];
    for(size_t i=0; i<right.length; i++)
      new_data[this->length + i] = right.data[i];
    
    return Vector(new_data, new_len, new_cap);
  }
  Inner operator[](size_t index) {
    return Inner(this, index);
  }

  const T& operator[](size_t index) const {
    if (index >= length) {
        throw VectorIndexError("Invalid element index.");
    }
    return data[index];
  }

  inline bool empty(void) const noexcept {
    return length==0;
  }

  void clear(void){
    data = std::make_unique<T[]>(8);
    length=0;
    _capacity=8;
  }
  void resize(size_t new_capacity){
    auto new_data = std::make_unique<T[]>(new_capacity);
    if(new_data == nullptr) 
      throw VectorMemoryError("Error: memory allocation error");

    for(size_t i=0; i<length && i<new_capacity; i++)
      new_data[i] = data[i];

    data = std::move(new_data);
    this->_capacity = new_capacity;
    if(length > _capacity) length = _capacity;
  }
  ~Vector()=default;
};
signed main(void) {

  return 0;
}