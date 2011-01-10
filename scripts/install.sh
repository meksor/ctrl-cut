#!/bin/bash

if [ ! $# -eq 2 ]; then
    echo "install.sh PRINTERNAME PPDNAME"
fi

PRINTER=$1
PPDNAME=$2
FILTER_PATH="`cups-config --serverbin`/filter"

# generate ppd files
$EC_SCRIPTS/generate_ppds.sh

# copy epilog filter into the cups filter path
cp EpilogFilter $FILTER_PATH/epilogcups

# install the printer
/usr/sbin/lpadmin -p "$PRINTER" -P "$EC_PPD_DIR/$PPDNAME"

