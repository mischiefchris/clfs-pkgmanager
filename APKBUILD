# Contributor: Natanael Copa <ncopa@alpinelinux.org>
# Maintainer: Ariadne Conill <ariadne@dereferenced.org>
pkgname=binutils
pkgver=2.37
pkgrel=3
pkgdesc="Tools necessary to build programs"
url="https://www.gnu.org/software/binutils/"
makedepends_build="bison flex texinfo"
makedepends_host="zlib-dev"
makedepends="$makedepends_build $makedepends_host"
arch="all"
license="GPL-2.0 GPL-3.0-or-later LGPL-2.0 BSD"
subpackages="$pkgname-dev $pkgname-doc"
source="https://ftp.gnu.org/gnu/binutils/binutils-$pkgver.tar.xz
	binutils-ld-fix-static-linking.patch
	gold-mips.patch
	ld-bfd-mips.patch
	0001-Revert-PR25882-.gnu.attributes-are-not-checked-for-s.patch
	binutils-mips-disable-assert.patch
	bfd-close-file-desriptor-if-there-is-no-archive-fd.patch
	defang-no-split.patch
	"
builddir="$srcdir/$pkgname-$pkgver"

if [ "$CHOST" = "$CBUILD" ] && [ "$CBUILD" = "$CTARGET" ] && [ "$CTARGET_ARCH" != "riscv64" ]; then
	subpackages="$subpackages $pkgname-gold"
fi

if [ "$CHOST" != "$CTARGET" ]; then
	pkgname="$pkgname-$CTARGET_ARCH"
	subpackages=""
	sonameprefix="$pkgname:"
fi

# secfixes:
#   2.35.2-r1:
#     - CVE-2021-3487
#   2.32-r0:
#     - CVE-2018-19931
#     - CVE-2018-19932
#     - CVE-2018-20002
#     - CVE-2018-20712
#   2.28-r1:
#     - CVE-2017-7614

build() {
	local _sysroot=/
	local _cross_configure="--enable-install-libiberty --enable-shared"
	local _arch_configure=""
	local _gold_configure="--disable-gold"
	local _plugin_configure="--enable-plugins"

	if [ "$CHOST" != "$CTARGET" ]; then
		_sysroot="$CBUILDROOT"
		_cross_configure="--disable-install-libiberty"
		_plugin_configure="--disable-plugins"
	fi

	if [ "$CHOST" = "$CBUILD" ] && [ "$CBUILD" = "$CTARGET" ] && [ "$CTARGET_ARCH" != "riscv64" ]; then
		_gold_configure="--enable-gold"
	fi

	if [ "$CTARGET_ARCH" = "x86_64" ]; then
		_arch_configure="--enable-targets=x86_64-pep"
	fi

	if [ "$CTARGET_ARCH" = "riscv64" ]; then
		_gold_configure="--disable-gold"
	fi

	case "$CTARGET_ARCH" in
	mips*)  _hash_style_configure="--enable-default-hash-style=sysv" ;;
	*)      _hash_style_configure="--enable-default-hash-style=gnu"	;;
	esac

	./configure \
		--build=$CBUILD \
		--host=$CHOST \
		--target=$CTARGET \
		--with-build-sysroot="$CBUILDROOT" \
		--with-sysroot=$_sysroot \
		--prefix=/usr \
		--mandir=/usr/share/man \
		--infodir=/usr/share/info \
		--disable-multilib \
		--enable-ld=default \
		$_gold_configure \
		--enable-64-bit-bfd \
		$_plugin_configure \
		--enable-relro \
		--enable-deterministic-archives \
		$_cross_configure \
		$_arch_configure \
		$_hash_style_configure \
		--with-pic \
		--disable-werror \
		--disable-nls \
		--with-mmap \
		--with-system-zlib
	make
}

package() {
	make install DESTDIR="$pkgdir"
	if [ -d "$pkgdir"/usr/lib64 ]; then
		mv "$pkgdir"/usr/lib64/* "$pkgdir"/usr/lib/
		rmdir "$pkgdir"/usr/lib64
	fi
	if [ "$CHOST" != "$CTARGET" ]; then
		# creating cross tools: remove any files that would conflict
		# with the native tools, or other cross tools
		rm -r "${pkgdir:?}"/usr/share
		rm -f "$pkgdir"/usr/lib/libiberty.a
		rm -r "${pkgdir:?}"/usr/lib/bfd-plugins
	fi
}

libs() {
	pkgdesc="Runtime libraries from binutils - libbfd and libopcodes"

	mkdir -p "$subpkgdir"/usr/lib
	mv "$pkgdir"/usr/lib/lib*.so "$subpkgdir"/usr/lib/
}

gold() {
	pkgdesc="GNU binutils - gold linker"

	if [ -e "$pkgdir"/usr/bin/ld.gold ]; then
		mkdir -p "$subpkgdir"/usr/bin
		mv "$pkgdir"/usr/bin/ld.gold "$subpkgdir"/usr/bin
	fi
	mkdir -p "$subpkgdir"/usr/$CTARGET/bin
	mv "$pkgdir"/usr/$CTARGET/bin/ld.gold "$subpkgdir"/usr/$CTARGET/bin/ld.gold
}

sha512sums="
5c11aeef6935860a6819ed3a3c93371f052e52b4bdc5033da36037c1544d013b7f12cb8d561ec954fe7469a68f1b66f1a3cd53d5a3af7293635a90d69edd15e7  binutils-2.37.tar.xz
ecee33b0e435aa704af1c334e560f201638ff79e199aa11ed78a72f7c9b46f85fbb227af5748e735fd681d1965fcc42ac81b0c8824e540430ce0c706c81e8b49  binutils-ld-fix-static-linking.patch
f55cf2e0bf82f97583a1abe10710e4013ecf7d64f1da2ef8659a44a06d0dd8beaf58dab98a183488ea137f03e32d62efc878d95f018f836f8cec870bc448556f  gold-mips.patch
314d2ef9071c89940aa6c8118e8a1e2f191a5d0a4bf596da1ad9cc84f884d8bc7dea8bd7b9fc3f8f1bddd3fd41c6eb017e1e804044b3bf084df1ed9e6e095e2d  ld-bfd-mips.patch
70ec22bd72ef6dddecfd970613387dd4a8cdc8730dd3cbf03d5a0c3a7c4d839383167bb06dad21bf7c235329fd44b5dc4aefe762f68544f17155cf002bf1be4a  0001-Revert-PR25882-.gnu.attributes-are-not-checked-for-s.patch
609cd90d8b334eb309f586b17b9d335a08d3dbb6def7c3eb5c010028fcb681674031e5b9d853aa7a39a50304356a86afc184b85562b3f228f8197f4d29395c8f  binutils-mips-disable-assert.patch
10a0074583d2cc4598710c7e434ba7088da074b105f4f5e951fc61af7150ad62adf60a7c98f6fd13b1771f169e45a5a1ef618240c6893d3f0f3d93fd768a03c6  bfd-close-file-desriptor-if-there-is-no-archive-fd.patch
4652f092c9376f0cb7fd6c72cb37ff7c15c1c6e3408fac79329b7f41a7925c98eb35989a9a040682130988a36401901d6d95afa44f0ce50caa85ee478db6bf03  defang-no-split.patch
"
