
# 42GetNextLine
Similar to the function getline from the system #man getline.
Prototype funcion looks like:

	char *get_next_line(int fd)

## Compiler
To use the  main.c in the project.
	
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=32 main.c get*.c

# Check memory leak
Use this line in the main, after the close function.
	
	system ("leaks a.out");


# Information Sources
- man getline
- man leaks
- man 2 open  
- https://www.tutorialspoint.com/cprogramming/c_file_io.htmy

# Testers
Tester used to check the project.
- https://github.com/Tripouille/gnlTester
- https://github.com/Mazoise/42TESTERS-GNL