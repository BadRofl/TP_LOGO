#!/bin/bash

make clean
make

echo "Entrer un fichier logo source: "
read PATH

./LOGO < $(PATH)
