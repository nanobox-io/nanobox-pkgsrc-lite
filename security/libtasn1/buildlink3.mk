# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:20 joerg Exp $

BUILDLINK_TREE+=	libtasn1

.if !defined(LIBTASN1_BUILDLINK3_MK)
LIBTASN1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=0.2.7
BUILDLINK_ABI_DEPENDS.libtasn1+=	libtasn1>=0.3.0
BUILDLINK_PKGSRCDIR.libtasn1?=	../../security/libtasn1
.endif # LIBTASN1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtasn1
