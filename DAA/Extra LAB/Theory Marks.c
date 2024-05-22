#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char sapID[20];
    char enrollNo[20];
    char name[50];
    int quiz1;
    int midSem;
    int quiz2;
    int endSem;
    float total;
};

void readCSV(FILE *file, struct Student students[], int *numStudents) {
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^,],%[^,],%[^,],%d,%d,%d,%d",
                   students[*numStudents].sapID,
                   students[*numStudents].enrollNo,
                   students[*numStudents].name,
                   &students[*numStudents].quiz1,
                   &students[*numStudents].midSem,
                   &students[*numStudents].quiz2,
                   &students[*numStudents].endSem) == 7) {
            (*numStudents)++;
        } else {
            printf("Error reading line: %s\n", line);
        }
    }
}

void sortStudents(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void calculateTotalPercentage(struct Student *student) {
    student->total = student->quiz1 + 0.2 * student->midSem +
                     student->quiz2 + 0.5 * student->endSem;
}

void writeOutputCSV(struct Student students[], int numStudents) {
    FILE *outputFile = fopen("C:\\Users\\laugh\\OneDrive\\Desktop\\DAA\\Extra LAB\\output.csv", "w");

    if (outputFile == NULL) {
        printf("Error creating output file!\n");
        return;
    }

    fprintf(outputFile, "SAP ID,Enroll No.,Name,Quiz 1,Mid-Sem,Quiz 2,End-Sem,Total\n");

    for (int i = 0; i < numStudents; i++) {
        fprintf(outputFile, "%s,%s,%s,%d,%d,%d,%d,%.2f%%\n",
                students[i].sapID, students[i].enrollNo, students[i].name,
                students[i].quiz1, students[i].midSem, students[i].quiz2,
                students[i].endSem, students[i].total);
    }

    fclose(outputFile);
}

int main() {
    FILE *file = fopen("C:\\Users\\laugh\\OneDrive\\Desktop\\DAA\\Extra LAB\\Theory marks (1).csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    struct Student students[100];
    int numStudents = 0;

    readCSV(file, students, &numStudents);
    fclose(file);

    sortStudents(students, numStudents);

    for (int i = 0; i < numStudents - 1; i++) {
        if (strcmp(students[i].sapID, students[i + 1].sapID) == 0 ||
            strcmp(students[i].enrollNo, students[i + 1].enrollNo) == 0) {
            printf("Error: Duplicate SAP ID or Enrollment Number detected!\n");
            return 1;
        }
    }

    for (int i = 0; i < numStudents; i++) {
        calculateTotalPercentage(&students[i]);
    }

    printf("%-10s %-15s %-30s %-6s %-6s %-6s %-6s %-10s\n",
           "SAP ID", "Enroll No.", "Name", "Quiz1", "MidSem", "Quiz2", "EndSem", "Total");

    for (int i = 0; i < numStudents; i++) {
        printf("%-10s %-15s %-30s %-6d %-6d %-6d %-6d %-10.2f%%\n",
               students[i].sapID, students[i].enrollNo, students[i].name,
               students[i].quiz1, students[i].midSem, students[i].quiz2,
               students[i].endSem, students[i].total);
    }

    writeOutputCSV(students, numStudents);

    return 0;
}
