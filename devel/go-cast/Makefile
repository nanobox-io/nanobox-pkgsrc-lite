# $NetBSD: Makefile,v 1.3 2017/08/25 17:03:25 jperkin Exp $

DISTNAME=	cast-1.1.0
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=     v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/cast
COMMENT=	Safe and easy casting from one type to another in Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/spf13/cast

.include "../../devel/go-jwalterweatherman/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
