#-----------------------------------------------------------------------------------------
#
# Usage
#
#   cat /tmp/in.mwk | awk -f ~/bin/awk_template.awk   | tee /tmp/out.mwk
#
# Date
#   2019-01-17
#
#-----------------------------------------------------------------------------------------

# backreferences don't exist. gsub is probably the next best thing
# there are no boolean variables, you must use strings

BEGIN {
	FS="(	| )+"
}
# Heading
/^=+ /    {

}
# Not Heading
$0 !~/^=== / {
}
# datestamp
/^2[0-9]{3}-[0-9]{2}(-[0-9]{2})?$/    {

	firstNchars = substr($0, 0, 20)

	# regex substitution (in-place)
	gsub(/ /,"_", firstNchars)

	# Execute shell command
	"date '+%Y-%m-%d'" | getline datestamp

	print datestamp"_"firstNchars".mwk"
	
	# TODO: print padded
	line = sprintf( "Prefix:%-32s", "hi")
	print line
	
	printf "%-15s %-20s %s %s %s\n", $11, $4, $8, $9, $6
	
	# TODO: add to associative array
}
// {
	# use printf if you don't want a newline
	print "[unmodified] " $0
}
END {
	# TODO: print all element pairs of associative array
}

