
# BORN 2 BE ROOT


## Kdump

## SELinux

## AppArmor

## LVM

## SSH
### Port 4242
https://wiki.debian.org/SSH
`apt install openssh-server`
The main configuration files are in the directory /etc/ssh :
ssh_config : client configuration file
sshd_config : server configuration file

## UFW FIREWALL
### Port 4242
https://www.linux.com/training-tutorials/introduction-uncomplicated-firewall-ufw/
`sudo ufw allow ssh
 sudo ufw limit 4242`

## Hostname
`sudo hostnamectl set-hostname linuxconfig`
`/etc/hosts ->
	127.0.0.1 localhost
	127.0.1.1 <CHANGE NAME>`


## Password 30 day expiration
https://www.cyberciti.biz/faq/linux-howto-check-user-password-expiration-date-and-time/

password is valid for 90 days for user named jerry:
`sudo chage -M 90 jerry
 sudo chage -l jerry`

set the minimum number of days between password changes:
`sudo chage -m 30 user`

## STRONG PASSWORD
https://www.unixmen.com/generate-check-strong-passwords-linux/

## CHANGE ROOT PASSWORD
`sudo passwd root`
`sudo passwd user`

## LIMIT 3 SUDO TRY
https://askubuntu.com/questions/338588/limit-user-login-attempts-ubuntu-12-10-pam-tally-so-pam-tally2-so
