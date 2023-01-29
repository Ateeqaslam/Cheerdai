#include <stdio.h>
#include <string.h>

// Prototype
void Read(char *arg, int byte);
void Write(char *arg, char *message);
void Del(char *arg, int byte);
void readall(char *arg);

// Globle
char *filename;
int main(int argc, char *argv[])
{
    // Execution Error handling
    if (argc != 3)
    {
        printf("Usage: ./Encode <operation> <filename[withextansion]>\n");
        printf("Operations:\n r Read\n w Write\n d Delete\n");
        return 1;
    }
    filename = argv[2];
    // Checking operations

    // reading
    if (argv[1][0] == 'r')
    {
        int numberOfByteToRead; // character long message to read
        printf("Bytes: ");      // Display
        scanf("%i", &numberOfByteToRead);
        Read(argv[2], numberOfByteToRead);
    }
    // writing
    if (argv[1][0] == 'w')
    {
        char messages[100];
        printf("Message: ");
        scanf("%[^\n]", &messages);

        Write(filename, messages);
        getchar(); // buffer cleaner
    }
    // Deleting
    if (argv[1][0] == 'd')
    {
        int numberOfByteToDelete; // character long message to delete
        printf("Bytes: ");        // Display
        scanf("%i", &numberOfByteToDelete);
        Del(argv[2], numberOfByteToDelete);
    }

    // Real All
    if (argv[1][0] == 'a')
    {
        readall(argv[2]);
    }
}

// Read the Messages in file
void Read(char *arg, int byte)
{
    char reader[byte + 2];

    FILE *file;
    file = fopen(arg, "rb+");

    fseek(file, -byte, SEEK_END);  // seek to the end and than get back
    fgets(reader, byte + 1, file); // read that many charcater

    printf("%s\n", reader);
    fclose(file);
}

// Write the Messages in file
void Write(char *arg, char *message)
{
    FILE *file;
    file = fopen(arg, "rb+");
    fseek(file, 0, SEEK_END);       // seek to the end
    fprintf(file, "\n%s", message); // write the message
    int bytes = strlen(message);
    printf("Bytes Written: %i\n", bytes);
    fclose(file);
}

// Delete the Message in file
void Del(char *arg, int byte)
{
    FILE *file;
    file = fopen(arg, "rb+");
    fseek(file, -byte, SEEK_END); // seek to the end and step back that many characters
    printf("Bytes Deleted: %i\n", byte);
    fclose(file);
}

// Debug Purpose
void readall(char *arg)
{
    FILE *file;
    char *buffer;
    file = fopen(arg, "rb");
    while (!feof(file))
    {
        fgets(buffer, 50, file);
        printf("%s\n", buffer);
    }
}