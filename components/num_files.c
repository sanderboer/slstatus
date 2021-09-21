/* See LICENSE file for copyright and license details. */
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "../util.h"
#if defined(__FreeBSD__)
#define PATH_MAX 256
#endif
int
num_files_i(const char *path)
{
	struct dirent *dp;
	DIR *fd;
	int num;

	if (!(fd = opendir(path))) {
		warn("opendir '%s':", path);
		return 0;
	}

	num = 0;
	while ((dp = readdir(fd))) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) {
			continue; /* skip self and parent */
		}
		num++;
	}

	closedir(fd);
        return num;
}

const char *
num_files(const char *path)
{
  int num = num_files_i(path);
  return bprintf("%d", num);
}

const char * maildir_mail(const char *path)
{
  char cur_path[PATH_MAX];
  char new_path[PATH_MAX];
  strcpy(cur_path, path);
  strcat(cur_path, "/INBOX/cur");
  strcpy(new_path, path);
  strcat(new_path, "/INBOX/new");
  int cur = num_files_i(cur_path);
  int new = num_files_i(new_path);
  char* map[]={"",""};
  int read = 0;
  if ( new > 0 ) read = 1;

  return bprintf("%s %i/%i", map[read],new,cur);
}
