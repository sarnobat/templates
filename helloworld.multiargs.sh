# The Bourne shell or the POSIX sh language specification don't support arrays. 
# Or rather they have only one array: the positional parameters ($1, $2, $@, 
# so one array per function as well).
# https://unix.stackexchange.com/questions/137566/arrays-in-unix-bourne-shell
ARGS="$@"

ARGS_TXT=`mktemp`
trap 'echo dirty end (local) $ARGS_TXT' SIGINT
trap 'echo dirty end (pipe)  $ARGS_TXT' SIGPIPE

# args are space-delimited
for VALUE in $ARGS; do
	echo $VALUE >> $ARGS_TXT
done

# stdin is newline-delimited
cat /dev/stdin | cat - $ARGS_TXT  | while read line ; do
	echo $line
done
echo "clean end: $ARGS_TXT"
