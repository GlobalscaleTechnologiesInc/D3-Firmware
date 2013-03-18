#!/bin/bash
OUTPUT_DIR="/tftpboot"
BOARD="db88ap510bp_b"

cd ..
# first cleaning up source tree
make mrproper

# configuring
make db88ap510bp_b_config BOOTROM=1 SPIBOOT=1 DRAM=2CS NAND=1

# building
make -s -j3

# copy binaries to output directory
rm -fr $OUTPUT_DIR/$BOARD/spi
mkdir -p $OUTPUT_DIR/$BOARD/spi

cp ./u-boot-db88ap510bp_b* $OUTPUT_DIR/$BOARD/spi/
