#include <stdio.h>


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

int add(float price[], int quantity[], int productcode[4], int totalbill) {
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

                    int itemCost = qty * price[i];
                    totalbill += itemCost;

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
    return totalbill;
}

void displayCart(float price[],int discount, int productcode[4], int totalbill) {
   
        
int ans;

    printf("Total without discount: %d\n", totalbill);
    printf("Do you have a discount code (EID2025)?");
    scanf(" %c", &ans);
    discount = totalbill;
    if(ans == 'y' || ans == 'Y') {
    	discount = discount *0.25;
	}
}
void invoice( int discount , int totalbill,char name[100], char cnic[20]) {
	printf("NAME: %s", name);
	printf("CNIC : %s", cnic);
	if (discount < totalbill) {
		printf("Discounted bill: %d \n", discount);
		printf("Total bill without discount: %d\n", totalbill);
	}
	else {
		printf("Totalbill: %d", totalbill);
	}
}

int main() {
	int discount;
    int quantity[4] = {50, 10, 20, 8};
    int productcode[4] = {001,002,003,004};
    float price[4] = {100, 200, 300, 150};

    char name[100], cnic[20];
    int totalbill = 0;
    int choice = 0;
int totalprice;
    while (choice != 6) {
        printf("\n===== SUPERMARKET MENU =====\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Cart\n");
        printf("5. Show Invoice (Total bill)\n");
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
                totalbill=add(price, quantity, productcode, totalbill);
                break;

            case 4:
                displayCart(price, discount,  productcode,  totalbill);
                break;

            case 5:
            invoice(discount,totalbill,name,cnic);
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
