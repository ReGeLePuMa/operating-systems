#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils.h"

int main(void)
{
	pid_t ret_pid,ret_pid2;
	pid_t pid,pid2;
	int status,status2;

	pid = fork();
	switch (pid) {
	case -1:
	{
		/* `fork()` has encountered an error. */
		DIE(1, "fork");
		break;
	}
	case 0:
	{
		/* Child process */
		printf("[child 1] current PID = %d; parent PID = %d\n",
			getpid(), getppid());

		/**
		 * TODO 2: Create another child process here and print its PID
		 * and PPID.
		 */
		pid2=fork();
		switch(pid2)
		{
			case -1:
			{
				/* `fork()` has encountered an error. */
				DIE(1, "fork");
				break;
			}
			case 0:
			{
				/* Child process */
				printf("[child 2] current PID = %d; parent PID = %d\n",
					getpid(), getppid());
				return 122;	
			}
			default:
			{
			/* Parent process */
				printf("[parent] child PID = %d; current PID = %d\n", pid,
					getpid());

				ret_pid2 = waitpid(pid2, &status2, 0);
				DIE(ret_pid2 < 0, "waitpid parent");

				if (WIFEXITED(status2))
					printf("[parent] Child process exited with status %d\n",
						WEXITSTATUS(status2));
				break;
			}
		}
		/**
		 * TODO 1: Return a different value from the child and see
		 * `status` change in the parent.
		 * 
		 */
			return 121;
		break;
	}

		
	default:
	{
		/* Parent process */
		printf("[parent] child PID = %d; current PID = %d\n", pid,
			getpid());

		ret_pid = waitpid(pid, &status, 0);
		DIE(ret_pid < 0, "waitpid parent");

		if (WIFEXITED(status))
			printf("[parent] Child process exited with status %d\n",
				WEXITSTATUS(status));
		break;
	}
		
}

	return 0;
}
