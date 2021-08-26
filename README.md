
# 42GetNextLine
Similar to the function getline from the system #man getline.
Prototype funcion looks like:

	char *get_next_line(int fd)

## Compiler
To use the  main.c in the project.
	
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=32 main.c get*.c

# Check memory leak
Use this line in the main, after the close() function.
	
	system ("leaks a.out");


# Information Sources
- man getline
- man 2 read
- man 2 open  
- man leaks
- https://www.tutorialspoint.com/cprogramming/c_file_io.htmy

# Testers
Tester used to check the project.
- https://github.com/Tripouille/gnlTester
- https://github.com/Mazoise/42TESTERS-GNL

# Notes to develope 
- After read() check result, -1 error in reading, number of bytes readed or 0 end of reading
- For every line, is needed \n\0, so basically add the \0 at the end.
- If the last pieze of line to return is empty, return NULL ?.
- 