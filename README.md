# Multithreaded Encryption/Decryption Tool

In this project, I have implemented a multithreaded command-line tool that can encrypt and decrypt data using a shared library containing the `encrypt` and `decrypt` functions. I have used a thread pool to parallelize the encryption and decryption process and improve performance on multi-core systems. This is especially useful when dealing with large amounts of data.

## Implementation Details

I have created a `ThreadPool` structure to manage a fixed number of worker threads. The thread pool is initialized with the desired number of threads, and each thread is responsible for reading data from stdin, processing it (encrypting or decrypting) using the functions from the shared library, and writing the output to stdout. I have used mutexes to synchronize the access to shared resources, avoiding conflicts when multiple threads read from stdin and write to stdout.

The code is organized into the following files:

- `threadpool.h`: Header file containing the `ThreadPool` structure definition and function declarations.
- `threadpool.c`: Implementation of the thread pool functions.
- `stdIn_main.c`: Main file containing the `main()` function and the worker thread function that uses the shared library's encryption and decryption functions.

## Building the Project

To build the project, I have updated the Makefile to include the new `coder` executable, which is built from the `threadpool.c` and `stdIn_main.c` files, and linked against the shared library and the pthread library.

To build the executables, simply run:

```sh
make
```

This will build the encoder, tester, and coder executables.


## Running the Tool

To encrypt a file, run:

```sh
cat input_file | ./coder key -e > encrypted_file
```
To decrypt an encrypted file, run:

```sh
cat encrypted_file | ./coder key -d > decrypted_file
```


Replace `input_file` with the name of the file you want to encrypt, `key` with an integer encryption key, `encrypted_file` with the desired name for the encrypted output, and `decrypted_file` with the desired name for the decrypted output.



## Performance Improvement

By parallelizing the encryption and decryption process using a thread pool, I have made better use of the available CPU cores in the system. This results in faster processing times for large amounts of data when compared to a single-threaded implementation. The performance improvement depends on the number of cores in the system and the efficiency of the encryption and decryption functions provided by the shared library.

## Testing the Project

To test the project, follow these steps:

1. Create a sample text file named `sample.txt` with some content.

2. Encrypt the `sample.txt` file using the `coder` tool:

```sh
cat sample.txt | ./coder 2 -e > encrypted_file
```
3. Decrypt the `encrypted_file` using the `coder` tool:
```sh
cat encrypted_file | ./coder 2 -d > decrypted_file
```
4. Compare the contents of `sample.txt` and `decrypted_file` to make sure they are the same:
```sh
diff sample.txt decrypted_file
```

If there is no output from this command, it means the contents of `sample.txt` and `decrypted_file` are the same, and the encryption and decryption process has worked correctly.

## Conclusion

This multithreaded encryption and decryption tool provides an efficient way to process large amounts of data by utilizing multiple CPU cores. The implementation using a thread pool ensures that the available system resources are used effectively, improving the overall performance of the encryption and decryption tasks.

By implementing this tool, I have demonstrated the power of multithreading in optimizing CPU usage and improving performance for tasks that can be parallelized, such as encryption and decryption. This concept can be applied to various other use cases, such as web servers handling multiple client requests simultaneously, to further enhance their performance and efficiency.

Going forward, there are opportunities to optimize the thread pool implementation, such as dynamically adjusting the number of worker threads based on the system load, or improving the efficiency of the encryption and decryption algorithms provided by the shared library. These enhancements can lead to even better performance and more efficient resource utilization in the future.
