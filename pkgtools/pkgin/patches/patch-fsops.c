$NetBSD$

--- fsops.c.orig	2015-03-08 17:49:37.000000000 +0000
+++ fsops.c
@@ -125,7 +125,8 @@ read_repos()
 	while (!feof(fp)) {
 		memset(buf, 0, BUFSIZ);
 
-		(void)fgets(buf, BUFSIZ, fp);
+		if (!fgets(buf, BUFSIZ, fp))
+			continue;
 
 		if (strncmp(buf, "ftp://", 6) != 0 &&
 			strncmp(buf, "http://", 7) != 0 &&
