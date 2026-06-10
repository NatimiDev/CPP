#!/bin/bash

numbers=()

for ((i=0; i < 3000; i++)); do
    numbers+=("$RANDOM")
done

./Pmergeme "${numbers[@]}"