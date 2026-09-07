#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

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
        printf("\n4. Exit");

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
                printf("\nThank you for using Simple Line Editor!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}