#/bin/bash
echo "enter a file name:"
read a
if test -e /root/$a
then echo "the file is exist!"
else echo "the file is not exist!"
fi
