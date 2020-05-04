 #!/bin/bash
input=$(</dev/stdin)
echo $input >> "input.txt"
./render_as_dot "RandomBalanceStringSet" < "input.txt" > "output.dot"
cat "output.dot" | dot -Tsvg > "output.svg"
