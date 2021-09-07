
# 42GetNextLine
**Get Next Line** is similar to the function getline from the system

# Compiler
To use the  main.c in the project. Only for testing purpose, no needed for the project.
	
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=32 main.c get*.c

Execute the output file ./a.out

# Sources
- man getline
- man 2 read
- man 2 open  
- man leaks
- https://www.tutorialspoint.com/cprogramming/c_file_io.htmy

# Testers
Tester used to check the project.
- https://github.com/Tripouille/gnlTester
- https://github.com/Mazoise/42TESTERS-GNL

# Check memory leak
Use this line in the main, after the close() function.
	
	system ("leaks a.out");

# Notes
- After read() check result returned; -1 error in reading, >0 number of bytes read or 0 end of reading.
- For every time read() add in the buffer \0 at the end.
- BUFFER_SIZE=10000000 It gets "segmentation fault", it is used a "char buff[BUFFER_SIZE + 1]", to fix this problem,
  is needed to allocate memory with malloc and free it after.

# Ref projects
https://github.com/lilangbr/42GNL