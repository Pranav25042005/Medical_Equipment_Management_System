#include<stdio.h>
#include<string.h>

#define MAX_EQUIPMENTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    char department[50];
} Equipment;

Equipment equipments[MAX_EQUIPMENTS];
int count = 0;

void addEquipment() {
    if (count == MAX_EQUIPMENTS) {
        printf("Storage full! Cannot add more equipment.\n");
        return;
    }
    printf("Enter Equipment ID: ");
    scanf("%d", &equipments[count].id);
    getchar(); // consume newline
    printf("Enter Equipment Name: ");
    fgets(equipments[count].name, sizeof(equipments[count].name), stdin);
    equipments[count].name[strcspn(equipments[count].name, "\n")] = 0; // remove newline
    printf("Enter Quantity: ");
    scanf("%d", &equipments[count].quantity);
    getchar();
    printf("Enter Department: ");
    fgets(equipments[count].department, sizeof(equipments[count].department), stdin);
    equipments[count].department[strcspn(equipments[count].department, "\n")] = 0;
    count++;
    printf("Equipment added successfully!\n");
}

void displayEquipments() {
    if (count == 0) {
        printf("No equipment to display.\n");
        return;
    }
    printf("\n--- Medical Equipment List ---\n");
    printf("%-5s %-20s %-10s %-20s\n", "ID", "Name", "Quantity", "Department");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10d %-20s\n", equipments[i].id, equipments[i].name, equipments[i].quantity, equipments[i].department);
    }
}

void searchEquipment() {
    int id;
    printf("Enter Equipment ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (equipments[i].id == id) {
            printf("Equipment found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nDepartment: %s\n",
                   equipments[i].id, equipments[i].name, equipments[i].quantity, equipments[i].department);
            return;
        }
    }
    printf("Equipment with ID %d not found.\n", id);
}

void updateQuantity() {
    int id, newQty;
    printf("Enter Equipment ID to update quantity: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (equipments[i].id == id) {
            printf("Current quantity: %d\n", equipments[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQty);
            equipments[i].quantity = newQty;
            printf("Quantity updated successfully.\n");
            return;
        }
    }
    printf("Equipment with ID %d not found.\n", id);
}

void deleteEquipment() {
    int id, index = -1;
    printf("Enter Equipment ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (equipments[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Equipment with ID %d not found.\n", id);
        return;
    }
    for (int i = index; i < count - 1; i++) {
        equipments[i] = equipments[i + 1];
    }
    count--;
    printf("Equipment deleted successfully.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Medical Equipment Management System ---\n");
        printf("1. Add Equipment\n");
        printf("2. Display All Equipments\n");
        printf("3. Search Equipment by ID\n");
        printf("4. Update Equipment Quantity\n");
        printf("5. Delete Equipment\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addEquipment();
                break;
            case 2:
                displayEquipments();
                break;
            case 3:
                searchEquipment();
                break;
            case 4:
                updateQuantity();
                break;
            case 5:
                deleteEquipment();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}