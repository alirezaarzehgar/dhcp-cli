#!/bin/bash

EXECUTABLE=./$1
FAKE_DB=test.db

function randomMac() {
    echo -n 00:60:2F; dd bs=1 count=3 if=/dev/random 2>/dev/null |hexdump -v -e '/1 ":%02X"'
}

function randomStr()
{
    dd bs=1 count=6 if=/dev/random 2>/dev/null |hexdump -v -e '/1 "%x"'
}

function randomUserName() {
    echo $(randomStr)
}

function randomDomain() {
    echo $(randomStr).com
}

function printConfigData() {
    echo 255.255.255.0
    echo 192.168.133.$1
    echo $(randomDomain)
    echo
    echo Y
}

function printLeaseData() {
    echo $(randomUserName)
    echo $(echo $((RANDOM%6)))
    echo $(randomMac)
    echo 192.168.133.$1
    echo
    echo Y
}

rm -rf $FAKE_DB 
$EXECUTABLE -i$FAKE_DB 1&>2 /dev/null

for i in `seq 5`;
do
    printConfigData $i | $EXECUTABLE -f $FAKE_DB --add --config 1&>2 /dev/null
done

for i in `seq 20`;
do
    printLeaseData $i | $EXECUTABLE -f $FAKE_DB --add --lease 1&>2 /dev/null
done