# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <fcntl.h>
# include <errno.h>
# include "../include/so_long.h"
# include "../include/colors.h"


void	mock_error_stderr_fileno(char *msg)
{
	if (msg)
	{
		ft_putstr_fd("error", STDERR_FILENO);
	}
	if (errno)
	{
		ft_putstr_fd("Error:\n", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	//exit (EXIT_FAILURE);
}

void	mock_strlen_strcmp_error(char *msg, FILE *stream)
{
    int fd = fileno(stream);
	ft_putstr_fd(RED, fd);
	if (msg)
	{
		ft_putstr_fd("Error:\n", fd);
		ft_putstr_fd(msg, fd);
		ft_putchar_fd('\n', fd);
	}
	if (errno)
	{
		ft_putstr_fd("Error:\n", fd);
		ft_putstr_fd(strerror(errno), fd);
		ft_putchar_fd('\n', fd);
	}
	ft_putstr_fd(NORMAL, fd);
    //exit (EXIT_FAILURE);

}

int test_print(const char *msg, const char *expected_output)
{
    FILE *tmp = tmpfile();

    mock_strlen_strcmp_error((char *)msg, tmp);
    const int tmp_length = ftell(tmp);
    rewind(tmp);

    char buffer[1024];
    fread(buffer, 1, sizeof(buffer) - 1, tmp);
    buffer[tmp_length] = '\0';
    //fgets(buffer, tmp_length + 1, tmp); // if just one line
    fclose(tmp);

    //printf("buffer: %s.\n", buffer);
    // printf("expected_output: %s.\n", expected_output);
    // printf("tmp_length: %d.\n", tmp_length);
    // printf("ft_strlen(expected_output): %d.\n", (int) ft_strlen(expected_output));

    return (strcmp(buffer, expected_output) == 0 && tmp_length == (int) ft_strlen(expected_output));
}

int test_output_stderr(char *msg, char *expected_output)
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return 1;
    }

    // Save the real stderr
    int saved_stderr = dup(STDERR_FILENO);
    if (saved_stderr == -1)
    {
        perror("dup");
        return 1;
    }

    // Redirect STDERR to pipefd[1]
    if (dup2(pipefd[1], STDERR_FILENO) == -1)
    {
        perror("dup2");
        return 1;
    }

    close(pipefd[1]); // No longer need this in this process
                      // because STDERR is now pipefd[1]

    mock_error_stderr_fileno(msg);

    // Restore real stderr
    dup2(saved_stderr, STDERR_FILENO);
    close(saved_stderr);

    // Now read whatever was written to the pipe
    char buffer[1024];
    ssize_t n = read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);

    if (n > 0)
    {
        buffer[n] = '\0';
        // printf("Captured from STDERR: %s\n", buffer);
        return (strcmp(buffer, expected_output) == 0);
    }

    return 0;
}
void test_error_ok(void)
{
    assert(test_print("whatever", "\x1B[31mError:\nwhatever\n\x1B[0m") == 1);
    assert(test_output_stderr("whatever", "error") == 1);
}

int main(void)
{
    test_error_ok();
}