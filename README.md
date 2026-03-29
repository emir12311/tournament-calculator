# Tournament Calcutator
Hello everyone! This is my first upload in a little while, and it's special because it's my first C code I've written. 
After finishing high school, I want to go to 42 Kocaeli which made me want to learn C to help me with my work in the future.
This project was to just help me learn the basics of C, like file input/output, pointers, memory management and etc.

While doing research about 42, I learned that they use a thing called Norminette, which checks your code style, so I wanted to make something that was compliant with that.
I will include my code before and after I did the Norminette formatting so you, me and everyone else viewing this can see how much my code changed. 

## How to run it
First, compile it using GCC:
```bash
gcc -Wall -Wextra -Werror after_norm_formatting.c -o tournament_calculator
# and if you want to compile the before formatting one:
gcc -Wall -Wextra -Werror before_norm_formatting.c -o tournament_calculator
```
Then you can just run it via:
```bash
# Linux/Macos
./tournament_calculator
# Windows
.\tournament_calculator
```
*Note: After running, your results will be saved to scores.txt in the same directory.*
