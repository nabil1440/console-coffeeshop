#include <iostream>
#include <stdlib.h>
using namespace std;

// Food item 
struct MenuItem {
  int serial;
  int price; 
  char name[20];
};

// Order struct 
struct Order {
  int menuItemSerial; 
  int quantity; 
  struct Order *next; 
} *front, *rear, *top; 

// Helper functions 
void enqueue(); 
void push(); 
void dequeue(); 


// Place an order 
void placeOrder(); 
// Serve an order 
void serve(); 
// Show receipt 
void showReceipt(); 
// Show initial menu 
void showUI(); 
// Show food menu 
void showMenu(); 
// Show both served and waiting 
void showAll(); 
// Show sold items 
void showSold(); 
// Show waiting queue 
void showQueue(); 


int main()
{

  MenuItem menu[5] = {};

  return 0;
}
