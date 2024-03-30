#!/bin/bash

path=$(dirname $0)
program_name=bob_is_a_lazy_man

cd $path && cd ..

make first > /dev/null

ok="\033[0;32mOK\033[0m\n"
ko="\033[0;31mKO\033[0m\n"

result=$(./$program_name hello)
expected="\"hello\" -> 5"
counter=0

((counter++))
if [[ "$result" == "$expected" ]]; then
	printf "$counter: "$ok
else
	printf "$counter: "$ko
	printf "Output:\n$output\n"
	printf "Expected:\n$expected\n"
fi

result=$(./$program_name Hello world)
expected="\"Hello\" -> 5
\"world\" -> 5"

((counter++))
if [[ "$result" == "$expected" ]]; then
	printf "$counter: "$ok
else
	printf "$counter: "$ko
	printf "Output:\n$output\n"
	printf "Expected:\n$expected\n"
fi

result=$(./$program_name "")
expected="\"\" -> 0"

((counter++))
if [[ "$result" == "$expected" ]]; then
	printf "$counter: "$ok
else
	printf "$counter: "$ko
	printf "Output:\n$output\n"
	printf "Expected:\n$expected\n"
fi

result=$(./$program_name "Int3r!sting")
expected="\"Int3r!sting\" -> 10"

((counter++))
if [[ "$result" == "$expected" ]]; then
	printf "$counter: "$ok
else
	printf "$counter: "$ko
	printf "Output:\n$output\n"
	printf "Expected:\n$expected\n"
fi

result=$(./$program_name "@|@~|@~#@##|@#")
expected="\"@|@~|@~#@##|@#\" -> 0"

((counter++))
if [[ "$result" == "$expected" ]]; then
	printf "$counter: "$ok
else
	printf "$counter: "$ko
	printf "Output:\n$output\n"
	printf "Expected:\n$expected\n"
fi
