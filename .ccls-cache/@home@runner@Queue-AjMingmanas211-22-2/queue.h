#include <iostream>
#include <iomanip>
#include "node.h"

class Queue {
  NodePtr head, tail;
  int size;

public:
  void enqueue(int, int);
  int dequeue();
  Queue();
  ~Queue(); // dequeue all
  bool isEmpty();
  int getSize();
  NodePtr getHead();
};


Queue::Queue() {
  size = 0;
  head = nullptr;
  tail = nullptr;
}

bool Queue::isEmpty() {
  return (head == nullptr && tail == nullptr);
}

Queue::~Queue() {
  while (!isEmpty()) {
    dequeue();
  }
}

void Queue::enqueue(int menu, int qty) {
  NodePtr new_node = new NODE(menu, qty);

  if (new_node != nullptr) {
    if (isEmpty()) {
      head = new_node;
    } else {
      tail->set_next(new_node);
    }
    tail = new_node;
    ++size;
  } else {
    std::cout << "Overflow" << "\n";
  }
}

int Queue::dequeue() {
  int value = 0;
  if (!isEmpty()) {
    NodePtr tmp = head;
    value = tmp->get_value();
    head = head->get_next();
    delete tmp;
    --size;
    if (isEmpty()) {
      tail = nullptr;
    }
  }
  return value;
}

int Queue::getSize() {
  return size;
}

NodePtr Queue::getHead() {
  return head;
}
