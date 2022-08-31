■ Create a new repository
<pre>
git clone https://github.com/ytg1123/Nutt_X.git
cd NuttX
touch README.md
git add README.md
git commit -m "add README"
git push -u origin master
</pre>

■ Existing folder
<pre>
cd existing_folder
git init
git remote add origin https://github.com/ytg1123/Nutt_X.git
git add .
git commit -m "Initial commit"
git push -u origin master
</pre>

■ Existing Git repository
<pre>
cd existing_repo
git remote rename origin old-origin
git remote add origin https://github.com/ytg1123/Nutt_X.git
git push -u origin --all
git push -u origin --tags
</pre>

■ 基本ツール導入<br>
$ sudo apt install build-essential<br>
$ sudo apt install make gperf flex bison libncurses-dev swig<br>

■ 作業フォルダ作成<br>
$ mkdir -p vivid-rtos<br>
$ cd vivid-rtos<br>

■ NuttX source path<br>
https://github.com/ytg1123/Nutt_X <br>
$ git clone https://github.com/ytg1123/Nutt_X.git

■ kconfigツールの導入<br>
$ git clone https://bitbucket.org/nuttx/tools<br>
$ cd tools/kconfig-frontends<br>
$ ./configure<br>
$ make -j 4<br>
$ sudo make install<br>
$ sudo /sbin/ldconfig<br>

■ NuttXビルド用ARMツールチェーンのインストール　gcc-v8版<br>
NuttXのビルドはgcc-v8を使いますので以下手順でgcc導入が必要です<br>
$ wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2<br>
$ tar xvf gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2<br>
$ mv gcc-arm-none-eabi-8-2018-q4-major ~/bin<br>
#それぞれの環境に合わせてPATH追加　（~/.bashrcなどに以下を追加など）<br>
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}<br>

■ u-boot-sunxi pcduino/H6/A10までサポート ARMツールチェーンのインストール　gcc-v4版<br>
AllwinnerA10チップ用splローダバイナリ生成とgcc-v4のinstallに関して<br>
A10のCPUリセットベクタ直後、pbl(PrimaryBootLoader)が実行後初期化が終了したらspl(SecondProgramLoader)が<br>
OSLoaderを起動します。<br>
splは実はu-boot-sunxiにソース定義されておりu-bootビルド時にsplフォルダに生成されている。<br>
NuttXはu-bootを使わないのですがsplを生成するために以下手順でビルドが必要です<br>
このu-bootのビルドに使うgccはgcc-v4版と少し古い版を使いますので以下でPATHを書き換える必要があります<br>

$ cd ~/NuttX<br>
$ wget https://launchpad.net/gcc-arm-embedded/4.7/4.7-2013-q1-update/+download/gcc-arm-none-eabi-4_7-2013q1-20130313-linux.tar.bz2<br>
$ tar xvf gcc-arm-none-eabi-4_7-2013q1-20130313-linux.tar.bz2<br>
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-4_7-2013q1/bin:${PATH}<br>

■ pcduino u-boot-sunxi.git　gcc-v4版<br>

$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-4_7-2013q1/bin:${PATH}<br>
$ git clone https://github.com/yuq/u-boot-sunxi.git<br>
$ cd u-boot-sunxi<br>
$ make pcduino CROSS_COMPILE=arm-none-eabi-<br>
$ ls ./spl/sunxi-spl.bin<br>

■  A33に対応したu-boot-2016.09 gccはv8版を利用<br>
$ git clone https://github.com/ARM-software/u-boot.git u-boot-2016.09<br>
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}<br>

CONFIG_MACH_SUN8I_A33対応u-boot利用ボードコンフィグ<br>

A33-OLinuXino_defconfig<br>
Bananapi_m2m_defconfig<br>
Nintendo_NES_Classic_Edition_defconfig<br>
Sinlinx_SinA33_defconfig<br>
ga10h_v1_1_defconfig<br>
iNet_D978_rev2_defconfig<br>
parrot_r16_defconfig<br>
q8_a33_tablet_1024x600_defconfig<br>
q8_a33_tablet_800x480_defconfig<br>

$ cd u-boot-2016.09<br>
$ make distclean<br>
$ make A33-OLinuXino_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>

Vividnodeの例<br>
$ make distclean<br>
$ make Vividnode_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>


Nintendo_NES_Classicの例<br>
$ make distclean<br>
$ make Nintendo_NES_Classic_Edition_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>

Orangepiの例<br>
$ make distclean<br>
$ make Orangepi_defconfig ARCH=arm ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>
$ make ARCH=arm CROSS_COMPILE=arm-linux-<br>

$ make distclean<br>
$ make A33-OLinuXino_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>


■  A33に対応したsunxi-v2017　gccはv8版を利用　この版はNG<br>
※A33への実装失敗してる、I2C_EEPROM関連でbuildが通らない<br>
※u-boot-2016.09に比べallwinner対応が増えているがソースがバグっている<br>
$ git clone https://github.com/friendlyarm/u-boot.git -b sunxi-v2017.x --depth 1 uboot-sunxi-v2017<br>
$ wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2<br>
$ tar xvf gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2<br>
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}<br>
$ cd uboot-sunxi-v2017<br>
$ make distclean<br>
$ make A33-OLinuXino_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>
$ make ARCH=arm CROSS_COMPILE=arm-none-eabi-<br>

$ sudo dd if=u-boot-sunxi-with-spl.bin of=/dev/mmcblk0 bs=1024 seek=8<br>

■ NuttX ソースの入手<br>
$ mkdir -p ~/NuttX<br>
$ git clone https://bitbucket.org/nuttx/nuttx.git<br>
$ git clone https://bitbucket.org/nuttx/apps.git<br>
$ cd nuttx<br>

■ PCDuino-v1 nuttx ビルド<br>

※ gcc-v8版でビルド<br>
$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}<br>
$ cd nuttx<br>
$ make distclean<br>
※ build環境をlinuxと指定してconfig実施<br>
$ tools/configure.sh -l pcduino-a10/nsh<br>
※ 必要であれば実施（menuconfigでカスタマイズが可能）<br>
$ make menuconfig<br>
#.configが生成される<br>
#ビルド実行<br>
$ make -j4<br>
※ nuttxフォルダ直下にバイナリファイル2個が生成される（nuttx.bin nuttx.hex）<br>


■ A33　nuttX arch/arm/Kconfigの編集<br>

先頭あたりのデフォルトconfigが以下の様に記述されている事を確認<br>
NuttXのデフォルトconfigはARCH_CHIP_STM32が選択されている様だ<br>

choice<br>
        prompt "ARM MCU selection"<br>
        default ARCH_CHIP_STM32<br>

ARCH_CHIP_A33　：　z7213のA33対応に関する記述を追記する<br>
config ARCH_CHIP_A33<br>
        bool "Allwinner A33"<br>
        select ARCH_CORTEXA7<br>
        select ARCH_HAVE_IRQPRIO<br>
        select ARCH_HAVE_LOWVECTORS<br>
        select ARCH_HAVE_FETCHADD<br>
        select ARCH_HAVE_SDRAM<br>
        select BOOT_RUNFROMSDRAM<br>
        select ARCH_HAVE_ADDRENV<br>
        select ARCH_NEED_ADDRENV_MAPPING<br>
        ---help---<br>
                Allwinner A33 family: ARM Cortex-A7<br>

ちなみにこの記述中にARCH_CORTEXA7がselectされている箇所がある<br>
ARCH_CORTEXA7のCPU機能を選択している。NuttXはCORTEXA7のフル機能をサポートしていないので<br>
実装済み機能でselect出来る選択肢を選んでいる。<br>
MMUの2段階TLBサポートとかL1L2キャッシュサポートなど実装できていない機能がたくさんある。<br>
NuttXで実装できているARM標準の機能だけしか選べない。<br>
NuttX実装標準ではARM標準の機能だけしか選べない<br>
SonyのNuttX実装ではマルチCPUやMMUフル実装サポートができている<br>

config ARCH_CORTEXA7<br>
        bool<br>
        default n<br>
        select ARCH_ARMV7A<br>
        select ARCH_DCACHE<br>
        select ARCH_ICACHE<br>
        select ARCH_HAVE_MMU<br>
        select ARCH_USE_MMU<br>
        select ARCH_HAVE_TESTSET<br>

■ A33　nuttX A33対応　フォルダ作成<br>

architecture 関連<br>
arch/arm/src/a33/<br>
arch/arm/include/a33<br>

ボード関連<br>
boards/arm/a3x/<br>
boards/Kconfig<br>

gicを使っているAllwinnerSOC：<br>
sun9iw1<br>
sun8iw1<br>
sun8iw9<br>
sun7i<br>
sun8iw3<br>
sun8iw7<br>
sun8iw8<br>
sun5i<br>
sun8iw5
sun8iw6<br>


■ A33　nuttX A33対応　build<br>

$ export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}<br>
$ cd nuttx<br>
$ make distclean<br>
$ tools/configure.sh -l vividnode-a33/nsh<br>
$ make menuconfig<br>
#ビルド実行<br>
$ make -j4<br>
※ nuttxフォルダ直下にバイナリファイル2個が生成される（nuttx.bin nuttx.hex）<br>


■ PCDuino-v1<br>

$ cd　u-boot-sunxi<br>
$ sudo dd if=./spl/sunxi-spl.bin of=/dev/mmcblk0 bs=1024 seek=8<br>
$　cd　../nuttx<br>
$ sudo dd if=nuttx.bin of=/dev/mmcblk0 bs=1024 seek=32<br>


■ sunxi boot spec<br>
https://linux-sunxi.org/Bootable_SD_card<br>

■ FELモードについて<br>
https://linux-sunxi.org/FEL<br>

実際時FELモードを利用してデータを転送するツール(z7213で動作確認済み)：<br>
https://github.com/jackmitch/sunxi-tools<br>

■ ダウンロード　lichee.brandy for tina3.5<br>
$ git clone git://git.yoctoproject.org/poky<br>
$ git clone git@157.7.129.177:vivid/lichee/brandy.git<br>

■ fel モードへの入り方　　シリアルコンソール方式<br>
シリアルコンソールから１又は２を押しながらPowewrOnするとu-bootが無くても、felモードに入れる<br>
実際、pcDuionoにはFELボタンがありこれを押しながらPowerOnするとfelモードに入る<br>
この機能はBROMに実装されている機能である<br>

felモードに対応していないu-bootからfelモードに入る場合は直接0xffff0020へジャンプすると入れる<br>
=> go 0xffff0020<br>


Through serial console<br>
If you have access to the UART already, you can send the character '1' ('2' on some devices) to the device during power-up.<br>

Boot1 is initialized using this method.<br>

With later SoCs, Allwinner's U-boot supports the "efex" command.<br>

If "efex" is not available in your U-boot, you can use the simple uboot "go" command with arguments pointing to the return FEL address:<br>
http://linux-sunxi.org/BROM#Other_booting_methods<br>
=> go 0xffff0020<br>
Starting application at 0xFFFF0020 ...<br>

■ flash書き込み手順　<br>
$ sudo sunxi-fel -p write 0x00000000 u-boot-sunxi-with-spl.bin<br>


$ sudo sunxi-fel exec 0x00000000<br>
$ sudo sunxi-fel -p write 0x80000000 rtthread.bin<br>
$ sudo sunxi-fel exec 0x80000000<br>

■  k210 nuttx porting <br>
※ この実装は32bitのk210<br>
n-miyamoto Naoya Miyamoto<br>
https://github.com/n-miyamoto/k210-nuttx.git<br>

