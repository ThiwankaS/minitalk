# Minitalk

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/C-100%25-brightgreen.svg)

## Overview

Minitalk is a simple client-server communication program written in C that uses UNIX signals to transmit messages between processes. This project is part of the 42 curriculum and aims to deepen understanding of inter-process communication (IPC) using signals.

## Features

- Sends and receives messages using signals (`SIGUSR1` and `SIGUSR2`).
- Handles messages character by character.
- Implements error handling for signal transmission.
- Supports long messages by continuously transmitting data.

## Installation

Clone the repository:
```sh
 git clone https://github.com/ThiwankaS/minitalk.git
 cd minitalk
```

Compile the program:
```sh
 make
```
This will generate the `server` and `client` executables.

## Usage

### 1. Start the Server
Run the server first to get its Process ID (PID):
```sh
 ./server
```
The server will print its PID. Example output:
```sh
 Server PID: 12345
```

### 2. Send a Message from the Client
Use the PID from the server and run the client with a message:
```sh
 ./client 12345 "Hello, Minitalk!"
```
The message will be transmitted to the server and printed on the console.

## Files Structure
```
minitalk/
│── src/
│   ├── client.c
│   ├── server.c
│── include/
│   ├── minitalk.h
│── Makefile
│── README.md
```

## How It Works
- The server listens for signals (`SIGUSR1` and `SIGUSR2`) to receive characters bit by bit.
- The client encodes the message into a binary format and sends it using signals.
- The server reconstructs and prints the message.

## Requirements
- GCC Compiler
- Linux or macOS (due to signal handling)

## Contributing
Feel free to fork this repository and submit pull requests if you have improvements or bug fixes.

## License
This project is licensed under the MIT License.

## Author
[ThiwankaS](https://github.com/ThiwankaS)
