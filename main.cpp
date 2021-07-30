#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

// Food item
struct MenuItem
{
  int serial;
  int price;
  char name[20];
};
struct MenuItem menu[5];
// Order struct
struct Order
{
  int menuItemSerial;
  int quantity;
  struct Order *next;
} * front, *rear, *top;

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
void showMenu(struct MenuItem menu[]);
// Show both served and waiting
void showAll();
// Show sold items
void showSold();
// Show waiting queue
void showQueue();

int main()
{

  menu[0].serial = 01;
  menu[0].price = 100;
  strcpy(menu[0].name, "Expresso");

  menu[1].serial = 02;
  menu[1].price = 150;
  strcpy(menu[1].name, "Cold Coffee");

  menu[2].serial = 03;
  menu[2].price = 250;
  strcpy(menu[2].name, "Latte");

  menu[3].serial = 04;
  menu[3].price = 200;
  strcpy(menu[3].name, "Cappuchino");

  menu[4].serial = 05;
  menu[4].price = 350;
  strcpy(menu[4].name, "Special Creampied Coffee");

  showMenu(menu);

  return 0;
}
void showMenu(struct MenuItem menu[])
{

  printf("WELCOME!!!\n\n");
  int p;
  printf("Press 1 to see menu.\n");
  scanf("%d", &p);
  if (p == 1)
  {
    for (int i = 0; i < 5; i++)
    {
      printf("%d.\n", menu[i].serial);
      printf("Name: %s\n", menu[i].name);
      printf("Price: %d BDT", menu[i].price);
      printf("\n\n");
    }
  }
}

void showAll()
{
  cout << "List of Items Are Sold" << endl;
  showSold();
  cout << endl;
  cout << "List of Items Are is the Serial" << endl; 
  showQueue();
  cout << endl;
}

//show stack
void showSold()
{
  Order *temp = top;
  while(temp != NULL)
  {
    cout << temp->menuItemSerial << endl;
    cout << temp->quantity << endl;
    temp = temp->next;
  }
}

//show the queue
void showQueue()
{
  Order *temp = front;
  while(temp != rear)
  {
    cout << temp->menuItemSerial << endl;
    cout << temp->quantity << endl;
    temp = temp->next;
  }
}
