// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "utils/utils.h"

#ifdef BUFSIZ
#undef BUFSIZ
#endif

#define BUFSIZ			1024

#define READ_FILE_NAME		"read_file.txt"
#define WRITE_FILE_NAME		"write_file.txt"

static int open_file_for_reading(const char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	DIE(fd < 0, "open");

	printf("Opened file descriptor is for reading: %d\n", fd);

	return fd;
}

static void read_from_file(char *buff, int fd, int bytes_to_read)
{
	int bytes_read;
	int total_read = 0;

	/**
	 * ALWAYS use `read()` in a loop because it might not read all the
	 * required bytes.
	 */
	while (total_read < bytes_to_read) {
		/**
		 * `total_read` bytes have been read so far
		 * `buff + total_read` is the address of the first byte to be
		 *	read
		 * `bytes_to_read - total_read` bytes need to be read
		 */
		bytes_read = read(fd, buff + total_read,
			bytes_to_read - total_read);
		DIE(bytes_read < 0, "read");

		/* 0 indicates the end of the file. */
		if (!bytes_read)
			break;

		total_read += bytes_read;
	}

	printf("Read %d bytes from file descriptor %d:\n%s", total_read,
		fd, buff);
}

static int open_file_for_writing(const char *file_name)
{
	int fd = 0;

	/**
	 * TODO 1: Open the file for writing. Remember to use `DIE()` to check
	 * for errors.
	 */
	fd= open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	DIE(fd==-1,"open");
	printf("Opened file descriptor is for writing: %d\n", fd);

	return fd;
}

static void write_to_file(char *buff, int fd, int bytes_to_write)
{
	int bytes_written;
	int total_written = 0;

	/**
	 * TODO 2: Write the buffer to the file descriptor.
	 * ALWAYS use `write()` in a loop because it might not read all the
	 * required bytes.
	 */
	while(total_written<bytes_to_write)
	{
		bytes_written=write(fd,buff+total_written,bytes_to_write-total_written);
		DIE(bytes_written< 0, "write");

		if (!bytes_written)
			break;

		total_written+=bytes_written;
	}
	printf("Wrote %d bytes to file descriptor %d\n", total_written,
		fd);
}

int main(void)
{
	int fd_read;
	int fd_write;
	char buff[BUFSIZ] = { 0 };
	char message[] = "Message for file2.txt: What's up, Doc?\n";

	fd_read = open_file_for_reading(READ_FILE_NAME);
	read_from_file(buff, fd_read, sizeof(buff));

	fd_write = open_file_for_writing(WRITE_FILE_NAME);
	write_to_file(message, fd_write, strlen(message));

	/**
	 * TODO 3: Write to `READ_FILE_NAME` and then read the newly written
	 * data. Use the functions defined above.
	 */
	int fd_write2= open_file_for_writing(READ_FILE_NAME);
	char message2[]="Sunt in fata pe avarii.\n";
	int fd_read2=open_file_for_reading(READ_FILE_NAME);
	char buff2[BUFSIZ] = { 0 };
	write_to_file(message2, fd_write2, strlen(message2));
	read_from_file(buff2,fd_read2,sizeof(buff2));
	/* TODO 4: `close()` the file `open()`-ed descriptors. */
	close(fd_read2);
	close(fd_write2);
	close(fd_read);
	close(fd_write);
	return 0;
}
