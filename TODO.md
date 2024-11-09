# Pipex Note

## Requirement

- It must take 4 arguments and will be execute as follows:
`./pipex file1 cmd1 cmd2 file2` and it should behave like this `< infile grep a1 | wc -w > outfile`

### Allow Function

- `open`
- `close`
- `read`
- `write`
- `malloc`
- `free`
- `perror`
- `strerror`
- `access`
- `dup`
- `dup2`
- `execve`
- `exit`
- `fork`
- `pipe`
- `unlink`
- `wait`
- `waitpid`
- libft is allowed

## TODO

- Handle arguents error.
- Rewrite split without memory leaks
