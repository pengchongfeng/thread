#/!bin/bash
count=1
while [$count -le 6];do
    ./a.out
    sleep 2
    if [-d "./core"];then
	break
    fi
done
