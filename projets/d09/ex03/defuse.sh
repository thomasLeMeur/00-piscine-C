echo "$(stat -t %s bomb.txt | cut -d ' ' -f 9 | cut -c2- | rev | cut -c2- | rev) - 1" | bc
