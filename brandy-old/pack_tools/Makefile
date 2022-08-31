all:
	make -C create_mbr
	make -C update_boot0
	make -C update_checksum
	make -C update_fes1
	make -C update_signature
	make -C update_simg
	make -C update_uboot
	make -C parser_img
	make -C openssl_signature
	make -C script
	make -C create_paragremer_img

	cp create_mbr/update_mbr 			../../../tools/pack-bintools/src/update_mbr
	cp update_boot0/update_boot0 			../../../tools/pack-bintools/src/update_boot0
	cp update_checksum/genchecksum_uboot 		../../../tools/pack-bintools/src/genchecksum_uboot
	cp update_fes1/update_fes1  			../../../tools/pack-bintools/src/update_fes1
	cp update_signature/signature 			../../../tools/pack-bintools/src/signature
	cp update_simg/simg 				../../../tools/pack-bintools/src/simg
	cp update_uboot/update_uboot 			../../../tools/pack-bintools/src/update_uboot
	cp parser_img/parser_img 			../../../tools/pack-bintools/src/parser_img
	cp openssl_signature/sunxi_sign 		../../../tools/pack-bintools/src/sunxi_sign
	cp script/script 				../../../tools/pack-bintools/src/script
	cp create_paragremer_img/programmer_img 	../../../tools/pack-bintools/src/programmer_img


