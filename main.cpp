#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

// Food item
struct MenuItem
{
  int serial;
  int price;
  char name[30];
};
struct MenuItem menu[5];
// Order struct
struct Order
{
  int menuItemSerial;
  int quantity;
  struct Order *next;
} *front, *rear, *top;

int navChoice; 

// Helper functions
void enqueue(int serial, int quantity);
void push(Order served);
Order dequeue(int serial, int quantity);

// Place an order
void placeOrder();
// Serve an order
void serve();
// Show receipt
void showReceipt();
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
  strcpy(menu[0].name, "Espresso");

  menu[1].serial = 02;
  menu[1].price = 150;
  strcpy(menu[1].name, "Cold Coffee");

  menu[2].serial = 03;
  menu[2].price = 250;
  strcpy(menu[2].name, "Latte");

  menu[3].serial = 04;
  menu[3].price = 200;
  strcpy(menu[3].name, "Cappucino");

  menu[4].serial = 05;
  menu[4].price = 350;
  strcpy(menu[4].name, "Special Creampied Coffee");

  while (true)
  {
    printf("1. See coffees\n");
    printf("2. Place order\n");
    printf("3. See waiting queue\n");
    printf("4. Serve next order\n");
    printf("5. See sales report\n");
    printf("6. See overall report\n");
    printf("0. Exit\n");

    printf("Your choice: ");
    scanf("%d", &navChoice);

    if(!navChoice) break; 
    
    switch (navChoice)
    {
    case 1:
      system("cls");
      showMenu(menu);
      break;

    case 2:
      placeOrder();
      break;
    
    case 3:
      system("cls"); 
      showQueue();
      break;

    case 4:
      serve();
      break;

    case 5:
      system("cls");
      showSold();
      break;

    case 6:
      system("cls");
      showAll();
    
    default:
      break;
    }
  }
  
  return 0;
}

void showMenu(struct MenuItem menu[])
{
  for (int i = 0; i < 5; i++)
  {
    printf("%d. ", menu[i].serial);
    printf("Name: %s, ", menu[i].name);
    printf("Price: %d BDT", menu[i].price);
    printf("\n");
  }

  printf("Press any key to continue...");
  getch();
  printf("\n");
}

void showAll()
{
  cout << "Sold items:" << endl;
  showSold();
  cout << endl;
  cout << "Waiting orders:" << endl; 
  showQueue();
  cout << endl;
}

//show stack
void showSold()
{
  Order *temp = top;
  int sum = 0;

  while(temp != NULL)
  {
    MenuItem target = menu[temp->menuItemSerial - 1];
    printf("Coffee: %s, Quantity: %d\n", target.name, temp->quantity);

    sum += target.price * temp->quantity; 
    temp = temp->next;
  }

  printf("Total revenue: %d BDT\n", sum); 

  // Code for interaction 
  printf("Press any key to continue...");
  getch();
  system("cls"); 
}

//show the queue
void showQueue()
{
  Order *temp = front;
  while(temp != NULL)
  {
    MenuItem target = menu[temp->menuItemSerial - 1];
    printf("Coffee: %s, Quantity: %d\n", target.name, temp->quantity);
    temp = temp->next;
  }

  // Code for interaction 
  printf("Press any key to continue...");
  getch();
  system("cls"); 
}

void placeOrder()
{
  int numberOfCoffee, quantityOfEach, serial;

  printf("The number of different coffees you wanna buy: "); 
  scanf("%d", &numberOfCoffee);

  for (int i = 1; i <= numberOfCoffee; i++)
  {
    printf("Enter coffee %d: ", i);
    scanf("%d", &serial); 
    printf("Enter quantity for coffee %d: ", i);
    scanf("%d", &quantityOfEach);

    enqueue(serial, quantityOfEach); 
  }  

  printf("\nYOUR RECEIPT:\n");
  showReceipt(); 

  // Code for interaction 
  printf("Press any key to continue...");
  getch();
  system("cls"); 
}

void enqueue(int serial, int quantity)
{
  MenuItem target = menu[serial - 1];

  if(front == NULL)
  {
    Order *newNode = (Order*) malloc(sizeof(Order)); 

    newNode->menuItemSerial = serial;
    newNode->quantity = quantity; 
    newNode->next = NULL; 

    front = newNode;
    rear = newNode; 

    printf("%d %s(s) added to the waiting queue\n",  quantity, target.name);  
    return; 
  }

    Order *newNode = (Order*) malloc(sizeof(Order)); 

    newNode->menuItemSerial = serial;
    newNode->quantity = quantity; 
    newNode->next = NULL; 

    rear->next = newNode;
    rear = newNode;

    printf("%d %s(s) added to the waiting queue\n",  quantity, target.name); 
    return; 
}

void push(Order served)
{
  if(top == NULL)
  {
    Order *newNode = (Order*) malloc(sizeof(Order)); 

    newNode->menuItemSerial = served.menuItemSerial; 
    newNode->quantity = served.quantity; 
    newNode->next = top;

    top = newNode; 
    printf("Sale added to record\n");
    return; 
  }

  Order *newNode = (Order*) malloc(sizeof(Order)); 

  newNode->menuItemSerial = served.menuItemSerial; 
  newNode->quantity = served.quantity; 
  newNode->next = top;

  top = newNode; 
  printf("Sale added to ledger\n");
  return; 
}

Order dequeue() 
{
  Order deq; 

  if(front == NULL) 
  {
    printf("No one is waiting!\n");
    return deq;
  }

  Order *temp = front; 
  front = front->next; 

  deq.menuItemSerial = temp->menuItemSerial;
  deq.quantity = temp->quantity; 

  free(temp);
  printf("Order served!\n"); 

  return deq; 
}

void showReceipt()
{
 Order *temp = front; 
 int sum = 0; 

 while (temp != NULL)
 {
   MenuItem target = menu[temp->menuItemSerial - 1];
   printf("Coffee: %s, Quantity: %d, Price: %d\n", target.name, temp->quantity, target.price * temp->quantity);

   // Add price to the sum 
   sum += target.price * temp->quantity;
   temp = temp->next; 
 } 

 printf("Total price: %d\n", sum); 
}

void serve()
{
  Order deq = dequeue();
  push(deq); 

  // Code for interaction 
  printf("Press any key to continue...");
  getch();
  system("cls"); 
}
