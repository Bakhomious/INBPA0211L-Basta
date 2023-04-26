# Sample Final Test

## Defining type

Define the type `AIRPORT` based on a structure having the following fields:

- `name`: name of the airport (a string having at most 30 characters, type: `char[]`)
- `city`: name of the city (a string having at most 30 characters, type: `char[]`)
- `runways`: number of runways (a positive integer, type: `int`)
- `time`: transfer time (a positive integer, type: `int`)

## Reading File

Open and read the CSV file which name is passed as the first command-line argument! Each line represents a single `AIRPORT` element in the following format:

`<name>;<city>;<runways>;<time>`

Notes:

1. Solve the exercise in function `main()`.
2. The end of the file is denoted by `EOF`.
3. It is guaranteed that the file contains at least `1` and at most `20` lines; allocate a suitable array.
4. Each line contains at most `100` characters.
5. The file uses semicolons `;` as the delimiter.
6. Print an error message and exit with status code `1` if the command-line argument is not present.
7. Print an error message and exit with status code `2` if the file does not exist.

------

## Sorting elements

Sort the array using built-in function `qsort()`, and the following stages:

1. number of runways (descending)
2. transfer time (descending)
3. name (ascending)

Notes:

1. Invoke function `qsort()` in function `main()`.

## Writing file

Open and write the CSV file, which name is passed as the second command-line argument and write the sorted sequence of records to the file!

Notes:

1. Solve the exercise in function `main()`.
2. The file should have the same format as the input file.
3. Print an error message and exit with status code `3` if the command-line argument is not present.
4. Print an error message and exit with status code `4` if the file cannot be opened.

## Querying the array

Define function query, which gets the memory address of an `AIRPORT` array and its length, then returns the greatest number of runways!

### Formal parameter list

1. `airports`: the memory address of the array (type: `AIRPORT *` )
2. `length`: the length of the array (type: `int`)

### Returned value

the greatest number of runways (type: `int`)

### Calling the function

1. Call the function in function `main()`, passing the memory address of the array and its length.
2. Print the returned value to the standard output.

## Sample execution

Command-line arguments: `input.csv output.csv`
Standard output: `3`

Contents of file `input.csv`:

```text
Zurich Kloten;Zurich;3;360
London Heathrow;London;2;240
Istanbul Ataturk;Istambul;3;120
Barcelona El Prat;Barcelona;3;150
```

Content of file `output.csv`:

```text
Zurich Kloten;Zurich;3;360
Barcelona El Prat;Barcelona;3;150
Istanbul Ataturk;Istambul;3;120
London Heathrow;London;2;240
```

