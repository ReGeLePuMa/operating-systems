#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "utils/utils.h"

static void wait_for_input(const char *msg)
{
	char buf[32];

	printf(" * %s\n", msg);
	printf(" -- Press ENTER to continue ...");
	fflush(stdout);
	fgets(buf, 32, stdin);
}

int main(int argc, char *argv[])
{
	int fdin;
	int fdout;
	char *src;
	char *dst;
	struct stat statbuf;

	DIE(argc != 3, "Usage: ./mmap_cp <from_file> <to_file>");

	/* TODO: Open the input file. */
	fdin=open(argv[1],O_RDONLY);
	/* TODO: Open/create the output file. */
	fdout=open(argv[2],O_RDWR|O_CREAT|O_APPEND,0644);
	/**
	 * TODO: Truncate the output file to the input file size. Use `fstat()`
	 * to get the size of the input file and `ftruncate()` to set the size
	 * of the output file.
	 */
	fstat(fdin,&statbuf);
	ftruncate(fdout,statbuf.st_size);
	/* TODO: `mmap()` the input file. */
	src=mmap(NULL,statbuf.st_size,PROT_READ,MAP_SHARED,fdin,0);
	/* wait_for_input("Mapped input file."); */
	wait_for_input("Astept input");
	/* TODO: `mmap()` the output file. */
	dst=mmap(NULL,statbuf.st_size,PROT_WRITE|PROT_READ,MAP_SHARED,fdout,0);
	/* wait_for_input("Mapped output file."); */
	wait_for_input("Astept input");
	/**
	 * TODO: Copy the contents of the input mapping to the output mapping.
	 */
	memmove(dst,src,statbuf.st_size);
	/* TODO: Clean up. Use `munmap()` to unmap the 2 files. */
	munmap(src,statbuf.st_size);
	munmap(dst,statbuf.st_size);
	close(fdin);
	close(fdout);
	return 0;
}
