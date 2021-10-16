#!/bin/bash

workingDir=$1

dbfile=$(find $workingDir -name "dhcpd.db")

dbpath=$(realpath $dbfile)

dirname $dbpath | head -1