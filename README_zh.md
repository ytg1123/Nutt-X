■基本ツール導入
$ sudo apt install build-essential
$ sudo apt install make gperf flex bison libncurses-dev swig

■作業フォルダ作成
$ mkdir -p vivid-rtos
$ cd vivid-rtos

■kconfigツールの導入
$ git clone https://bitbucket.org/nuttx/tools
$ cd tools/kconfig-frontends
$ ./configure
$ make -j 4
$ sudo make install
$ sudo /sbin/ldconfig

■NuttXビルド用ARMツールチェーンのインストール　gcc-v8版
NuttXのビルドはgcc-v8を使いますので以下手順でgcc導入が必要です
$ wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2
$ tar xvf gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2
$ mv gcc-arm-none-eabi-8-2018-q4-major ~/bin
#それぞれの環境に合わせてPATH追加　（~/.bashrcなどに以下を追加など）
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}

■u-boot-sunxi pcduino/H6/A10までサポート ARMツールチェーンのインストール　gcc-v4版
AllwinnerA10チップ用splローダバイナリ生成とgcc-v4のinstallに関して
A10のCPUリセットベクタ直後、pbl(PrimaryBootLoader)が実行後初期化が終了したらspl(SecondProgramLoader)が
OSLoaderを起動します。
splは実はu-boot-sunxiにソース定義されておりu-bootビルド時にsplフォルダに生成されている。
NuttXはu-bootを使わないのですがsplを生成するために以下手順でビルドが必要です
このu-bootのビルドに使うgccはgcc-v4版と少し古い版を使いますので以下でPATHを書き換える必要があります

$ cd ~/NuttX
$ wget https://launchpad.net/gcc-arm-embedded/4.7/4.7-2013-q1-update/+download/gcc-arm-none-eabi-4_7-2013q1-20130313-linux.tar.bz2
$ tar xvf gcc-arm-none-eabi-4_7-2013q1-20130313-linux.tar.bz2
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-4_7-2013q1/bin:${PATH}

■pcduino u-boot-sunxi.git　gcc-v4版

$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-4_7-2013q1/bin:${PATH}
$ git clone https://github.com/yuq/u-boot-sunxi.git
$ cd u-boot-sunxi
$ make pcduino CROSS_COMPILE=arm-none-eabi-
$ ls ./spl/sunxi-spl.bin

■ A33に対応したu-boot-2016.09 gccはv8版を利用
$ git clone https://github.com/ARM-software/u-boot.git u-boot-2016.09
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}

CONFIG_MACH_SUN8I_A33対応u-boot利用ボードコンフィグ

A33-OLinuXino_defconfig
Bananapi_m2m_defconfig
Nintendo_NES_Classic_Edition_defconfig
Sinlinx_SinA33_defconfig
ga10h_v1_1_defconfig
iNet_D978_rev2_defconfig
parrot_r16_defconfig
q8_a33_tablet_1024x600_defconfig
q8_a33_tablet_800x480_defconfig

$ cd u-boot-2016.09
$ make distclean
$ make A33-OLinuXino_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-

Vividnodeの例
$ make distclean
$ make Vividnode_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-


Nintendo_NES_Classicの例
$ make distclean
$ make Nintendo_NES_Classic_Edition_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-

Orangepiの例
$ make distclean
$ make Orangepi_defconfig ARCH=arm ARCH=arm CROSS_COMPILE=arm-none-eabi-
$ make ARCH=arm CROSS_COMPILE=arm-linux-

$ make distclean
$ make A33-OLinuXino_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-


■ A33に対応したsunxi-v2017　gccはv8版を利用　この版はNG
※A33への実装失敗してる、I2C_EEPROM関連でbuildが通らない
※u-boot-2016.09に比べallwinner対応が増えているがソースがバグっている
$ git clone https://github.com/friendlyarm/u-boot.git -b sunxi-v2017.x --depth 1 uboot-sunxi-v2017
$ wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2
$ tar xvf gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}
$ cd uboot-sunxi-v2017
$ make distclean
$ make A33-OLinuXino_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-

$ sudo dd if=u-boot-sunxi-with-spl.bin of=/dev/mmcblk0 bs=1024 seek=8

■NuttX ソースの入手
$ mkdir -p ~/NuttX
$ git clone https://bitbucket.org/nuttx/nuttx.git
$ git clone https://bitbucket.org/nuttx/apps.git
$ cd nuttx

■PCDuino-v1 nuttx ビルド

※gcc-v8版でビルド
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}
$ cd nuttx
$ make distclean
※build環境をlinuxと指定してconfig実施
$ tools/configure.sh -l pcduino-a10/nsh
※必要であれば実施（menuconfigでカスタマイズが可能）
$ make menuconfig
#.configが生成される
#ビルド実行
$ make -j4
※nuttxフォルダ直下にバイナリファイル2個が生成される（nuttx.bin nuttx.hex）


■A33　nuttX arch/arm/Kconfigの編集

先頭あたりのデフォルトconfigが以下の様に記述されている事を確認
NuttXのデフォルトconfigはARCH_CHIP_STM32が選択されている様だ

choice
        prompt "ARM MCU selection"
        default ARCH_CHIP_STM32

ARCH_CHIP_A33　：　z7213のA33対応に関する記述を追記する
config ARCH_CHIP_A33
        bool "Allwinner A33"
        select ARCH_CORTEXA7
        select ARCH_HAVE_IRQPRIO
        select ARCH_HAVE_LOWVECTORS
        select ARCH_HAVE_FETCHADD
        select ARCH_HAVE_SDRAM
        select BOOT_RUNFROMSDRAM
        select ARCH_HAVE_ADDRENV
        select ARCH_NEED_ADDRENV_MAPPING
        ---help---
                Allwinner A33 family: ARM Cortex-A7

ちなみにこの記述中にARCH_CORTEXA7がselectされている箇所がある
ARCH_CORTEXA7のCPU機能を選択している。NuttXはCORTEXA7のフル機能をサポートしていないので
実装済み機能でselect出来る選択肢を選んでいる。
MMUの2段階TLBサポートとかL1L2キャッシュサポートなど実装できていない機能がたくさんある。
NuttXで実装できているARM標準の機能だけしか選べない。
NuttX実装標準ではARM標準の機能だけしか選べない
SonyのNuttX実装ではマルチCPUやMMUフル実装サポートができている

config ARCH_CORTEXA7
        bool
        default n
        select ARCH_ARMV7A
        select ARCH_DCACHE
        select ARCH_ICACHE
        select ARCH_HAVE_MMU
        select ARCH_USE_MMU
        select ARCH_HAVE_TESTSET

■A33　nuttX A33対応　フォルダ作成

architecture 関連
arch/arm/src/a33/
arch/arm/include/a33

ボード関連
boards/arm/a3x/
boards/Kconfig

gicを使っているAllwinnerSOC：
sun9iw1
sun8iw1
sun8iw9
sun7i
sun8iw3
sun8iw7
sun8iw8
sun5i
sun8iw5
sun8iw6


■A33　nuttX A33対応　build

$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}
$ cd nuttx
$ make distclean
$ tools/configure.sh -l vividnode-a33/nsh
$ make menuconfig
#ビルド実行
$ make -j4
※nuttxフォルダ直下にバイナリファイル2個が生成される（nuttx.bin nuttx.hex）


■PCDuino-v1

$ cd　u-boot-sunxi
$ sudo dd if=./spl/sunxi-spl.bin of=/dev/mmcblk0 bs=1024 seek=8
$　cd　../nuttx
$ sudo dd if=nuttx.bin of=/dev/mmcblk0 bs=1024 seek=32


■sunxi boot spec
https://linux-sunxi.org/Bootable_SD_card

■FELモードについて
https://linux-sunxi.org/FEL

実際時FELモードを利用してデータを転送するツール(z7213で動作確認済み)：
https://github.com/jackmitch/sunxi-tools

■ダウンロード　lichee.brandy for tina3.5
$ git clone git://git.yoctoproject.org/poky
$ git clone git@157.7.129.177:vivid/lichee/brandy.git

■fel モードへの入り方　　シリアルコンソール方式
シリアルコンソールから１又は２を押しながらPowewrOnするとu-bootが無くても、felモードに入れる
実際、pcDuionoにはFELボタンがありこれを押しながらPowerOnするとfelモードに入る
この機能はBROMに実装されている機能である

felモードに対応していないu-bootからfelモードに入る場合は直接0xffff0020へジャンプすると入れる
=> go 0xffff0020


Through serial console
If you have access to the UART already, you can send the character '1' ('2' on some devices) to the device during power-up.

Boot1 is initialized using this method.

With later SoCs, Allwinner's U-boot supports the "efex" command.

If "efex" is not available in your U-boot, you can use the simple uboot "go" command with arguments pointing to the return FEL address:
http://linux-sunxi.org/BROM#Other_booting_methods
=> go 0xffff0020
Starting application at 0xFFFF0020 ...

■flash書き込み手順　
$ sudo sunxi-fel -p write 0x00000000 u-boot-sunxi-with-spl.bin


$ sudo sunxi-fel exec 0x00000000
$ sudo sunxi-fel -p write 0x80000000 rtthread.bin
$ sudo sunxi-fel exec 0x80000000







