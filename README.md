# Enigma2 (and EnigmaMachine2)
A small foray into a simple encryption algorithm that can be used on its own- or serve as the basis for a more complex communication channel utilizing an S-P Block cipher to encrypt plaintext.


## Usage
This script can be run from the command line; was created using C
Tested through a Linux Bash Shell (Ubuntu) on a Windows 10 system, Compiled using the GNU Compiler Collection (GCC)

- Compile using the syntax "gcc Enigma<Machine>2.c" [optionally using the "-o" flag to rename the resulting a.out file]
- Run the compiled Enigma2.c file to encrypt the text
- Run the compiled EnigmaMachine2.c to decrypt the text
  - NOTE: The input text for EngimaMachine2 must be formatted exactly as the output is given from Enigma2
