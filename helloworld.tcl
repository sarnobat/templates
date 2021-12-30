# set f [open stdin]
while {[gets stdin line] >= 0} {
	if { [file exists "/tmp"] } {
		puts "$line exists"
	} else {
		# This loops over every line
		puts ">>$line<<"
    }
}
close $f

#   while {[gets stdin line] >= 0} {
# 	  puts $line
#   }

#   set n 0
#   while {$n<30} {
#     gets stdin row
#     puts $row
# #     if { [file exists "input.txt"] } {
# # 		puts "input.txt exists"
# # 	} 
# #     if { [string equal $row "."] } { break };
# #     append message $row "\n"
#   }
#   puts "---------"
# #   puts $message