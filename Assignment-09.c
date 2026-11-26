#include <stdio.h>

int main()
{
    FILE *source, *destination;
    char sourceFile[100], destinationFile[100];
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourceFile);

    printf("Enter destination file name: ");
    scanf("%s", destinationFile);

    source = fopen(sourceFile, "r");

    if(source == NULL)
    {
        printf("Unable to open source file.");
        return 1;
    }

    destination = fopen(destinationFile, "w");

    if(destination == NULL)
    {
        printf("Unable to open destination file.");
        fclose(source);
        return 1;
    }

    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File contents copied successfully.");

    return 0;
}
