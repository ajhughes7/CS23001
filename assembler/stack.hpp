#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    10/2019
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>
////////////////////////////////////////////////////////////////////////////
// CLASS INV: Last Node in list has next = 0.           
//
// 
template<typename T> 
class Node {
public:
  Node() : next(0) {};
  Node(const T& item) : data(item), next(0) {};
  T data;
  Node<T> *next; 
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV: tos is either 0 or a linked list of Nodes
//
//    
template <typename T>
class stack {
public:
              stack() : tos(0) {};
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
  stack<T>& operator= (stack<T> rhs) {swap(rhs); return *this;};
        bool      empty     () const {return tos == 0;};
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};


template <typename T>
bool stack<T>::full() const {
  Node<T> *ptr = new(std::nothrow) Node<T>();
  if (ptr == 0) return true;
  delete ptr;
  return false;
}


template <typename T>
void stack<T>::push(const T& item) {
  assert(!full());
  Node<T> *temp = new Node<T>(item);
  temp->next = tos;
  tos = temp;
}

template <typename T>
T stack<T>::pop() {
  assert(!empty());
  Node<T> *temp = tos; // so that initial tos node can be deleted after updating  tos
  T result = tos->data; // so initial tos data can be returned after updating tos
  tos = tos->next; // update tos
  delete temp; // free up space from node that was popped
  return result; // original tos data returned
}

template <typename T>
T stack<T>::top() const {
  assert(!empty());  
  return tos->data;
}

template <typename T>
void stack<T>::swap(stack<T>& rhs) {
  Node<T> *temp = tos; 
  tos = rhs.tos;
  rhs.tos = temp; 
}


template <typename T>
stack<T>::stack(const stack<T>& rhs) : stack() {
  Node<T> *rhsTemp = rhs.tos, *lhsTemp;
  while(rhsTemp != 0) {
    if (tos == 0) {
      tos = new Node<T>(rhsTemp->data);
      lhsTemp = tos;
    } else {
      lhsTemp->next = new Node<T>(rhsTemp->data);
      lhsTemp = lhsTemp->next;
    }
    rhsTemp = rhsTemp->next;
  }
}

template <typename T>
stack<T>::~stack() {
  Node<T> *tmp;
  while (tos != 0) {
    tmp = tos;
    tos = tos->next;
    delete tmp;
  }
}

#endif

