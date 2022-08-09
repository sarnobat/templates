# On wish, we get an exception. On tclsh we don't.

set fh [open $filename]
while {[gets $fh line] != -1} {
    # process $line
}
close $fh

while {[gets stdin line] >= 0} {
	if { [file exists "$line"] } {
		puts "$line exists"
	} else {
		puts ">>$line<<"
    }
}

