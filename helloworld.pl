# epoch to YYYY-MM-DD
# date +'%s' | perl -MTime::Piece -pe 's/(\d+)/Time::Piece->localtime($1)->strftime("%Y-%m-%d")/e'