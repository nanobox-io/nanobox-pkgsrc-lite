# $NetBSD: Makefile,v 1.4 2017/09/04 18:01:03 wiz Exp $

DISTNAME=	PasteScript-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PasteScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pythonpaste.org/script/
COMMENT=	Pluggable command-line frontend for setting up package file layouts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-paste-[0-9]*:../../www/py-paste

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
