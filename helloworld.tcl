# On wish, we get an exception. On tclsh we don't.

# set fh [open $filename]
# while {[gets $fh line] != -1} {
#     # process $line
# }
# close $fh

while {[gets stdin line] >= 0} {
	if { [file isdirectory "$line"] } {
# 		puts "\[dir\] $line"
		puts [format "%-10s %s" "\[dir\]" $line]
	} elseif { [file exists "$line"] } {
		puts [format "%-10s %s" "\[file\]" $line]
    } else {
		puts ">>$line<<"
    }
}

