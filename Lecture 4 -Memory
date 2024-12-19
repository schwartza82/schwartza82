//Bit maps
-Coordinate system of top down
-cs50.ly/art 
- RGB system = color system where you can rep any color of the rainbow using red, green, and blue

//hexadecimal system aka base-16
- 0-9 digits and 6 letters of the English alphabet (case insensitive) A B C D E F
- columns are powers of 16

16 1
1  0
- this is 16 in hexadecimal 

FF in hexadecimal = 16 x 15 + 1 x 15 -> 255

-4 bits in binary 1111 = 15
-1111 in binary = FF in hexadecimal (4 bits underneath the hood)

- hexadeciaml often used to describe the locations of the addresses in memory

int n = 50;
- number 50 ends up in computers memory and assigned a name n in a symbol n 

//Pointers introduction
& = ampersand operator allows us to get the address of a piece of data in memory (put before the name of a variable to get address)
* = d-reference operator lets you go to a specific address in memory

//&n for address of n in memory 

#include <stdio.h>
int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}

$ make addresses
$ ./addresses
0x7ffccfdccb5c

-pointers not a feature you can harness in higher-level languages like Python and Java
- C is close enough to the computer's hardware you can get before things get really low level and scary (like assembly language) 

Pointers = variable that contains an address of some variable (think of it like an address)

#include <stdio.h>
int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    //p is the address of an integer
    //%p = pointer
}

$ make addresses
$ ./addresses
0x7fffea4119fc

**pointers very good for data structures in memory**
- helps us create the equivalent of 2-D and 3-D data structures by linking things together

-pointers take up 8 bytes (1 bit) while integers by convention take up 4 bytes

**can be helpful to think of a pointer as a variable that points to something else**
- double pointers ** exist (dear lord) but we won't cover that yet

//Introduction to Data Types and Strings in C

string s = "Hi!" 
- double quotes add /0 (null) at the end of string. Extra byte for free!
- single quotes for char don't do that

Why is it sufficient for a variable to only store the 1st byte address and not all of the bytes
- Because of the design of strings, we always null terminate them so it only sufficiences ot know the 1st byte's address

//There is no such thing as a "string" keyword in C
**strings are actually a pointer to a character c**

string s = "HI!"; is actually
char *s = "HI!";

typedef struct
{
  string name;
  string number;
}
person;
- defined a person to be this structure

typedef int integer;
- if you want to create the keyword integer as a datatype, you can typedef it to int
- int becomes a synoynm for integer

typedef char *string;
- this is what's in cs50 library
- associates "string" with char * 
- python has string called stir


#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int n = 50;
    int *p = &n; // on the left side type of variable you want to point at, then a star and then the name of the variable
    printf("%i\n", *p);
    //*p = dereference p ("open the mailbox and print whatever is in the mailbox)
}

//Declaring a pointer requires you to declare the datatype
//When you use a pointer, you just use a star

$ make addresses
$ ./addresses
50

//address of a character vs the character itself

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
}

$ make addresses
$ ./addresses
0x603ce9084004


#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
}
$ make addresses
$ ./addresses
HI!
- %s prints stuff in a sequence until it gets /0

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
}
$ make addresses
$ ./addresses
H
-%c just has you printing out the literal first character

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
}
$ make addresses
$ ./addresses
0x63220dc41004
0x63220dc41004

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", s);
    printf("%c\n", &s[0]);
    printf("%c\n", &s[1]);
}
$ make addresses
$ ./addresses
0x55c88c224004
0x55c88c224004
0x55c88c224005
0x55c88c224006
0x55c88c224007
-continous 1 byte away from each other

//Pointer arithmetic




09:10:19  Understanding Hexadecimal Representation
09:19:54  Getting the Address of a Variable
09:44:01  Introduction to Data Types and Strings in C
10:03:55  Harnessing Pointer Arithmetic with Strings
10:17:37  Exploring string manipulation
10:19:27  Copying strings and memory allocation
10:47:25  Handling Garbage Values
11:09:12  Swapping values using pointers in C,
11:13:00  Memory limitations and potential issues in C,
11:27:18  Importance of Data Structures
