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
- `dup2` - Copies descriptor table entry oldfd to descriptor table entry newfd (If newfd was open, closes newfd before the copy)
- `execve`
- `exit`
- `fork` - Used to creat a seperate, duplicate process.
- `pipe` - Pipes are used when you want to communicate between two precesses. Ex. A single program that wants to create a new process and communicate with the child process.
- `unlink`
- `wait`
- `waitpid`
- libft is allowed

## TODO

- [ ] Do this the last before submit work - Change back `CFLAGS = -Wall`
- [x] Handle arguents error. if (argc != 5) -> error.
- [ ] Rewrite split without memory leaks
