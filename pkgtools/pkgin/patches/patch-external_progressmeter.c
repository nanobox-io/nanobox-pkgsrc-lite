$NetBSD$

--- external/progressmeter.c.orig	2015-03-08 17:49:37.000000000 +0000
+++ external/progressmeter.c
@@ -236,9 +236,10 @@ refresh_progress_meter(void)
 			strlcat(buf, "    ", win_size);
 	}
 
-	write(STDOUT_FILENO, buf, win_size - 1);
-	last_update = now;
-	last_pos = cur_pos;
+        if(write(STDOUT_FILENO, buf, win_size - 1)) {
+            last_update = now;
+            last_pos = cur_pos;
+        }
 }
 
 /*ARGSUSED*/
@@ -293,7 +294,8 @@ stop_progress_meter(void)
 	if (cur_pos != end_pos)
 		refresh_progress_meter();
 
-	write(STDOUT_FILENO, "\n", 1);
+	if(write(STDOUT_FILENO, "\n", 1))
+		return;
 }
 
 /*ARGSUSED*/
