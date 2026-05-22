# Welcome to My Mastermind
***

## Task
In this project, I am building a replica of the famous Mastermind game in C, running directly from the terminal. The goal of the game is to find a secret code composed of 4 distinct digits between '0' and '8'. 

The implementation focuses on core system programming concepts including:
Standard stream interactions and input parsing using system calls.
Handling conditional flags passed via command line arguments (`-c` and `-t`).
Generating unique randomized configurations when custom setups are absent.
Preventing memory safety issues and avoiding standard functions banned by project guidelines.

## Description
To solve this project, I structured the software architecture by breaking the program down into separate modular files (`main.c`, `my_mastermind.c`, and `my_mastermind.h`) to handle specialized tasks without breaching compilation limits.

The core gameplay loop functions as follows:
1.Argument Parsing:** The program checks `argc` and `argv` for custom secret codes (`-c`) or custom max round attempts (`-t`). If no code is explicitly given, it employs a randomizing sequence using `srand()` and `rand()` to produce a 4-digit code without repeating digits.
2.Low-Level Input Reading:** Instead of using unsafe high-level inputs, I utilized the `read(0, &c, 1)` system call to grab user guesses character-by-character into a managed buffer array until a newline (`\n`) or End-Of-File (Ctrl+D) is detected.
3.Validation & Evaluation:** A specialized nested verification method ensures the input consists of exactly 4 unique numerical entries between 0 and 8. If validated, the secret code is evaluated against the guess, returning exact indices matches (Well placed) and correct character misalignments (Misplaced).

## Installation
No specialized third-party dependencies are required to run this game. You only need a standard UNIX environment with a gcc compiler and make utility installed. To compile the codebase and generate the my_mastermind executable with strict compilation warnings, simply type the command "make" in your terminal and press enter.

## Usage
Once compiled, you can run the executable directly from your console in various modes depending on your preference.

To play in Default Mode, which generates a random 4-digit code and grants you 10 attempts, type "./my_mastermind" in the terminal. If you want to use a specific code, you can initiate the Custom Secret Code Mode by typing "./my_mastermind -c" followed by your desired 4-digit code in quotation marks, such as "0123". To change the maximum number of rounds, use the Custom Attempt Limit Mode by typing "./my_mastermind -t" followed by the number of attempts, for example "5". You can also combine these parameters into a single command, such as "./my_mastermind -c 4312 -t 7".

During execution, type your 4-digit guess and hit Enter. If you wish to exit the game cleanly at any point, press Ctrl + D (EOF) on an empty prompt line. To safely delete intermediate object binary structures and reset your directory state, you can run the command "make fclean" in your terminal.
```
./my_project argument1 argument2
```

### The Core Team

abdullaz_a
<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
