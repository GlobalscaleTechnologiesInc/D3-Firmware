#!/bin/bash
OUTPUT_DIR="/tftpboot"
BOARD="db88ap510_pcac"

cd ..
# first cleaning up source tree
make mrproper

# configuring
make db88ap510_pcac_config BOOTROM=1 SPIBOOT=1 DRAM=2CS

# building
make -s -j3

# copy binaries to output directory
rm -fr $OUTPUT_DIR/$BOARD/spi
mkdir -p $OUTPUT_DIR/$BOARD/spi

cp ./u-boot-db88ap510_pcac* $OUTPUT_DIR/$BOARD/spi/
