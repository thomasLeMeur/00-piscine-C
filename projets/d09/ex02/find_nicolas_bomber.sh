cat annuaire | grep -i -e "^nicolas\tbomber" -e "^bomber\tnicolas" | cut -d $'\t' -f 3 | grep -v ' '
