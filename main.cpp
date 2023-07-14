#include <iostream>
#include <iomanip>

using namespace std;

#include "node.h"
#include "queue.h"

void displayMenu(){
  cout << "List of order number" << "\n";
  cout << "  1. Ramen 100 Baht" << "\n";
  cout << "  2. Somtum 20 Baht" << "\n";
  cout << "  3. Fried Chicken 50 Baht" << "\n";
  cout << "\n";
}

int main(int argc, char* argv[]){
  Queue q;
  int size;

  int price;
  int order = 0, qty = 0;
  int num = 1;
  int current_cash = 0;

  for(int i = 1; i < argc; i += 2){
    int price = 0, cash_paid = 0; 
    if(argv[i][0] == 'x'){
      if(q.getSize() <= 0){
        cout << "Empty queue" << "\n";
        break;
      }
      price = q.dequeue();
      cout << "Customer no : "<< num <<"\n";
      cout << "You have to pay " << price << "\n\n";

      while(price != 0 && current_cash < price){
        cout << "Cash : ";
        cin >> cash_paid;
        current_cash += cash_paid;
        if(current_cash < price){
          cout << "Please pay more " << price - current_cash << " or more"<< "\n";
        }
      }

      cout << "Thank you" << "\n\n";
      if(current_cash >= price){
        cout << "Change is : " << current_cash - price << "\n\n";
        
        current_cash = 0;
      }
      num++;
      i--;
    }
    else{
      if(atoi(argv[i]) < 1 || atoi(argv[i]) > 3 || atoi(argv[i + 1]) < 0){
        cout << "Invalid orders" << "\n";
        continue;
      }
      else{
        q.enqueue(atoi(argv[i]), atoi(argv[i + 1]));
      }
    }
    size = ((q.getSize() > 0) ? q.getSize() : 0);
  }
  cout << "\n" << setw(20) << setfill('=') << "=\n";
  cout << "There are " << size << " people left in the queue" << "\n";

  return 0;
}
