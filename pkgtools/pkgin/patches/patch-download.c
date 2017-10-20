$NetBSD$

--- download.c.orig	2016-02-08 16:27:12.000000000 +0000
+++ download.c
@@ -159,6 +159,28 @@ sum_close(struct archive *a, void *data)
 	return ARCHIVE_OK;
 }
 
+void
+fix_url(char *in, char *out)
+{
+	char *in_p = in;
+	char *out_p = out;
+	while (*in_p) {
+		switch (*in_p) {
+			case '+':
+				in_p++;
+				*out_p++ = '%';
+				*out_p++ = '2';
+				*out_p++ = 'B';
+				break;
+			default:
+				*out_p++ = *in_p++;
+				break;
+		}
+	}
+	*out_p = '\0';
+	return;
+}
+
 /*
  * Download a package to the local cache.
  */
@@ -173,8 +195,11 @@ download_pkg(char *pkg_url, FILE *fp)
 	fetchIO *f = NULL;
 	char buf[4096];
 	char *pkg, *ptr;
+	char fixed_pkg_url[BUFSIZ];
+	
+	fix_url(pkg_url, fixed_pkg_url);
 
-	if ((url = fetchParseURL(pkg_url)) == NULL)
+	if ((url = fetchParseURL(fixed_pkg_url)) == NULL)
 		errx(EXIT_FAILURE, "%s: parse failure", pkg_url);
 
 	if ((f = fetchXGet(url, &st, "")) == NULL)
