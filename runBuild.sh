###
 # @Date: 2022-01-08 22:03:33
 # @LastEditors: Please set LastEditors
 # @LastEditTime: 2022-01-10 22:28:02
 # @Author: Keeyu
 # @Github: https://github.com/keeYuc
###
#! /usr/bin/bash
CLPATH=`pwd`/build
NAME="plug"
CGO_ENABLED=1 GOOS=windows GOARCH=386 go build -buildmode=c-archive -o $NAME.a
#rm $CLPATH/*.lib
#rm $CLPATH/*dll.a
#rm $CLPATH/*.a
#rm $CLPATH/*.exp
#rm $CLPATH/*.h
mv $NAME.a $NAME.h $CLPATH
cd $CLPATH
bash exchange.sh