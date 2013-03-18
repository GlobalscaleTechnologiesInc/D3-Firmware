#!/bin/bash
OUTPUT_DIR="/tftpboot"
BOARD="rd88ap510_a0_avng"

cd ..
# first cleaning up source tree
make mrproper

# configuring
echo "new dramc reg file"
make rd88ap510_a0_avng_config BOOTROM=1 SPIBOOT=1 DRAM=SAMSUNG_2G_A0 

# building
make -s -j3

# copy binaries to output directory
rm -fr $OUTPUT_DIR/$BOARD/2g
mkdir -p $OUTPUT_DIR/$BOARD/2g

cp ./u-boot-rd88ap510_a0_avng* $OUTPUT_DIR/$BOARD/2g/
