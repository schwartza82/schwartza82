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
- double quotes add /0 (nul) at the end of string. Extra byte for free!
- single quotes for char don't do that

Why is it sufficient for a variable to only store the 1st byte address and not all of the bytes
- Because of the design of strings, we always nul terminate them so it only sufficiences ot know the 1st byte's address

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
#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}
$ make addresses
$ ./addresses
H
I
!

-square bracket notation is syntactic sugar for this

//randomly touching random bytes of memory cuz we crazy
#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+50000));
}
$ make addresses
$ ./addresses
H
I
Segmentation fault (core dumped)
- here, your touching a segment of memory not allocated to you

//Harnessing Pointer Arithmetic with Strings

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
    printf("%s\n", s+1);
    printf("%s\n", s+2);
}

$ make addresses
$ ./addresses
HI!
I!
- string = a sequence of characters identified by their first byte
- printing out a character and then everything after that until the nul character

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (*s == *t)
    //* means "go there"
    //At an address 0x123 and 0x546 there is a character H
    //compares 1st character of both strings but not every other one
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

//pedantic usage of pointer arithmetic to get character

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (*s == *t && *(s+1) == *(t+1)) //can do that for every character if you really wanted to
    //* means "go there"
    //At an address 0x123 and 0x546 there is a character H
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

//2 "strings" (char *p pointer for char) separated by a certain number of bytes
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", t);
}
$ make comparestring
$ ./comparestring
s: HI!
t: HI!
0x59f2f35066b0
0x59f2f35066f0
- ending b0 vs f0 suggests seperation by certain number of bytes (the rest of the characters after H)

//Copying strings and memory allocation

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
$ code copy.c
$ make copy
$ ./copy
s: hi!
s: Hi!
t: Hi!

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");

    char* t = s;
    //value of address being copied as in s and t have the same memory address
    //t and s are NOT copies of the underlying characters

    if(strlen(t) > 0)
     //blindly assuming there's going to be at least one character in s so need if statement
    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}

    //using malloc and free to successfully copy a string
    malloc = memory allocation. Used to ask the operating system (Mac OS, Linux, etc) for some number of bytes of memory. returns 1st bite of memory if it's found free for you
        free = when you're done with some chunk of memory you can "free it" by passing in that same address and just hand it back to your operating system. Lets your operating system know you're free with a chunk of memory and that it can let you use said memory for something else later
        
    **if you use malloc to ask for more and more memory without ever free the memory, you'll run out of memory and you'll computer will likely freeze

#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");

    char* t = malloc(strlen(s) + 1);
    //asks malloc for how many bytes the user types in plus the nul character
    //t is now a pointer to a random chunk of free space

    for (int i = 0, n = strlen(s) + 1; i< n; i++)
        //included optimization of strlen(s) + 1 function so we don't have to keep calling it
        //here, n never changes so compares static value n to dynamic value i
    {
        t[i] = s[i];
        //copying from right to left for each character in s
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
$ make copy
$ ./copy
s: hi!
s: hi!
t: Hi!

//NULL vs nul 
nul = /0 a singer character
NULL = point (address) to 0. by convention, nothing should go there

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");
    if (s == NULL)
    //If too much memory is used get_string returns NULL
    {
        return 1;
    }

    char* t = malloc(strlen(s) + 1);
    if (t == NULL)
    //if user asks for too much memory
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    //If you allocate memory with maloc or certain other function, you have to free the memory when you're done with it
    //don't need to free memory from get_string b/c cs50 library automatically frees it for you

    return 0;
}



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
