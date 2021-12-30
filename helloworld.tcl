# On wish, we get an exception. On tclsh we don't.
while {[gets stdin line] >= 0} {
	if { [file exists "$line"] } {
		puts "$line exists"
	} else {
		puts ">>$line<<"
    }
}