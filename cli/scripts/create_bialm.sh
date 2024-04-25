#!/bin/bash

link=https://raw.githubusercontent.com/ribana-b/void/develop/bob_is_a_lazy_man/bob_is_a_lazy_man.h
dir=../bob_is_a_lazy_man

mkdir -p $dir
curl -s $link > $dir/bob_is_a_lazy_man.h
