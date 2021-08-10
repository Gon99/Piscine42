ifconfig | grep "ether " | sed -e 's/[[:blank:]]//g' -e 's/ether//g'
