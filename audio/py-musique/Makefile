# $NetBSD: Makefile,v 1.55 2017/09/04 18:00:49 wiz Exp $

DISTNAME=	pymusique-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	31
CATEGORIES=	audio
#MASTER_SITES=	http://www.pyronecrophilia.com/content/pymusique/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.pyronecrophilia.com/content/pymusique/
COMMENT=	Interface to the iTunes Music Store

RESTRICTED=	Possible legal problems due to iTunes access
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-mcrypt-[0-9]*:../../security/py-mcrypt
DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-mcrypt, py-gtk2

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
