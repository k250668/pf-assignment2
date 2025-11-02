#include <stdio.h>

int rows = 4;     
int column = 4;   

void status(int grid[4][4]) {
    int r, c, bit, action;

 printf("Enter sector coordinates (row [0-3] col [0-3]): ");

    scanf("%d %d", &r, &c);

    if (r >= rows || c >= column || r < 0 || c < 0) {
        printf("Invalid coordinates!\n");
        return; 
    }

    printf("Select status to update:\n");
    printf("0. POWER\n1. OVERLOAD\n2. MAINTENANCE\n");
    scanf("%d", &bit);

    printf("Action? (1 = Set, 0 = Clear): ");
    scanf("%d", &action);

    if (action == 1) {
        grid[r][c] |= (1 << bit);
        printf("Status set to ON!\n");
    } else {
        grid[r][c] &= ~(1 << bit);
        printf("Status set to OFF!\n");
    }

    printf("Updated Sector Value: %d\n", grid[r][c]);
}

void display(int grid[4][4]) {
	int r;
	int c;
    printf("Enter sector coordinates (row col): ");
    scanf("%d %d", &r, &c);
int value = grid[r][c];
    if (r >= rows || c >= column || r < 0 || c < 0) {
        printf("Invalid coordinates!\n");
        return; 
    }
    if (value & (1 << 0)) {  
        printf("Power Status: ON \n");
    } else {
        printf("Power Status: OFF \n");
    }

    if (value & (1 << 1)) {
        printf("Overload Warning  : OVERLOADED \n");
    } else {
        printf("Overload Warning  : NORMAL \n");
    }
    if (value & (1 << 2)) {
        printf("Maintenance Needed: YES\n");
    } else {
        printf("Maintenance Needed: NO\n");
    }
}

void Diagnostic(int grid[4][4]) {
    int r, c;
    int overloadCount = 0;
    int maintenanceCount = 0;
    for (r = 0; r < 4; r++) {
        for (c = 0; c < 4; c++) {
            int value = grid[r][c];

            if (value & (1 << 1)) {  
                overloadCount++;
            }
            if (value & (1 << 2)) {  
                maintenanceCount++;
            }
        }
    }

    printf("\n--- SYSTEM DIAGNOSTIC REPORT ---\n");
    printf("Total sectors OVERLOADED       : %d\n", overloadCount);
    printf("Total sectors NEED MAINTENANCE: %d\n", maintenanceCount);
}

int main() {
    int choice;
    int grid[4][4] = {0}; 

    while (1) {
        printf("\n--- IESCO POWER GRID MENU ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                status(grid);
                break;

            case 2:
                display(grid);
               break;
            case 3:
            	Diagnostic(grid);
            	break;
            case 4:
            	printf("THANK YOU!BYE!");
            	return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

