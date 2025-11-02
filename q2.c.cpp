#include <stdio.h>

int cartCodes[20];
int cartQty[20];
int cartCount = 0;

void information(char name[100], char cnic[20]) {
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your cnic number: ");
    scanf("%s", cnic);
}
void display(int productcode[4], float price[4], int quantity[4]) {
    int i;
    printf("No.\tCode\tPrice\tQty\n");
    for (i = 0; i < 4; i++) {
        printf("%d\t%04d\t%.2f\t%d\n", i + 1, productcode[i], price[i], quantity[i]);
}
}

int add(float price[], int quantity[], int productcode[4], int totalBill) {
    int code;
    int qty, found = 0;
    char more = 'y';

    while (more == 'y' || more == 'Y') {
        printf("\nEnter product code: ");
        scanf(" %d", &code);

        printf("Enter quantity to buy: ");
        scanf("%d", &qty);

        found = 0;

        for (int i = 0; i < 4; i++) {
            if (code == productcode[i]) {
                found = 1;
                if (quantity[i] >= qty) {
                    quantity[i] -= qty;

                    cartCodes[cartCount] = code;
                    cartQty[cartCount] = qty;
                    cartCount++;

                    int itemCost = qty * price[i];
                    totalBill += itemCost;

                    printf(" Added! Cost: %d\n", itemCost);
                } else {
                    printf(" Not enough stock!\n");
                }
                break;
            }
        }

        if (!found)
            printf("Product not found!\n");
        printf("Add more items? (y/n): ");
        scanf(" %c", &more);
    }
    return totalBill;
}

void displayCart(float price[], int productcode[4], int totalBill) {
    printf("\nCART ITEMS:\n");
    printf("Code\tQty\tPrice\n");
    for (int i = 0; i < cartCount; i++) {
        printf("%03d\t%d\t", cartCodes[i], cartQty[i]);
        for (int j = 0; j < 4; j++) {
            if (cartCodes[i] == productcode[j]) {
                printf("%.2f\n", price[j]);
                break;
            }
        }
    }
int ans;
    printf("-------------------------\n");
    printf("Total without discount: %d\n", totalBill);
    printf("Do you have a code?");
    scanf(" %c", &ans);
    if(ans == 'y' || ans == 'Y') {
    	
	}
}

int main() {
    int quantity[4] = {50, 10, 20, 8};
    int productcode[4] = {001,002,003,004};
    float price[4] = {100, 200, 300, 150};

    char name[100], cnic[20];
    int totalBill = 0;
    int choice = 0;
int totalprice;
    while (choice != 6) {
        printf("\n===== SUPERMARKET MENU =====\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Cart\n");
        printf("5. Show Invoice (Total Bill)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                information(name, cnic);
                break;

            case 2:
                display(productcode, price, quantity);
                break;

            case 3:
                totalBill = add(price, quantity, productcode, totalBill);
                break;

            case 4:
                displayCart(price, productcode,totalBill);
                break;

            case 5:
                printf("\nTotal Bill = %d\n", totalBill);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

