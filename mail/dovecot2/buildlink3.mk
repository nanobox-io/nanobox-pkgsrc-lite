# $NetBSD: buildlink3.mk,v 1.10 2015/03/14 10:52:09 adam Exp $

BUILDLINK_TREE+=	dovecot

.if !defined(DOVECOT_BUILDLINK3_MK)
DOVECOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=2.2.0
# must match current package version for plugins to load
BUILDLINK_ABI_DEPENDS.dovecot+=		dovecot>=2.2.16<2.2.17
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot2

pkgbase:=	dovecot
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.dovecot:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.elif !empty(PKG_BUILD_OPTIONS.dovecot:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # DOVECOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dovecot
