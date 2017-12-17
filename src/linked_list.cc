#include <iostream>

#include "linked_list.h"
#include <assert.h>

namespace algo{

  bool SLinkedList::isEmpty(){
    return is_empty;
  }

  bool SLinkedList::push_back(int num){
    is_empty = false;
    if (head == nullptr){
      head = std::make_shared<SLL_Node>(num);
      // std::cout << "HEAD++" << std::endl;
      return true;
    }
    SLL_Node slln{num};//std::make_shared<SLL_Node>(nullptr)};
    std::shared_ptr<SLL_Node> walk = head;
    while(walk->next != nullptr){//
      // std::cout << "__" << walk->data << "__";
      walk = walk->next;
    }
    // std::cout << std::endl;
    assert(walk != nullptr);//
    walk->next = std::make_shared<SLL_Node>(slln);
    // std::cout << "<<<<<<<<<" << walk->next->data << "<<<<<" << std::endl;
    if (walk->next->data == num) return true;
    return false;
  }

  size_t SLinkedList::size(){
    size_t rtn_val = 0;
    std::shared_ptr<SLL_Node> walk = head;
    while(walk){ // returns false if shared_ptr is null
      // std::cout << "size called" << std::endl;
      rtn_val++;
      walk = walk->next;
    }
    return rtn_val;
  }
}