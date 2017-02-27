# $NetBSD: options.mk,v 1.4 2016/11/26 16:12:18 marino Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc5-aux
PKG_SUPPORTED_OPTIONS=  fortran objc testsuite static bootstrap allstages
PKG_SUGGESTED_OPTIONS=  #fortran objc 

# disable nls for now (build error involving iconv)
# disable fortran, breaks during build on NetBSD 7.0-beta

.include "../../mk/bsd.options.mk"


# Bootstrap is essentially a maintainer option and it will ignore
# all other options because it is intent on building a bootstrap compiler.


#############################
##  ADD LANGUAGE: Fortran  ##
#############################

.if empty(PKG_OPTIONS:Mfortran) || !empty(PKG_OPTIONS:Mbootstrap)
EXTRA_CONFARGS+= --disable-libquadmath
.else
LANGS+= fortran
APPLY_DIFFS+= fortran
.if ${OPSYS} == NetBSD
EXTRA_CONFARGS+= --disable-libquadmath
.else
EXTRA_CONFARGS+= --enable-libquadmath
.endif
.endif


#################################
##  ADD LANGUAGE: Objective-C  ##
#################################

.if !empty(PKG_OPTIONS:Mobjc) && empty(PKG_OPTIONS:Mbootstrap)
LANGS+= objc
.endif


#########################
##  TESTSUITE SUPPORT  ##
#########################

.if !empty(PKG_OPTIONS:Mtestsuite) && empty(PKG_OPTIONS:Mbootstrap)
BUILD_DEPENDS+= dejagnu>=1.4:../../devel/dejagnu
APPLY_DIFFS+= ada-testsuite
APPLY_DIFFS+= cxx-testsuite
APPLY_DIFFS+= gcc-testsuite
.endif


#################################
##  NATIONAL LANGUAGE SUPPORT  ##
#################################

EXTRA_CONFARGS+= --disable-nls


###############################
##  STATICALLY BUILT OPTION  ##
###############################

.if !empty(PKG_OPTIONS:Mstatic)
STATIC_BUILD = yes
.endif

.if defined(STATIC_BUILD) && empty(PKG_OPTIONS:Mbootstrap)
.  if ${OPSYS} == SunOS
PKG_FAIL_REASON+= SunOS does not support static builds
.  else
EXTRA_CONFARGS+= --with-stage1-ldflags=-static
.  endif
.endif


#################################
##  BOOTSTRAP COMPILER OPTION  ##
#################################

# Solaris does not support static linking system libraries, so bootstraps
# on SunOS require gmp&co to be built with gcc.  Also, OpenBSD x86-64
# fails configuration during the linking of -lmpc -lmpfr -lgmp in a contest;
# it complains of missing references in libm.  These libraries are built by
# a different compiler (the base) so perhaps that's the problem.  Building
# gmp&co in the tree allows the configure step to succeed on OpenBSD.

.if ${OPSYS} == OpenBSD || ${OPSYS} == MirBSD || \
   (${OPSYS} == SunOS && !empty(PKG_OPTIONS:Mbootstrap))
.include "../../devel/gmp/inplace.mk"
.include "../../math/mpcomplex/inplace.mk"
.include "../../math/mpfr/inplace.mk"
.else
EXTRA_CONFARGS+= --with-gmp=${BUILDLINK_PREFIX.gmp}
EXTRA_CONFARGS+= --with-mpfr=${BUILDLINK_PREFIX.mpfr}
EXTRA_CONFARGS+= --with-mpc=${BUILDLINK_PREFIX.mpcomplex}
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mbootstrap)
EXTRA_CONFARGS+= --disable-shared --disable-lto
EXTRA_CONFARGS+= --disable-libstdcxx-pch
.  if ${OPSYS} != SunOS
EXTRA_CONFARGS+= --with-stage1-ldflags=-static
EXTRA_CONFARGS+= --with-boot-ldflags=-static
EXTRA_CONFARGS+= --with-system-zlib
.  endif
.else
.  if empty(PKG_OPTIONS:Mallstages)
EXTRA_CONFARGS+= --disable-bootstrap
EXTRA_CONFARGS+= --disable-libcc1
.  endif
EXTRA_CONFARGS+= --enable-shared
.endif
