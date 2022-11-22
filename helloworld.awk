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
	
	# TODO: add to associative array
}
END {
	# TODO: print all element pairs of associative array
}

