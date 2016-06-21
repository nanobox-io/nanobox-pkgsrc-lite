$NetBSD: patch-camlibs_jl2005c_jpeg__memsrcdest.h,v 1.1 2016/02/04 11:57:50 wiz Exp $

Fix build with jpeg-9b.

--- camlibs/jl2005c/jpeg_memsrcdest.h.orig	2012-12-13 08:49:29.000000000 +0000
+++ camlibs/jl2005c/jpeg_memsrcdest.h
@@ -1,9 +1 @@
 #include <jpeglib.h>
-
-void
-jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * buffer,
-	unsigned long bufsize);
-
-void
-jpeg_mem_dest (j_compress_ptr cinfo, unsigned char ** outbuffer,
-	unsigned long * outsize);
