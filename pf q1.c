#include <stdio.h>
void add(int isbns[100],char titles[100][50],float prices[100],int quantities[100],int *book) {
	printf("Enter isbn of book you want to add: ");
	scanf("%d", &isbns[*book]);
int i;
	for (i = 0 ; i< *book ; i++) {
		if (*book != 0) {
	 if(isbns[*book] == isbns[i]) {
	 	printf("Innvalid");
	 	return ;
	 } } }
		printf("Enter title of book you want to add: ");
	scanf("%s", titles[*book]);
		printf("Enter price of book you want to add: ");
	scanf("%f", &prices[*book]);
	printf("Enter quantity of book you want to add: ");
	scanf("%d", &quantities[*book]);
		(*book)++;
		printf("BOOk ADDED! Total books = %d", *book);
}

 void process(int isbns[100],
	char titles[100][50],
float prices[100],
int quantities[100],int *book) {
	int i;
	int search;
	int copies;
	printf("Enter isbn of book you want to sell: \n");
	scanf("%d", &search);
	printf("Enter number of copies: ");
	scanf("%d", &copies);
	for (i = 0 ; i< *book;i++) {
		if(isbns[i] == search) {
			if(copies<= quantities[i]) {
				quantities[i] = quantities[i] - copies;
				printf("DONE!, upadated quantity = %d\n", quantities[i]);
			
			}
			else {
				printf("Not enough copies sorry!#n");
		} 
			return;
		}
		else {
			printf("Book not found!\n");
			 }
		}
		
}

void lowstock(int isbns[100],
	char titles[100][50],
float prices[100],
int quantities[100],int *book) {
	int i;
	printf("Low stock books (less than 5 left):\n");
	for (i = 0 ; i < *book ; i++) {
		if (quantities[i] < 5) {
			printf("ISBN: %d\n", isbns[i]);
			printf("Title: %s\n", titles[i]);
			printf("Price: %.2f\n", prices[i]);
			printf("Quantity: %d\n\n", quantities[i]);
		}
	}
}

int main() {
	int count = 0;
	int quantity;
	int isbns[100];
	char titles[100][50];
float prices[100];
int quantities[100];
int choice;
while(choice != 4) {
 printf("\nChoose one of the options:\n");
        printf("1. Add new book\n");
        printf("2. Process a sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

	
	switch (choice) {
		case 1:
		    add(isbns, titles, prices, quantities, &count);
		    break;
		case 2:
		 process(isbns, titles, prices, quantities, &count);
		 break;
		 case 3:
		 lowstock(isbns, titles, prices, quantities, &count);
		 break;
		 case 4:
		 	printf("THANK YOU!");
		 	break;
	}
	
}

	return 0;
}
