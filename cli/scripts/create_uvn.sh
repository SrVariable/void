#!/bin/bash

link=https://raw.githubusercontent.com/ribana-b/void/develop/ultramarines_vs_necrones/ultramarines_vs_necrones.h
dir=../ultramarines_vs_necrones

mkdir -p $dir
curl -s $link > $dir/ultramarines_vs_necrones.h
