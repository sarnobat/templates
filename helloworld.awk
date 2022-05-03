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
}
# Heading
/^=+ /    {

}
# datestamp
/^2[0-9]{3}-[0-9]{2}(-[0-9]{2})?$/    {
}
END {
}