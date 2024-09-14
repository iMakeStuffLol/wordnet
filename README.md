# wordnet
A simple C++ program to generate word networks
## usage
First, compile the program using g++ (or your prefered C++ compiler)

g++ main.c -o youroutputfile

Then run the program

./youroutputfile input.txt -o output.gexf -l 3

You can use Gephi to view the file
## parameters
-o outputfile - required

-l lowerbound - optional, 3 by default, functions as length if -u is not set

-u upperbound - optional, is the value of -l by default

-d difference - optional, is 1 by default

EXAMPLE: ./youroutputfile input.txt -o output.gexf -l 2 -u 5 -d 2

This example would get words from a length of 2 to 5 and join them if they differ by 2 or less characters

## limitations
1. The difference is calculated from start to end. This means the difference between "an" and "tan" would be 3 but the difference between "an" and "and" would be 1
2. The program is not efficient once the list starts getting too long.
