###
### Example
###
###     find  | head -6 | sh helloworld.sh

while getopts ":ht" opt; do
  case ${opt} in
    h ) # process option h
      ;;
    t ) # process option t
      ;;
    \? ) echo "Usage: cmd [-h] [-t]"
      ;;
  esac
done

while read line ; do
  
	if [[ $line =~ ^\/[a-zA-Z0-9]* ]]; then
		echo "(is absolute, removing CWD)" >&2
		line_after=${line#$PWD}
		echo "$line_after"
	else
		echo "(is relative, adding CWD)" >&2
		# double slash for to replace all occurrences
		echo "$PWD/$line_after"
	fi

	basename $line
	dirname $line

	# 	line_after=${line//o/PREFIX}
	# Looks like ^ isn't supported in variable expansion

  
done < "${1:-/dev/stdin}"


### 7) convert epoch to date and vv
epoch=`date +%s --date "2022-01-01" `
date_iso=`date --iso-8601 --date @1641024000`
current_date=`date`

### 8) concurrent
echo "this is concurrent code" &

### 9) add padding after string
find | head | xargs -n 1 printf "column 1 %-50s%scolumn 2\n"

### 10) write to file
find | tee /tmp/out.log

### 11) web scrape
curl 'https://www.google.com' | lynx  -stdin -image_links  -dump

### 2D plot
seq 1 1000| shuf | xargs -n 2 | sort -n | tee /tmp/hello.dat
gnuplot -e "set terminal dumb; plot '/tmp/hello.dat'"

