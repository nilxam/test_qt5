#!/bin/bash

qmake-qt5
make
g++ -rdynamic -o run run.cpp -ldl
