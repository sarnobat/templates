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

## TODO: show examples of these:
##
## next
##
# 	/(name)=(.*)/ {
# 	  name = $2  # Capture everything after "name="
# 	  print "Hello,", name
# 	}
# 	
# 	/name/ && /active/ { print $0 }  # Matches lines containing "name" and "active"
# 	/^(red|blue|green)/ { print $0 }  # Matches lines starting with "red", "blue", or "green"
# 	!/^error/ { print $0 }  # Matches lines that don't start with "error"
# 	/(name)=(.*)/ { print "Name:", $2 }  # Captures everything after "name=" in $2
# 	/color(..)/ { print "Found color code:", $2 }  # Captures two characters after "color"
# 	# Match lines where the second field is a number greater than 10
# 	/$2 > 10/ { print $0 }
# 	# Match lines where the third field exactly matches the string "active"
# 	/$3 == "active"/ { print $0 }

BEGIN {
	FS="(	| )+"
}
# Heading
$0  ~ /^=+ /    {

}
# Not Heading
$0 !~/^=== / {
}
# datestamp
/^2[0-9]{3}-[0-9]{2}(-[0-9]{2})?$/    {

	# command line argument
	for (i = 0; i < ARGC; i++) {
		print ARGV[i]
	}

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

