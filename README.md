# ks-Harkkaty-t

This is our course practice project that includes mall projects. The first one is simple program that reads the given text file in from down to up. The second project has four small simple programs wich are different UNIX utilities such as cat, grep, zip and unzip. And the third one is very surface level shell program named wish. We wrote a documentation about the project progcess and learning skills.

Documentation:https://lut-my.sharepoint.com/:w:/g/personal/viia_mantymaki_student_lut_fi/EdWDdJmp_4xGncaIHD9MDz8BUPFXFt2reJ5VESiZycGsbg?e=raaoup

## *************** Project One ***********************

### Files:

reverse.c

input.txt

### How to run:

reverse.c

Compile: gcc -o reverse reverse.c
Then run: prompt> ./reverse

## *************** Project Two ***********************

### Files:

my-cat.c

my-grep.c

my-zip.c

my-unzip.c


### How to run:

my-cat.c

Compile: gcc -O2 -Wall -Werror -o my-cat my-cat.c Then run: prompt> ./my-cat filename


my-grep.c

Compile: gcc -O2 -Wall -Werror -o my-grep my-grep.c Then run: prompt> ./my-grep searchterm filename


my-zip.c

Compile: gcc -O2 -Wall -Werror -o my-zip my-zip.c
Then run: ./my-zip filename.txt > filename.z

my-unzip.c

Compile: gcc -O2 -Wall -Werror -o my-unzip my-unzip.c
Then run: ./my-unzip filename.z

## *************** Project Three ***********************

### Files:

wish.c

### How to run:

Compile: gcc -o wish wish.c
Then run: prompt> ./wish.c or prompt> ./wish.c textfilename.txt
