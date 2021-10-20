#!/bin/bash

EXECUTABLE=./$1
FAKE_DB=test.db

function printConfigData() {
    echo 255.255.255.0
    echo 192.168.133.2
    echo example.com
    echo
    echo Y
}

function printLeaseData() {
    echo "ali"
    echo 2
    echo 192.168.133.2
    echo
    echo
    echo Y
}

rm -rf $FAKE_DB 
$EXECUTABLE -i$FAKE_DB 1&>2 /dev/null

for i in `seq 5`;
do
    printConfigData | $EXECUTABLE -f $FAKE_DB --add --config 1&>2 /dev/null
done

for i in `seq 20`;
do
    printLeaseData | $EXECUTABLE -f $FAKE_DB --add --lease 1&>2 /dev/null
done