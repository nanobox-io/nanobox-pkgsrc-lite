# $NetBSD: Makefile,v 1.19 2015/03/20 16:33:28 taca Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
COMMENT=		PHP extension for zlib compression

CONFLICTS=	php-zlib-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

# See https://bugs.php.net/bug.php?id=53829
.include "../../devel/zlib/builtin.mk"
.if empty(USE_BUILTIN.zlib:M[Yy][Ee][Ss])
CFLAGS+=		-DZLIB_INTERNAL=1
.endif

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
