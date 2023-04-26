# High Level Programming Languages 1 — Lab 11 Overview

## Input and Output

**Input** &mdash; it means to feed some data into a program.
**Output** &mdash; it means to display some data on screen, printer, or in any file.

### The Standard Files

C programming treats all the devices as files. So devices such as the display are addressed in the same way as files and the following three files are automatically opened when a program executes to provide access to the keyboard and screen.

|Standard File| File Pointer | Device|
|-------------|--------------|-------|
|Standard input|	stdin	|Keyboard|
|Standard output|	stdout	|Screen|
|Standard error|	stderr	|Your screen|

The file pointers are the means to access the file for reading and writing purpose. This section explains how to read values from the screen and how to print the result on the screen.

**Example functions:** `getchar()`, `putchar()`, `gets()`, `puts()`, `fgets()`, `scanf()` and `printf()`

## File I/O

A file represents a sequence of bytes, regardless of it being a text file or a binary file.

### Opening Files

```C
FILE *fopen( const char * filename, const char * mode );
```

#### Parameters

- `filename` &mdash; a string literal
- `mode`

#### `mode` types

|Mode|Description|
|----|-----------|
|`r` |Opens an existing text file for reading purpose.|
|`w` | Opens a text file for writing. If it does not exist, then a new file is created.|
|`a` | Opens a text file for writing in appending mode. If it does not exist, then a new file is created. Notice appending means adding|


### Closing a File

```C
int fclose( FILE *fp );
```

The `fclose()` function returns zero on success, or `EOF` if there is an error in closing the file. This function actually flushes any data still pending in the buffer to the file, closes the file, and releases any memory used for the file.

### Reading a File

```C
char *fgets( char *buf, int n, FILE *fp );
```

The functions `fgets()` reads up to `n-1` characters from the input stream referenced by `fp`. It copies the read string into the buffer `buf`, appending a `null` character to terminate the string.

If this function encounters a newline character `\n` or the end of the file `EOF` before they have read the maximum number of characters, then it returns only the characters read up to that point including the new line character.

### Writing to a File

```C
int fprintf(FILE *stream, const char *format [, argument, ...])  
```

This function is similar to `printf()` we normally use, however you have to specify a `FILE *stream`, which is a file pointer. Refer to [parameters](#parameters). Read more [here](https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm).

**IMPORTANT Notice:** *File handling* is very much different from *redirection* that we used to do before. Refer to this [tutorial](https://linuxhint.com/redirect-stdout-and-stderr-to-file/) for more info.

-----

## Example

Let's consider the [Airports](https://github.com/INBPA0212L-2023/exercises/blob/main/week-10/P110101.md) exercise again. This time we have a file to read from rather than the standard input.

This time we will specify the files we read from and write to as [command-line](../Week%2008/README.md) arguments.

```C
int main(int argc, char *argv[]) {}
```

Let's do some error handling to check if the user specified an input file `argv[1]` and then read the file itself. Notice that we do this error handling to avoid `null`s.

Here is our new main function

```C
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "No input file provided.\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin)
    {
        fprintf(stderr, "Input file does not exit.\n");
        return 2;
    }
    
    return EXIT_SUCCESS;
}
```

Notice that whenever we have a peculiar error-prone behavior, we output it as `stderr`.

Next we have to read that data and store them in an array, in this case we read until `EOF` and close the `fin`.

```C
    char line[101];
    AIRPORT airports[20];
    int counter = 0;

    while(fgets(line, sizeof(line), fin))
    {
        strcpy(airports[counter].name, strtok(line, ";"));
        strcpy(airports[counter].city, strtok(NULL, ";"));
        airports[counter].runways = atoi(strtok(NULL, ";"));
        airports[counter].time = atoi(strtok(NULL, ";"));
        counter++;
    }
    fclose(fin);
```

The logic for writing to a file is very much similar, we just change the mode to `"w"` instead.

```C
    if (argc < 3)
    {
        fprintf(stderr, "No output file provided.\n");
        return 3;
    }
    
    FILE *fout = fopen(argv[2], "w");
    if (!fout)
    {
        fprintf(stderr, "Output file cannot be opened.\n");
        return 4;
    }
```

Now we iterate over the array and use `fprintf()` to write the lines to the output file and close it as usual.

```C
    for (int i = 0; i < counter; i++)
    {
        fprintf(fout, "%s (%s): %d\n", airports[i].name,
            airports[i].city, airports[i].time);
    }
    fclose(fout);
```

Complete code is available [here](./airportfile.c).

