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
	"Lorem ipsum odor amet, consectetuer adipiscing elit. Lacus vel consectetur magna feugiat congue ultricies. Nec dapibus dictum luctus litora ultrices. Quam elit erat dis maximus nostra euismod ante arcu. Ultricies potenti accumsan ac vivamus mollis potenti! Venenatis accumsan eget varius sapien nunc pellentesque. Vehicula lacus parturient velit felis quam vestibulum.
Suspendisse amet mi eget conubia fringilla posuere ad hac. Posuere non nibh sagittis ac lectus semper fames. Lacus ullamcorper parturient, non curae eget molestie vel. Ornare conubia sapien duis nibh montes? Ad non aliquam suspendisse himenaeos primis tempus mus. Nisi suscipit cursus viverra porttitor venenatis porttitor vitae vestibulum. Nibh dolor ad scelerisque suspendisse
potenti arcu taciti? Quam phasellus ornare leo ornare parturient tristique facilisi praesent dignissim. Fames etiam nostra sollicitudin mattis elementum nam."
)

# Send each string to the server using the client
for STRING in "${TEST_STRINGS[@]}"; do
  for ((i=1; i<=10; i++)); do
    echo "Sending: $STRING (Iteration $i)"
    ./client $SERVER_PID "$STRING"
    sleep 1 # Wait briefly to ensure the server processes each message
    echo "--------------------------------"
  done
done

# Notify user the test is complete
echo "Testing complete. Check the server output for received messages."
