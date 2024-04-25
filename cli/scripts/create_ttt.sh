#!/bin/bash

link=https://raw.githubusercontent.com/ribana-b/void/develop/trolling_the_troll/trolling_the_troll.h
dir=../trolling_the_troll

mkdir -p $dir
curl -s $link > $dir/trolling_the_troll.h
