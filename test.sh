#!/bin/bash

# Function to clean up background processes on exit
cleanup() {
  echo "Stopping server..."
  kill $SERVER_PID
  exit
}

# Trap script exit to clean up server
trap cleanup EXIT

# Start the server in the background
./server &
SERVER_PID=$!
echo "Server started with PID: $SERVER_PID"
sleep 1 # Wait a moment to ensure the server starts

# Define an array of test strings
TEST_STRINGS=(
	"test string"
)

# Send each string to the server using the client
for STRING in "${TEST_STRINGS[@]}"; do
  for ((i=1; i<=20; i++)); do
    echo "Sending: $STRING (Iteration $i)"
    ./client $SERVER_PID "$STRING"
    sleep 1 # Wait briefly to ensure the server processes each message
    echo "--------------------------------"
  done
done

# Notify user the test is complete
echo "Testing complete. Check the server output for received messages."
