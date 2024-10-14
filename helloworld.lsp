;; Example
;;
;;		find | sbcl --script helloworld.lsp

(defun valid-file-path-p (path)
	(probe-file (make-pathname :name path)))

(loop for line = (read-line) while line do 
  (if (valid-file-path-p line)
      (print (concatenate 'string "[file] " line))
      (print (concatenate 'string "[not file] " line)))
)