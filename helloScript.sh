#! /bin/bash

set -x

echo "Enter file name"
read fileName

set +x


: '
count=9
age=16
if (( $count < 9 ))
then 
       	echo "the condition is less than 9"
elif (( $count <=9 || $age == 15 ))
then 
	echo "age and count is ok"
else
	echo "the condition is greater than 9"
fi

number=1
while (( $number<=10  ))
do 
	echo "$number"
	number=$(( number+1  ))

done

for i in {0..100..2}
do 
	echo $i
done


for((i=0;i<=10;i++))
do 
	if (( $i==3 || $i==7 ))
	then 
		continue
	fi
	echo $i
done
//args for sh
echo $0 $1 $2 $3

#array of args

args=("$@")

#echo ${args[0]} ${args[1]} ${args[2]} ${args[3]}
#this will print everything that array contains
echo $@

#this will print the length of an array
echo $#

while read -p "enter your enput here: " line
do
	echo "$line"
done < "${1:-/dev/stdin}"

#input and o/p in same file
#ls +al >file1.txt 2>&1

#input and o/p in same file
#ls +al >file1.txt 2>&1
#ls +al >& file1.txt

message="hello linuxhint audience"

#exporting variable to another file
export message 
./secondScript.sh

#just use like other variable use it no prob

read -p "enter 1 string:" stl1
read -p "enter 2 string:" stl2

if [ $stl1 == $stl2 ]
then
	echo "both string match"
else 
	echo "string dont match"
fi

read -p "enter 1 string:" stl1
read -p "enter 2 string:" stl2

if [ "$stl1" \< "$stl2" ]
then
	echo "$stl1 is smaller than $stl2"
elif [ "$stl1" \> "$stl2" ]
then
	echo "$stl2 is smaller than $stl1"
else
	echo "string are equal in length"
fi

echo "${stl1^l}"

#to upper case
echo "${stl1^^}"

n1=20
n2=4

echo $(( n1+n2  ))
echo $(( n1-n2  ))
echo $(( n1*n2  ))
echo $(( n1/n2  ))
echo $(( n1%n2  ))

echo "Enter Hex Number of your choice:"
read Hex

echo -n "The Decimal value of $Hex is :"
echo "obase=10; ibase=16; $Hex" | bc

cars=("BMW" "TOYOTA" "HONDA")
echo "${cars[@]}"
echo "${cars[0]}"
echo "${cars[1]}"
echo "${cars[2]}"

echo "${!cars[@]}"
echo "${#cars[@]}"

unset cars[1]
cars[1]="Mercedese"
echo "${cars[@]}"

function funcheck(){
	returningvalue="using function right now"
	echo "$returningvalue"
}

funcheck

echo "Enter directory name to check:" 
read direct

if [ -d "$direct"  ]
then
	echo "$direct exists"
else 
	echo "$direct does not exists"
fi

echo "Enter the file name from  which you want to read."
read fileName

if [ -f "$fileName"  ]
then
	rm $fileName
	echo "$fileName has been deleted succesfully"
else 
	echo "$fileName does not exists"
fi

url="https://raw.githubusercontent.com/sarveshmaurya306/dethub/main/README.md"

#inherit everything even file name
curl ${url} -O  

#download file and put data in opfile
curl ${url} -o opfile
curl ${url} > opfile

#show the header of files (information of the file)
curl -I ${url}

select car in BMW MERCEDESE TESLA ROVER TOYOTA
do
	case $car in 
		BMW)
			echo "BMW SELECTED";;
		MERCEDESE)
			echo "MERCEDESE SELECTED";;
		TESLA)
			echo "TESLA SELECTED";;
		ROVER)
			echo "ROVER SELECTED";;
		TOYOTA)
			echo "TOYOTA SELECTED";;
		*)
			echo "ERROR! Please select between 1..5";;
		esac
done

echo "Press any key to continue"
while [ true ]
do
	#read single charater from stdin in every 3sec
	read -t 3 -n 1
	# $? gives the exit status of the last command executed 
	if [ $? = 0  ]
	then
		echo "You have terminated the script"
		exit;
	else
		echo "Waiting for you to press the key sir!!"
	fi
done

#wait for file system events with inotify
mkdir -p /home/sarvesh/Desktop/NewFolder
inotifywait -m /home/sarvesh/Desktop/NewFolder

echo "Enter filename to search text from "
read fileName

if [ -f $fileName  ]
then
	echo "Enter the text to search"
	read grepVar
	grep -i -n -c -v $grepVar $fileName
else
	echo "$fileName doenot exists"
fi

#awk
echo "Enter filename to print from awk "
read fileName

if [ -f $fileName  ]
then
	awk "/scriptName/ {print $1, $2}" $fileName
else
	echo "$fileName doenot exists"
fi

#sed
echo "Enter filename to substitute using sed "
read fileName

if [ -f $fileName  ]
then
	sed "s/i/I/g" $fileName
else
	echo "$fileName doenot exists"
fi
'
