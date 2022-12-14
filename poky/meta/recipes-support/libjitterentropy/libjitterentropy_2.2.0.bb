SUMMARY = "Hardware RNG based on CPU timing jitter"
DESCRIPTION = "The Jitter RNG provides a noise source using the CPU execution timing jitter. \
It does not depend on any system resource other than a high-resolution time \
stamp. It is a small-scale, yet fast entropy source that is viable in almost \
all environments and on a lot of CPU architectures."
HOMEPAGE = "http://www.chronox.de/jent.html"
LICENSE = "GPLv2+ | BSD"
LIC_FILES_CHKSUM = "file://COPYING;md5=a95aadbdfae7ed812bb2b7b86eb5981c \
                    file://COPYING.gplv2;md5=eb723b61539feef013de476e68b5c50a \
                    file://COPYING.bsd;md5=66a5cedaf62c4b2637025f049f9b826f \
                    "
SRC_URI = "git://github.com/smuellerDD/jitterentropy-library.git \
           file://0001-Makefile-cleanup-install-for-rebuilds.patch"
SRCREV = "933a44f33ed3d6612f7cfaa7ad1207c8da4886ba"
S = "${WORKDIR}/git"

do_configure[noexec] = "1"

LDFLAGS += "-Wl,-O0"

do_install () {
    oe_runmake install INCDIR="/include" \
                       DESTDIR="${D}" \
                       PREFIX="${exec_prefix}" \
                       LIBDIR="${baselib}" \
                       INSTALL_STRIP="install"
}

