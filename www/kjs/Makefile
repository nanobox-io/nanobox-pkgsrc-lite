# $NetBSD: Makefile,v 1.6 2017/09/18 09:53:06 maya Exp $

DISTNAME=	kjs-${KF5VER}
PKGREVISION=	5
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for JS scripting in applications
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.25/portingAids/}

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	perl pkg-config

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
