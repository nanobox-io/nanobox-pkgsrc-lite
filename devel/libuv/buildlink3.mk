# $NetBSD: buildlink3.mk,v 1.35 2013/04/06 11:06:52 rodent Exp $

BUILDLINK_TREE+=  libuv

.if !defined(LIBUV_BUILDLINK3_MK)
LIBUV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuv+= libuv>=20130301
BUILDLINK_PKGSRCDIR.libuv?= ../../devel/libuv

.endif # LIBUV_BUILDLINK3_MK

BUILDLINK_TREE+=  -libuv

