$(call inherit-product-if-exists, target/allwinner/octopus-common/octopus-common.mk)

PRODUCT_PACKAGES +=

PRODUCT_COPY_FILES +=

PRODUCT_AAPT_CONFIG := large xlarge hdpi xhdpi
PRODUCT_AAPT_PERF_CONFIG := xhdpi
PRODUCT_CHARACTERISTICS := musicbox

PRODUCT_BRAND := allwinner
PRODUCT_NAME := octopus_sch
PRODUCT_DEVICE := octopus-sch
PRODUCT_MODEL := Octopus R58 Dev
