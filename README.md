# Encode Program

## Overview
The **Encode** program is a command-line utility that allows users to perform file operations such as:
- Reading the last *n* bytes of a file.
- Writing/appending new content to a file.
- Deleting the last *n* bytes from a file.
- Displaying the entire content of a file (debugging purpose).

---

## Features
- **Read (`r`)**: Reads a specified number of bytes from the end of the file.
- **Write (`w`)**: Appends a new message to the end of the file.
- **Delete (`d`)**: Deletes a specified number of bytes from the end of the file.
- **Read All (`a`)**: Outputs the entire content of the file.

---

## Requirements
- A C compiler like GCC to compile the code.
- The program works with any valid Image/audio/video file.

---

## Compilation

Compile the program using a terminal/command prompt with the following command:

```bash
gcc -o Encode Encode.c
```

---

## Usage

Run the program with the following command syntax:

```bash
./Encode <operation> <filename>
```

### Operations
| Operations   | Description   | 
|------------|------------|
| r | Reads the last n bytes of the file. |
| w | Appends a message to the end of the file. |
| d | Deletes the last n bytes from the file. |
| a | Displays the entire contents of the file. |

**Example**
#### 1. Read the Last n Bytes
  ```bash
./Encode r myfile.[extention]
  ```
  The program will prompt for the number of bytes to read.
  
  **Example Iteration:**
  ```markfile
Bytes: 10
HelloWorld
  ```
#### 2. Write a Message
  ```bash
./Encode w myfile.[extension]
  ```
  The program will prompt for the message to append.
  
  **Example Iteration:**
  ```markfile
Message: Welcome to Encode!
Bytes Written: 18
  ```
#### 3. Delete the Last n Bytes
  ```bash
./Encode d myfile.[extension]
  ```
  The program will prompt for the number of bytes to delete.
  
  **Example Iteration:**
  ```markfile
Bytes: 5
Bytes Deleted: 5
  ```
#### 4. Read All (Debug Mode)
  ```bash
./Encode a myfile.txt
  ```
  Displays the entire content of the file.
  
  **Example Iteration:**
  ```markfile
HelloWorld
Welcome to Encode!
  ```

    

