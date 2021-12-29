  set n 0
  while {$n<3000} {
    gets stdin row
    puts $row
    if { [string equal $row "."] } { break };
    append message $row "\n"
  }
  puts "---------"
  puts $message