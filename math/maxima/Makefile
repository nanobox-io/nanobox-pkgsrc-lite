# $NetBSD: Makefile,v 1.48 2017/09/13 10:00:53 wiz Exp $

DISTNAME=		maxima-5.40.0
# On updates, please make sure editors/TeXmacs knows about the new
# version number.
# (if needed, patch plugins/maxima/bin/{maxima_detect,tm_maxima})
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system
LICENSE=		gnu-gpl-v2

# Note: lisp backend is depended and setup up for in options.mk
DEPENDS+=		tk-[0-9]*:../../x11/tk

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo perl
REPLACE_SH=		doc/misc/grepforvariables.sh

INFO_FILES=		yes
TEST_TARGET=		check
PYTHON_FOR_BUILD_ONLY=	yes

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
