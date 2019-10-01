# GameOfLife

Kaitlyn Abdo
CPSC 350 - 03
Professor Rene German
Chapman University

How to run: 

Shortcomings: The program has difficulties finding a file from a path if it is not in the same directory. 

The program: The game of life simulates the lifecycle of bacteria. The program prompts to enter either a map file or a random assignment. The map file must be in the format of :
ROW
COLUMN
INITIAL GRID

This allows for the program to accurately set up the initial colony. X represents cells and '-' represents empty spaces. If you decide for a random assignment, you will be prompted for rows, columns, and cell density. Then, you will be asked which mode you would like to complete the simulation. The options are classic, mirror and donut. After, you will be prompted for ouput styles. You can either output to a file (file name will be prompted for after), have a 1 second pause between generations or press enter between generations. The program will terminate once the simulation is stable or when the colony has died. 

Sources:
https://ubuntuforums.org/showthread.php?t=296142
https://stackoverflow.com/questions/8469900/cant-downcast-because-class-is-not-polymorphic/8470002
https://stackoverflow.com/questions/18410234/how-does-one-represent-the-empty-char
Udemy C++ Course
Brandon Fabre
