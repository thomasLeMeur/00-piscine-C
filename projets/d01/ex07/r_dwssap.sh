cat /etc/passwd | grep -v "^#" | sed "1d;n;d" | cut -d : -f 1 | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr "\n" "," | sed "s/,$/./" | tr -d "\n" | sed 1d
