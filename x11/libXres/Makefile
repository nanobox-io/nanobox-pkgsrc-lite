# $NetBSD: Makefile,v 1.12 2017/10/11 16:45:43 wiz Exp $

DISTNAME=		libXres-1.2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Resource Information Extension Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xres.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/resourceproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
