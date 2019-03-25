parse_process_stat: parse /proc/[pid]/stat

Usage: ./parse_process_stat [pid]

Everything is parsed but only starttime is printed.

Example:
```sh
./parse_process_stat 4242
/proc/4242/stat.starttime => 193691
```

read_sudo_token: parse /var/run/sudo/ts/[username]

Usage: ./read_sudo_token < /var/run/sudo/ts/[username]

parse all sudo token

Example:

`sh
# ./read_sudo_token < /var/run/sudo/ts/test
===================version = 2
size 56
type 4
flags 0
auth_uid 0
sid 0
pid start_time 0 sec 0 nsec
ts 0 sec 0 nsec
ttydev 0
ppid 0
===================version = 2
size 56
type TS_PPID
flags 0
auth_uid 1001
sid 4242
pid start_time 986 sec 440000000 nsec
ts 996 sec 210870326 nsec
ttydev 4242
ppid 4242
`

spawn_process_pid: spawn a shell that has a given pid

Usage: ./spawn_process_pid [pid]

Example:

`sh
bash$ ./spawn_process_pid 12345
sh$ echo $$
12345
`


https://github.com/ThomasHabets/injcode

https://blog.nelhage.com/2011/02/changing-ctty/
https://blog.habets.se/2009/03/Moving-a-process-to-another-terminal.html
