# Threaded File Encryption/Decryption
This project demonstrates a multi-threaded implementation of encryption and decryption algorithms for file input/output.
The program can handle files of any size by processing them in chunks of 1024 bits per thread, with the number of threads determined by the number of cores available on the system.

## Usage
To compile the program, run the command:

` make all `
This will generate an executable file named code.
------------------------------------ 
#### To encrypt a file, run the command:

`./code -e < input\_file > encrypted\_file `

where input\_file is the name of the file to be encrypted and encrypted\_file is the name of the output file where the encrypted data will be stored.

---------------------------------------------------

#### To decrypt a file, run the command:

`./code -d < encrypted\_file > decrypted\_file `

where encrypted\_file is the name of the file containing the encrypted data and decrypted\_file is the name of the output file where the decrypted data will be stored.

---------------------------------------------------

#### Cleaning up
To remove the executable and object files, run the command:

`make clean`

---------------------------------------------------

##### Additional Notes

The number of threads used by the program depends on the number of cores available on the system. This is determined using the `get_nprocs_conf()` function.
The program can handle files of any size by processing them in chunks of 1024 bits per thread. This allows the program to efficiently process large files without running out of memory.
The program generates a new RSA key pair each time it is run. To use a specific key pair, the code can be modified to read the keys from a file instead of generating new ones.
The program prints the time taken to encrypt and decrypt a file to the console.

---------------------------
#### If you still don't understand somthing about the wat the project work, i suggest to watch the video below:

https://github.com/Orcohen33/Advanced_Programming_Ex2/assets/87694635/4179d3ab-8ae3-409b-b9cf-ad213ec9ebc3

