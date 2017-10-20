# $NetBSD: Makefile,v 1.1 2013/03/05 22:18:37 imil Exp $
# -*- mode: makefile; tab-width: 8; indent-tabs-mode: 1 -*-
# vim: ts=8 sw=8 ft=make noet

VERSION=		1.2.11
DISTNAME=		zlib-${VERSION}
PKGREVISION=		5
PKGNAME=		zlib-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		http://zlib.net/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.zlib.net/
COMMENT=	General purpose data compression library
LICENSE=	zlib

USE_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/zlib-${VERSION}

USE_LANGUAGES+=		c

pre-build:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}

post-install:
	cp ${FILESDIR}/libz.la ${DESTDIR}${PREFIX}/lib/libz.la

.include "../../mk/bsd.pkg.mk"
