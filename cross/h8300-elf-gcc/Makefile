# $NetBSD: Makefile,v 1.3 2017/09/09 15:17:12 dholland Exp $

DISTNAME=		gcc-6.2.0
PKGNAME=		cross-h8300-elf-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			newlib-${NEWLIBVER}.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		#empty
COMMENT=		GCC compiler for h8300-elf

NEWLIBVER=		2.4.0
SITES.newlib-${NEWLIBVER}.tar.gz=	ftp://sources.redhat.com/pub/newlib/

DEPENDS+=	cross-h8300-elf-binutils-[0-9]*:../../cross/h8300-elf-binutils

.include "../../mk/bsd.prefs.mk"
# To avoid an internal compiler error of a library for h8300h
#  on NetBSD/amd64 7.99.39 (GCC 5.4)
.if ${OPSYS} == "NetBSD"
GCC_REQD+=		6.2
.endif

USE_LANGUAGES=		c c++

H8300_PREFIX=		${PREFIX}/cross-h8300-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${H8300_PREFIX}

CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--target=h8300-elf
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
INFO_FILES=		yes

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
