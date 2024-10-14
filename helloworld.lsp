;; Example
;;
;;		find | sbcl --script helloworld.lsp


(loop for line = (read-line) while line do (print line))
