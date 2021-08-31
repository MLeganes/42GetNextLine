
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
- After read() check result, -1 error in reading, number of bytes readed or 0 end of reading
- For every line, is needed \n\0, so basically add the \0 at the end.
- If the last pieze of line to return is empty, return NULL ?.

# Ref projects
https://github.com/lilangbr/42GNL