echo "Running tests..."
echo

output=$(./process_creation.exe)
expected_output="PCB Index 0: Status: allocated; Parent PCB Index -2; Children Index(es): 1 2 3 4
PCB Index 3: Status: allocated; Parent PCB Index 0; Children Index(es): 5 6
PCB Index 5: Status: allocated; Parent PCB Index 3; Children Index(es): 7 8 9
PCB Index 3: Status: allocated; Parent PCB Index 0; Children Index(es):
PCB Index 5: Status: free."

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass: Output is correct"
else
  echo "Expected '$expected_output' but got: $output"
  exit 1
fi

echo
echo "All tests passed."

exit 0