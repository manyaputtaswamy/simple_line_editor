#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Function to display the document */
void display()
{
    int i;

    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n--- Document ---\n");

    for (i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

/* Function to insert a line */
void insertLine()
{
    int position;
    int i;

    if (lineCount >= MAX_LINES)
    {
        printf("\nDocument is full.\n");
        return;
    }

    printf("\nEnter line number to insert at: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter the text: ");
    fgets(lines[position - 1], MAX_LENGTH, stdin);

    lines[position - 1][strcspn(lines[position - 1], "\n")] = '\0';

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Function to delete a line */
void deleteLine()
{
    int position;
    int i;

    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\nEnter line number to delete: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Function to save the document to a file */
void saveFile()
{
    FILE *file;
    int i;

    file = fopen("document.txt", "w");

    if (file == NULL)
    {
        printf("\nUnable to save file.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("\nFile saved successfully as document.txt\n");
}

/* Function to load the document from a file */
void loadFile()
{
    FILE *file;

    file = fopen("document.txt", "r");

    if (file == NULL)
    {
        printf("\nNo saved file found.\n");
        return;
    }

    lineCount = 0;

    while (lineCount < MAX_LINES &&
           fgets(lines[lineCount], MAX_LENGTH, file) != NULL)
    {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;
    }

    fclose(file);

    printf("\nFile loaded successfully.\n");
    printf("Total lines loaded: %d\n", lineCount);
}

/* Function to search for text */
void searchText()
{
    char search[MAX_LENGTH];
    int i;
    int found = 0;

    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\nEnter text to search: ");
    fgets(search, MAX_LENGTH, stdin);

    search[strcspn(search, "\n")] = '\0';

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], search) != NULL)
        {
            printf("Text found in line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found in the document.\n");
    }
}

int main()
{
    int choice;

    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("=================================\n");

    while (1)
    {
        printf("\n1. Insert Line");
        printf("\n2. Delete Line");
        printf("\n3. Display Document");
        printf("\n4. Save File");
        printf("\n5. Load File");
        printf("\n6. Search Text");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                display();
                break;

            case 4:
                saveFile();
                break;

            case 5:
                loadFile();
                break;

            case 6:
                searchText();
                break;

            case 7:
                printf("\nThank you for using Simple Line Editor!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
