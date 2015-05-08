$NetBSD$

Turn off confirmation prompt to install new database, we always want it.

--- pkgindb.c.orig	2015-03-08 17:49:37.000000000 +0000
+++ pkgindb.c
@@ -165,9 +165,11 @@ upgrade_database()
 		 * COMPAT_CHECK query leads to an error for an
 		 * incompatible database
 		 */
+#if 0
 		printf(MSG_DATABASE_NOT_COMPAT);
 		if (!check_yesno(DEFAULT_YES))
 			exit(EXIT_FAILURE);
+#endif
 
 		pkgindb_reset();
 
