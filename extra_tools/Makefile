# relink :)
all:
	gcc spawn_process_pid.c -o spawn_process_pid -static
	gcc spawn_process_pid2.c -o spawn_process_pid2 -static
	# gcc read_sudo_token.c -o read_sudo_token -static
	# gcc read_sudo_token_forensic.c -o read_sudo_token_forensic -static
	gcc write_sudo_token.c -o write_sudo_token -static
	gcc parse_process_stat.c -o parse_process_stat -static
	gcc activate_sudo_token.c -o activate_sudo_token -Wno-overflow -static
	gcc take_dev.c -o take_dev -Wno-overflow -static
	cp activate_sudo_token ../

clean:
	rm -rf spawn_process_pid read_sudo_token write_sudo_token parse_process_stat activate_sudo_token read_sudo_token_forensic
