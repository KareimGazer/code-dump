template<typename T>
class Vector3
{
  public: Vector3(T x, T y, T z)
  {
    this->data[0] = x;
    this->data[1] = y;
    this->data[2] = z;

    // for iterator
    this->head = &data[0];
    this->tail = &data[2];
  }
  public: Vector3()
  {
    Vector3(0, 0, 0);
  }

  public: class Iterator;

  public: Iterator begin(){return Iterator(this->head, this->tail);}
  public: Iterator end(){return Iterator(nullptr, nullptr);}
public: class Iterator
      {
        public:
          // Iterator()
          // {
          //   this->currentPtr = head;
          //   this->lastPtr = tail;
          // }

          Iterator(const T* cPtr, const T* lPtr)
          {
              this->currentPtr = cPtr;
              this->lastPtr = lPtr;
          }
 
          Iterator& operator=(Iterator iterator)
          {
            this->currentPtr = iterator.currentPtr;
            this->lastPtr = iterator.lastPtr;
            return *this;
          }
 
          // Prefix ++ overload
          Iterator& operator++(){
            if(this->currentPtr == this->lastPtr) currentPtr = nullptr;
            if (this->currentPtr) currentPtr++;
            return *this;
          }
 
        //Postfix ++ overload
          Iterator operator++(int){
            Iterator iterator = *this;
            ++*this;
            return iterator;
          }
 
        bool operator!=(const Iterator& iterator){
            return this->currentPtr != iterator.currentPtr;
        }

        bool operator==(const Iterator& iterator){
            return this->currentPtr == iterator.currentPtr;
        }
 
        int operator*(){return *currentPtr;}
 
  private:
        const T* currentPtr; const T* lastPtr;
  };
  
  public: T* head; T* tail;
  private: T data[3];
};
