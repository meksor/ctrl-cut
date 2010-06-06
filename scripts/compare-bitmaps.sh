#!/bin/sh

pixelerror=`compare -fuzz 10% -metric AE $1 $2 tmp.png 2>&1`
if [ $? -ne 0 ]
then
  exit 1 # Compare failed to read image
elif [ $pixelerror -gt 0 ]
then
  echo "Pixel error: $pixelerror"
  exit 1
fi
exit 0