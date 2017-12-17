#ifndef SRC_ALGO_LINKED_LIST
#include <memory>

  namespace algo{
    
    struct SLL_Node{
      int data;
      std::shared_ptr<SLL_Node> next;
      SLL_Node():data(0), next(nullptr){}
      SLL_Node(int _d): data(_d), next(nullptr){}
    };

    class SLinkedList{
      public:
        
        SLinkedList(): is_empty(true), head(nullptr){};
        bool isEmpty();
        bool push_back(int num);
        size_t size();
      private:
        std::shared_ptr<SLL_Node> head;
        bool is_empty;
    };

  }
#endif