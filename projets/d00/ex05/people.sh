ldapsearch -LLL uid=z\* cn | grep "^cn:" | sed "s/cn: //g" | sort -rf
