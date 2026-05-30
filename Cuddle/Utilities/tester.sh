#!/bin/bash

echo "name,age,city,salary,student" > data.csv

names=("Alice" "Bob" "Charlie" "David" "Emma" "Lucas" "Léo" "Nathan" "Alex" "Paul")
cities=("Paris" "London" "Berlin" "Madrid" "Rome" "Brussels")

for i in $(seq 1 1000)
do
    name=${names[$RANDOM % ${#names[@]}]}
    age=$((20 + RANDOM % 20))
    city=${cities[$RANDOM % ${#cities[@]}]}
    salary=$((25000 + RANDOM % 30000))

    if [ $((RANDOM % 2)) -eq 0 ]; then
        student="true"
    else
        student="false"
    fi

    echo "$name$i,$age,$city,$salary,$student" >> data.csv
done