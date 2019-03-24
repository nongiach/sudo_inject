# relink :)
all:
	gcc spawn_process_pid.c -o spawn_process_pid
	gcc read_sudo_token.c -o read_sudo_token
	gcc read_sudo_token_forensic.c -o read_sudo_token_forensic
	gcc write_sudo_token.c -o write_sudo_token
	gcc parse_process_stat.c -o parse_process_stat
	gcc activate_sudo_token.c -o activate_sudo_token -Wno-overflow
	cp activate_sudo_token ../

clean:
	rm -rf spawn_process_pid read_sudo_token write_sudo_token parse_process_stat activate_sudo_token read_sudo_token_forensic
