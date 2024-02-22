#include <stdio.h>
#include <string.h>

struct Medicine {
    char code[7];
    char name[20];
    char disease[20];
    int stock;
    float price;
};

void displayMedicines(struct Medicine medicines[], int totalMedicines) {
    printf("+----+--------------+----------------------+--------------+--------+--------+\n");
    printf("| %-2s | %-12s | %-20s | %-12s | %-6s | %-6s |\n", "No", "Medicine Code", "Medicine Name", "Disease", "Stock", "Price");
    printf("+----+--------------+----------------------+--------------+--------+--------+\n");
    for (int i = 0; i < totalMedicines; ++i) {
        printf("| %-2d | %-12s | %-20s | %-12s | %-6d | Rp %-4.2f |\n", i + 1, medicines[i].code, medicines[i].name,
               medicines[i].disease, medicines[i].stock, medicines[i].price);
    }
    printf("+----+--------------+----------------------+--------------+--------+--------+\n");
}

void addStock(struct Medicine medicines[], int totalMedicines) {
    char inputCode[7];
    int quantity;

    printf("\nInput medicine code: ");
    scanf("%s", inputCode);

    int index = -1;
    for (int i = 0; i < totalMedicines; ++i) {
        if (strcmp(inputCode, medicines[i].code) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine Code Doesn't Exist!\n");
        return;
    }

    printf("Input quantity (1-100): ");
    scanf("%d", &quantity);

    if (quantity < 1 || quantity > 100) {
        printf("Invalid quantity. Input again.\n");
        return;
    }

    medicines[index].stock += quantity;

    printf("Press Enter to continue...\n");
    getchar();
    getchar();
}

void sellMedicine(struct Medicine medicines[], int totalMedicines) {
    char inputCode[7];
    int quantity;

    printf("\nInput medicine code: ");
    scanf("%s", inputCode);

    int index = -1;
    for (int i = 0; i < totalMedicines; ++i) {
        if (strcmp(inputCode, medicines[i].code) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine Code Doesn't Exist!\n");
        return;
    }

    printf("Input quantity (1-%d): ", medicines[index].stock);
    scanf("%d", &quantity);

    if (quantity < 1 || quantity > medicines[index].stock) {
        printf("Invalid quantity. Input again.\n");
        return;
    }

    float totalPrice = medicines[index].price * quantity;
    printf("Total Price = Rp %.2f x %d = Rp %.2f\n", medicines[index].price, quantity, totalPrice);

    medicines[index].stock -= quantity;

    printf("Available stock after sale: %d\n", medicines[index].stock);

    printf("Press Enter to continue...\n");
    getchar();
    getchar();
}

int main() {
    struct Medicine medicines[] = {
        {"DIZ001", "Paramex", "Dizziness", 120, 14000.0},
        {"FLU001", "Panadol", "Flu & Fever", 57, 8000.0},
        {"DIAG01", "Diatabs", "Diarrhea", 10, 6500.0},
        {"DIA002", "Diapet", "Diarrhea", 18, 6000.0}
    };

    int totalMedicines = sizeof(medicines) / sizeof(medicines[0]);

    displayMedicines(medicines, totalMedicines);

    int choice;
    do {
        printf("\n1. Add Stock\n");
        printf("2. Sell\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(medicines, totalMedicines);
                break;
            case 2:
                sellMedicine(medicines, totalMedicines);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
