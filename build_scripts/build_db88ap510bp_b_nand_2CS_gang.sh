#!/bin/bash
OUTPUT_DIR="/tftpboot"
BOARD="db88ap510bp_b"

cd ..
# first cleaning up source tree
make mrproper

make db88ap510bp_b_config BOOTROM=1 NANDBOOT=1 NAND=1 DRAM=2CS

# building
make -s -j3

# copy binaries to output directory
rm -fr $OUTPUT_DIR/$BOARD/nand
mkdir -p $OUTPUT_DIR/$BOARD/nand

cp ./u-boot-db88ap510bp_b* $OUTPUT_DIR/$BOARD/nand/
