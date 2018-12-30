#!/bin/bash

CMDNAME=`basename $0`

filename="*.c"

#引数チェック
if [ $# -lt 1 ] || [ $# -gt 2 ];then
	echo "Usage: $CMDNAME file or file clean" 1>&2
	exit 1
fi

case "$1" in
		$filename) FLG_A="TRUE";;
		*) echo "Usage: file extension < $filename >"
	exit 1 ;;
esac

if [ $# -eq 2 ];then
	case "$2" in
			"clean") FLG_B="TRUE";;
			*) echo "Usage: $CMDNAME file clean"
		exit 1 ;;
	esac

	rm -f 
fi
	
exit 0
