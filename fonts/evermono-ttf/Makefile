# $NetBSD: Makefile,v 1.4 2017/08/16 20:45:36 wiz Exp $

DISTNAME=	evermono
VERSION=	7.0.0
PKGNAME=	evermono-ttf-${VERSION}
CATEGORIES=	fonts
#MASTER_SITES=	http://www.evertype.com/emono/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.evertype.com/emono/
COMMENT=	Simple, elegant, monowidth font with wide Unicode coverage
LICENSE=	evermono-license

DIST_SUBDIR=	evermono-ttf-${VERSION}

WRKSRC=		${WRKDIR}/evermono-${VERSION}
USE_LANGUAGES=	# none

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} share/doc/evermono-ttf

do-build:
do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/emono-licence.txt ${DESTDIR}${PREFIX}/share/doc/evermono-ttf/

.include "../../mk/bsd.pkg.mk"
