#ifndef MINI_H
#define MINI_H
//the entire header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "spkgbuild"

// variables to search for in spkgbuild
#define PKG "pkgname="
#define VER "version="
#define REL "release="
#define EPH "epoch="
#define DES "descript"
#define MAI "maintainer"
#define ARK "arch="
#define URL "url="
#define LIC "license="
#define GRP "group="
#define DEP "depends="
#define MEP "makedepends="
#define CEP "checkdepends="
#define OEP "optdepends="
#define PRV "provides="
#define CNF "conflicts="
#define RPL "replaces="
#define BAC "backup="
#define OPT "options="
#define SCR "script="
#define SRC "source="
#define NOE "noextract="
#define VPG "validpgpkeys="
#define MD5 "md5sums="
#define SH1 "sha1sums="
#define SH2 "sha256sums="
#define SH5 "sha512sums="

#endif
