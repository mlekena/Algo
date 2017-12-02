#ifndef SRC_ALGO_LINKED_LIST
  namespace algo{
    
    class SLinkedList{
      public:
        SLinkedList(): is_empty(true){};
        bool isEmpty();
        bool push_back(int num);
      private:
        bool is_empty;
    };

  }
#endif