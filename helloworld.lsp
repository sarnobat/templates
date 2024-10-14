;; Example
;;
;;		find | sbcl --script helloworld.lsp

(defun valid-file-path-p (path)
	(probe-file (make-pathname :name path)))

(defun last-part-of-path (path)
  (let ((pathname (pathname path)))
    (if (directory-pathname-p pathname)
        (last (directory pathname))
        (last (pathname-name pathname)))))

(defun greet-user (name)
  (return-from greet-user (format nil "Hello, ~A!" name)))


(loop for line = (read-line) while line do 
	 (if 	(valid-file-path-p line)
			(progn 
				(print (concatenate 'string "[file path] " 	line))
				(print (concatenate 'string "[file name] " (greet-user line))))
      		(print (concatenate 'string "[not file] " line))))