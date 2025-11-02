#include <stdio.h> 
#include <string.h>

void encodeMessage(char message[]) {
	int i,j;
	int length = 0;
	int temp;
	  

	for ( i = 0; message[i] != '\0' ; i++) {
		length++; }
		j = length-1;
		for (i = 0;i<j;i++){
			temp = message[i];
			message[i] = message[j];
			message[j]= temp;
			j--;
		}
	printf("reversed message is: %s \n", message);
	
	for(i = 0 ; i<length;i++){
		message[i] ^= (1 << 2) | (1 << 5);
	}
printf("Encoded message: %s ", message);
}

void decode(char message[]) {
	int i,j;
	int length = 0;
	int temp;

	
	for (i = 0; message[i] !='\0'; i++) {
		length++; }
		for(i = 0 ; i<length;i++){
		message[i] ^= (1 << 2) | (1 << 5);
	}

		j = length-1;
		for (i = 0;i<j;i++){
			temp = message[i];
			message[i] = message[j];
			message[j]= temp;
			j--;
		}
	printf("Decoded message is: %s \n", message);
}

int main() {
	char message[100];
	int length;
	 int choice;
    while (1) {
    	printf("\nTCS Message Encoder/Decoder\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter the message: ");
                fgets(message, sizeof(message), stdin);
                encodeMessage(message);
                break;

            case 2:
                printf("Enter the message: ");
                fgets(message, sizeof(message), stdin);
             
                decode(message);
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
	}
	return 0;
}
