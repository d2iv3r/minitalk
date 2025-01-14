# Minitalk

## Overview
**Minitalk** is a project that involves building a simple communication program between a client and a server using UNIX signals. The server can handle multiple clients simultaneously, and the client sends a string message to the server, which the server then prints.

This project enhances your understanding of signals, inter-process communication (IPC), and the fundamentals of system calls in UNIX.

---

## Features
- Communication between a client and a server using **SIGUSR1** and **SIGUSR2** signals.
- Ability to send a string message from the client to the server.
- Server handles multiple clients and prints the received messages in real time.
- Handles edge cases such as empty messages or invalid PIDs.

---

## Installation
1. Clone the repository:
   ```bash
   git clone git@github.com:d2iv3r/minitalk.git
   cd minitalk

2. Build the project:
   ```bash
   make
   ```
This will create two executables:
   - server
   - client

## Usage

**Starting the Server**

Run the `server` program to start the server. It will display its Process ID (PID):
   ```bash
   ./server
   ```
**Output:**
   ```bash
   Server PID: 12345
   ```
Sending a Message from the Client
To send a message, run the client program with the server's PID and the message:
   ```bash
   ./client 12345 "Hello, Minitalk!"
   ```
The server will receive and display the message:
   ```bash
   Received message: Hello, Minitalk!
   ```

## Communication Protocol

Minitalk uses `SIGUSR1` and `SIGUSR2` signals to encode and transmit characters. Each character is sent bit by bit:

- SIGUSR1 represents a 0.
- SIGUSR2 represents a 1.

The server assembles the bits into characters and reconstructs the original string.