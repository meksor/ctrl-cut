#!/bin/bash

cd $EC_BASE

. $EC_FUNCTIONS

[ ! -d "./tmp" ] && mkdir "./tmp"

export RASTER_OFF="y"
filter=./epilogcups
[ $# != 1 ] && error "Usage: $0 ps-file" 1
file=$1

try "locating cups-config..." "type cups-config" 

export CHARSET=utf-8
export CONTENT_TYPE=application/pdf
#export CUPS_CACHEDIR=/private/var/spool/cups/cache
export CUPS_DATADIR=`cups-config --datadir`
export CUPS_FILETYPE=document
export CUPS_SERVERROOT=`cups-config --serverroot`
export DEVICE_URI=file:/tmp/passthrough.ps
export FINAL_CONTENT_TYPE=printer/passthrough
export LANG=en_US.UTF-8
#export PATH=/usr/libexec/cups/filter:/usr/bin:/usr/sbin:/bin:/usr/bin
export PPD="$CUPS_DATADIR/ppd/passthrough.ppd"
export PRINTER=passthrough
#export SOFTWARE=CUPS/1.4.3
export USER=root

$filter 32 kintel `basename $file ps`cdr 1 options $file
exit $?
