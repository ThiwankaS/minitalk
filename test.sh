#!/bin/bash

# Check if server PID is provided as a command line argument
if [ -z "$1" ]; then
  echo "Use: $0 <server_pid>"
  exit 1
fi

SERVER_PID="$1"
echo "Seding message to the server PID: $SERVER_PID"
#Test 01
echo "TEST 01: Sending simple string"
echo "------------------------------------------------------------------"
TEST_STRING="Hello, How are you doing?"
echo "String Length: ${#TEST_STRING}"
./client "$SERVER_PID" "$TEST_STRING"
sleep 1
echo "------------------------------------------------------------------"
#Test 02
UNICODE_STRING="你好, 世界! 🌍🚀💡" # Chinese, emojis, etc.
echo "TEST 02: Sending Unicode string"
echo "String Length: ${#UNICODE_STRING}"
./client "$SERVER_PID" "$UNICODE_STRING"
sleep 1
echo "------------------------------------------------------------------"
#Test 03
STRING_100="Success is not final, failure is not fatal: it is the courage to continue that counts in every step of life."
echo "TEST 03: Sending string with exactly 100 characters"
echo "String Length: ${#STRING_100}"
./client "$SERVER_PID" "$STRING_100"
sleep 1
echo "------------------------------------------------------------------"
#Test 04
echo "TEST 04: Sending a string multiple times"
TEST_STRINGS=(
  "Change is courage, always embrace the it,adapt and get evlove!"
)

for STRING in "${TEST_STRINGS[@]}"; do
  for ((i=1; i<=10; i++)); do
    echo "Sending: (Iteration $i)"
    echo "String Length: ${#STRING}"
    ./client "$SERVER_PID" "$STRING"
    sleep 1
    echo "------------------------------------------------------------------"
  done
done
#Test 05
echo "TEST 05: Sending a bigger string multiple times"
TEST_STRINGS=(
  "Life is a journey filled with challenges, lessons, and moments of joy.
  Every failure teaches resilience, and every success builds confidence.
  The key is to stay persistent, embrace change, and keep moving forward.
  Growth comes from pushing beyond comfort zones and believing in oneself.
  True happiness lies not in perfection, but in the ability to learn, adapt, and
  appreciate each step along the way."
)

for STRING in "${TEST_STRINGS[@]}"; do
  for ((i=1; i<=3; i++)); do
    echo "Sending: (Iteration $i)"
    echo "String Length: ${#STRING}"
    ./client "$SERVER_PID" "$STRING"
    sleep 1
    echo "------------------------------------------------------------------"
  done
done
#Test 06
LARGE_STRING="Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum.
Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum.
Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum.
Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum.
Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum.
Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum.
Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum."
echo "TEST 03: Sending large string (> 3000 characters)"
echo "String Length: ${#LARGE_STRING}"
./client "$SERVER_PID" "$LARGE_STRING"
sleep 1
echo "------------------------------------------------------------------"
# Notify user the test is complete
echo "Testing complete. Check the server output for received messages."
