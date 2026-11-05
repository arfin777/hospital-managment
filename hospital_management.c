#include <stdio.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

void addPatient();
void viewPatients();
void searchPatient();

int main() {
    int choice;

    while (1) {
        printf("\n=========================================\n");
        printf("       HOSPITAL MANAGEMENT SYSTEM        \n");
        printf("=========================================\n");
        printf("1. Add New Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Please enter a valid number!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\n[Error] Invalid choice! Pick between 1 and 4.\n");
        }
    }
    return 0;
}

void addPatient() {
    struct Patient p;

    FILE *file = fopen("patients.txt", "a");
    if (file == NULL) {
        printf("[Error] Could not open file to save data!\n");
        return;
    }

    printf("\n--- ADD NEW PATIENT ---\n");
    printf("Enter Patient ID (e.g., 101): ");
    scanf("%d", &p.id);

    printf("Enter Patient Name (one word): ");
    scanf("%s", p.name);

    printf("Enter Patient Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease (one word): ");
    scanf("%s", p.disease);

    fprintf(file, "%d %s %d %s\n", p.id, p.name, p.age, p.disease);

    fclose(file);

    printf("\n[Success] Patient record saved permanently to 'patients.txt'!\n");
}

void viewPatients() {
    struct Patient p;

    FILE *file = fopen("patients.txt", "r");
    if (file == NULL) {
        printf("\n[Info] No patient records found yet! (File is empty)\n");
        return;
    }

    printf("\n=========================================\n");
    printf("          ALL REGISTERED PATIENTS        \n");
    printf("=========================================\n");
    printf("ID\tName\t\tAge\tDisease\n");
    printf("-----------------------------------------\n");

    while (fscanf(file, "%d %s %d %s", &p.id, p.name, &p.age, &p.disease) == 4) {
        printf("%d\t%s\t\t%d\t%s\n", p.id, p.name, p.age, p.disease);
    }

    fclose(file);
    printf("-----------------------------------------\n");
}

void searchPatient() {
    struct Patient p;
    int searchId, found = 0;

    FILE *file = fopen("patients.txt", "r");
    if (file == NULL) {
        printf("\n[Info] No patient records found to search!\n");
        return;
    }

    printf("\nEnter Patient ID to search: ");
    scanf("%d", &searchId);

    while (fscanf(file, "%d %s %d %s", &p.id, p.name, &p.age, &p.disease) == 4) {
        if (p.id == searchId) {
   printf("\n[Found!] Patient Details:\n");
 printf("ID     : %d\n", p.id);
  printf("Name   : %s\n", p.name);
  printf("Age    : %d\n", p.age);
 printf("Disease: %s\n", p.disease);
found = 1;
  break;
 }
 }
 fclose(file);
if (!found) {
        printf("\n[Result] No patient found with ID %d.\n", searchId);
    }
}
