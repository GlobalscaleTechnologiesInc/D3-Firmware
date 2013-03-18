#!/bin/bash
OUTPUT_DIR="/tftpboot"
BOARD="rd88ap510avng"

cd ..
# first cleaning up source tree
make mrproper

# configuring
make rd88ap510avng_config BOOTROM=1 SPIBOOT=1 DRAM=SAMSUNG_1G NAND=0

# building
make -s -j3

# copy binaries to output directory
rm -fr $OUTPUT_DIR/$BOARD/1g
mkdir -p $OUTPUT_DIR/$BOARD/1g

cp ./u-boot-rd88ap510avng* $OUTPUT_DIR/$BOARD/1g/
