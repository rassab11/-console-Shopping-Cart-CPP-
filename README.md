# Console Shopping Management System (C++)

This is a simple **console-based Shopping Management System** written in **C++**.

It allows a user to:
- **Login** or **Signup**
- Display a small catalog of items
- Build a cart by selecting items and quantities
- Calculate the billing **total**
- Confirm the **order** with an order number
- Choose a payment method: **Cash on Delivery** or **Credit Card**

## How it works

1. The program starts by printing the main menu:
   - `1. Login`
   - `2. Signup`
   - `3. Exit`
2. After login/signup, it shows a catalog of items:
   - Grocery
   - FastFood
   - Electronic
   - HouseHold
3. You can add items to the cart (up to 5 cart lines).
4. The program prints an **order summary** including item totals and the overall **TOTAL**.
5. It then asks for payment choice and shows an **Order Confirmed** screen.

## Features implemented
- Basic user flow (Login/Signup)
- In-memory cart building
- Item total calculation: `item price * quantity`
- Random generated order number
- Simple payment selection and order confirmation

## Compile & Run

### macOS / Linux (g++)
```bash
g++ "semister_project (1).cpp" -o shopping
./shopping
```

### Windows (MinGW)
```bash
g++ "semister_project (1).cpp" -o shopping.exe
shopping.exe
```

## Notes
- All data is stored only during runtime (no database / no file storage).
- If the cart reaches the limit (5 items), it will stop adding more.

