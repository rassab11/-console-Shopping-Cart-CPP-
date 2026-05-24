#include <iostream>          
#include <cstring>              
#include <ctime>                 
#include <cctype>                
using namespace std;



struct User {
    char name[30];      
    char pass[20];      
    char address[50];   
    int id;             
};


struct Item {
    char name[20];    
    int price;         
    int qty;            
    int total;       
};



void printLine() { cout << "===========================================" << endl; }


void printHeader() {
    printLine();                                   
    cout << "       SHOPPING MANAGEMENT SYSTEM" << endl;  
    printLine();                         
}


int main() {
  
    User u;                     
    Item items[5];          
    int count = 0;          
    int choice;           
    int orderNo;                
    double total = 0;            
    char payMethod[20];         
    char decision;         
    
    
    srand(time(0));                     
    orderNo = 1000 + rand() % 9000;
    
    printHeader();                     
    
    
    cout << "\n1. Login  2. Signup  3. Exit: ";
    cin >> choice;                      
    
    if (choice == 1) {             
        cout << "\nEnter Username: ";
        cin >> u.name;                 
        cout << "Enter Password: ";
        cin >> u.pass;                 
        cout << "Login Successful!" << endl;
    }
    else if (choice == 2) {             
        cout << "\n--- CREATE ACCOUNT ---" << endl;
        cout << "Username: ";
        cin >> u.name;               
        cout << "Password: ";
        cin >> u.pass;                  
        
        cout << "✓ Account Created Successfully!" << endl;
    }
    else {                              
        cout << "Goodbye!" << endl;
        return 0;                      
    }
    
   
    u.id = 10000 + rand() % 100;       
    cout << "Your User ID: " << u.id << endl;
    
    cout << "Billing Address: ";
                       
    cin.getline(u.address, 50);         
    
    
    
    char itemsName[4][20] = {"Grocery", "FastFood", "Electronic", "HouseHold"};
    int prices[4] = {7, 5, 15, 20};
    
    printHeader();                      
    cout << "\nAVAILABLE ITEMS:" << endl;
    
  
    for (int i = 0; i < 4; i++) {
        cout << i+1 << ". " << itemsName[i] << " - $" << prices[i] << endl;
    }
    
    cout << "\nAdd items? (y/n): ";
    cin >> decision;                   
    
   
    while (decision == 'y' || decision == 'Y') {
        cout << "Select item (1-4): ";
        cin >> choice;                
        
        if (choice >= 1 && choice <= 4) {   
            strcpy(items[count].name, itemsName[choice-1]);  
            items[count].price = prices[choice-1];           
            cout << "Quantity: ";
            cin >> items[count].qty;     
            items[count].total = items[count].price * items[count].qty;  
            count++;                      
        }
        else {                    
            cout << "Invalid choice!" << endl;
        }
        
        if (count >= 5) {               
            cout << "Cart full!" << endl;
            break;                       
        }
        
        cout << "Add more? (y/n): ";
        cin >> decision;              
    }
    

    if (count > 0) {                 
        printHeader();
        cout << "ORDER# " << orderNo << endl;
        printLine();
        cout << "Item          Price   Qty   Total" << endl;
        printLine();
        
        
        for (int i = 0; i < count; i++) {
            cout << items[i].name << "     $" << items[i].price 
                 << "     " << items[i].qty << "     $" << items[i].total << endl;
            total += items[i].total;    
        }
        
        printLine();
        cout << "TOTAL: $" << total << endl;
        printLine();
        
       
        cout << "\n1. Cash on Delivery" << endl;
        cout << "2. Credit Card" << endl;
        cout << "Choose payment: ";
        cin >> choice;                 
        
    
        switch (choice) {
            case 1:                     
                strcpy(payMethod, "Cash on Delivery"); 
                break;
            case 2:                   
                strcpy(payMethod, "Credit Card");
                cout << "Card#: ";
                cin >> u.pass;          
                break;
            default:                
                strcpy(payMethod, "Pending"); 
                break;
        }
        

     
        printHeader();
        cout << "      ORDER CONFIRMED!" << endl;
        cout << "Order #: " << orderNo << endl;
        cout << "Total: $" << total << endl;
        cout << "Pay: " << payMethod << endl;
        cout << "Address: " << u.address << endl;
        printLine();
        cout << "Thanks for shopping!" << endl;
    }
    else {                           
        cout << "\nNo items selected. Visit again!" << endl;
    }
    
    return 0;                         
}

