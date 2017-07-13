result=$(ifconfig | grep -oE "inet ([0-9]{1,3}.){3}[0-9]{1,3}" | cut -d ' ' -f 2)
if [ -z result  ]
then
	echo "Je suis perdu!"
else
	echo "$result"
fi
