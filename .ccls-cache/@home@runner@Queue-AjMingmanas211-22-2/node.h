#include <iostream>
#include <iomanip>

#ifndef node_h
#define  node_h

class NODE{
	 int menu, qty;
	NODE *next;
public:
	NODE(int, int);
	~NODE();
  int get_value();
	void set_next(NODE *);
	NODE* get_next();
  int get_order();
};
typedef NODE* NodePtr;

NODE::NODE(int menu, int qty){
	this->menu = menu;
  this->qty = qty;
  std::cout << "Order : " << qty << " " << ((menu == 1) ? "Ramen" : (menu == 2) ? "Somtum" : "Fried Chicken") << "\n";
	next = NULL;

}
int NODE::get_value() {
  int total;
  switch (menu) {
    case 1:
      total = 100 * qty;
      break;
    case 2:
      total = 20 * qty;
      break;
    case 3:
      total = 50 * qty;
      break;
    default:
      total = 0;
      break;
  }
  return total;
}


NODE* NODE::get_next(){
	return next;

}

void NODE::set_next(NODE *next){
	 this->next = next;

}

NODE::~NODE(){}

int NODE::get_order(){
  return menu;
}

#endif