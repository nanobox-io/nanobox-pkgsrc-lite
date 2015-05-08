# $NetBSD: buildlink3.mk,v 1.9 2014/09/06 08:20:29 jperkin Exp $

BUILDLINK_TREE+=	gcc47

.if !defined(GCC47_BUILDLINK3_MK)
GCC47_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc47+=	gcc47>=4.7
BUILDLINK_ABI_DEPENDS.gcc47+=	gcc47>=4.7.0
BUILDLINK_PKGSRCDIR.gcc47=	../../lang/gcc47
BUILDLINK_DEPMETHOD.gcc47?=	build

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc47=gcc47
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc47}/gcc47

BUILDLINK_FILES.gcc47=		#empty
BUILDLINK_AUTO_VARS.gcc47=	no

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB) && empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
DEPENDS+=	{gcc47,gcc47-libs}>=4.7:../../lang/gcc47-libs
ABI_DEPENDS+=	{gcc47,gcc47-libs}>=4.7.0:../../lang/gcc47-libs
.endif

pkgbase := gcc47
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc47:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC47_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc47
