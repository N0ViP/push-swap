#!/bin/bash
#!/bin/bash
echo $2
count=$2
limit=$3
i=0
while [ $i -ne $count ]
do 
	./script.py $1
	numbers="$(cat random_numbers.txt)"
	./push_swap "$numbers" | ./checker_linux "$numbers"
	moves="$(./push_swap "$numbers" | wc -l)"
	echo $moves
	if [ $moves -gt $limit ]; then
		echo $numbers
		echo $moves
		break ;
	fi
done;
sleep 0.2

