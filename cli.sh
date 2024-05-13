#!/bin/bash

if [[ ! -d ../void ]]; then
	cd $HOME
fi

if [[ ! -d ./void ]] && [[ ! -d ../void ]]; then
	git clone https://github.com/ribana-b/void.git 
fi

if [[ -d ./void ]]; then
	cd void
fi

git switch release > /dev/null 2>&1
mkdir -p lib
cd lib

if [[ ! -d ./BFL ]];then
	git clone https://github.com/SrVariable/BFL.git
fi

if [[ ! -f ./BFL/libBFL.a ]]; then
	make -sC BFL
	rm -rf ./BFL/bool ./BFL/char ./BFL/fd ./BFL/ft_printf ./BFL/get_next_line \
	./BFL/math ./BFL/memory ./BFL/obj ./BFL/string ./BFL/linked_list \
	./BFL/test ./BFL/README.md
fi

make run -sC ../cli
